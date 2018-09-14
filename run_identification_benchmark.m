%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%    BENCHMARK FOR ROBOT DYNAMIC PARAMETER IDENTIFICATION METHODS     %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Authors: Julien Roux, Quentin Leboutet, Alexandre Janot

clear all
close all

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Recompile the mex files:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Automatically add the Benchmark folder and its subfolders to the path:
addpath('Benchmark');
addpath(genpath('Benchmark'));

if isunix
    disp('Linux detected. Benchmark can be executed...')
    
    if license('test','distrib_computing_toolbox')==0 % If the parallel computing toolbox is not detected on the machine
        disp('The distributed computing toolbox was not detected. Expect slower computations for the CLOE, UKF and SRUKF...')
    end
    
    if license('test','matlab_coder')==0 % If the matlab coder is not detected
        disp('The matlab coder toolbox was not detected. Switching to pure matlab computations (no mex).')
        codeImplementation = 'classic';
    else
        disp('The matlab coder toolbox was detected.')
        disp('Using mex files will increase the execution speed.')
        prompt1 = 'Do you want to use mex files ? Y/N [Y]';
        flag1=false;
        flag2=false;
        while flag1==false
            decitionMex = input(prompt1,'s');
            if isempty(decitionMex)
                decitionMex = 'Y';
            end
            if strcmp(decitionMex, 'Y')
                flag1=true;
                versionMatlab = ver('matlab');
                if strcmp(versionMatlab.Release,'(R2018a)') % Same matlab version than the one used for the initial mex compilation
                    disp('Your matlab version is compatible with the provided mex files. Launching parameter identification without recompiling...')
                    codeImplementation = 'optim';
                else
                    fprintf("You are using Matlab %s \n", versionMatlab.Release) ;
                    disp('This benchmark was originally compiled for Linux with matlab R2018a. If you want to use mex files, it will be necessary to recompile them.');
                    prompt2 = 'Do you want to recompile mex files ? Y/N [Y]';
                    
                    while flag2==false
                        decisionCompilation = input(prompt2,'s');
                        if isempty(decisionCompilation)
                            decisionCompilation = 'Y';
                        end
                        if strcmp(decisionCompilation, 'Y')
                            flag2=true;
                            % [torqueVector_mex observationMatrix_mex integrate_RRR_dyn_CL_mex ekf_opt_mex ukf_opt_mex srukf_opt_mex]
                            list = [1 1 1 1 1 1];
                            compileTime = recompileMex(list);
                            codeImplementation = 'optim';
                        elseif strcmp(decisionCompilation, 'N')
                            flag2=true;
                            disp('Switching to pure matlab computations (no mex).')
                            codeImplementation = 'classic';
                        else
                            disp('Incorrect input !')
                            flag2=false;
                        end
                    end
                end
            elseif strcmp(decitionMex, 'N')
                flag1=true;
                disp('Switching to pure matlab computations (no mex).')
                codeImplementation = 'classic';
            else
                disp('Incorrect input !')
                flag1=false; % looping
            end
        end
    end
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Benchmark initialization:
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % Load robot experiment data:run
    
    load('RRR_traj_5.mat')
    
    % Select the identification methods :
    
    % 1 -> method used, 0 -> method not used
    % [LS, LS_f, LS_fBW, DIDIM, CLOE_Q, CLOE_Qp, EKF, UKF, SRUKF]
    % The benchmark will only produce results for methods with 1
    
    identificationMethods = [1 1 1 1 1 1 1 1 1];
    
    % Important parameters:
    displayProgression = true;
    
    if displayProgression == true
        progressBar = waitbar(0,'Benchmark initialization', 'name', 'Progress of the parametric identification sub-process');
    end
    
    N_t = 10;   % Number of trials for each method and each initial point
    N_i = 10;   % Number of different initial points
    N = 10000;  % Number of samples
    
    % Identify the robot using a subset of the experiment trajectory [t_i, t_f]:
    t_i = 0;            % Start time
    t_f = 10;           % End time
    dt = (t_f-t_i)/N;   % Sampling time
    f =1/dt;            % Sampling frequency
    
    % Decimate parameters
    fnyq = f/2;         % Nyquist frequency
    freq_decim = 20;    % Final number of samples = N/freq_decim
    ndecim = round(0.8*fnyq/(freq_decim));
    ndecim = 1;
    
    % Generate a set of N_i initial parameter estimates:
    
    [Xhi_obj, Theta_obj, Initial_pts] = generateInitParamEst(N_i);
    
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Inverse Dynamic Identification Model and Least Square (IDIM-LS):
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(1)==1 % LS
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting IDIM-LS    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('IDIM-LS: First Iteration...'));
        end
        results_LS.N_t = N_t;
        results_LS.N_i = N_i;
        results_LS.t_i = t_i;
        results_LS.t_f = t_f;
        results_LS.N = N;
        results_LS.Theta_obj = Theta_obj;
        results_LS.Xhi_obj = Xhi_obj;
        results_LS.Initial_points = Initial_pts;
        results_LS.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_LS.eps = zeros(N_i, N_t);
        results_LS.times = zeros(N_i, N_t);
        
        % Options:
        optionsIDIM_LS.solver='backslash'; % [backslash]: use the matlab optimized function (x=A\b), [pinv]: use the matlab pseudoinverse function
        optionsIDIM_LS.implementation=codeImplementation; % [classic]: do not use mex functions (very slow), [optim]: use mex functions (faster)
        optionsIDIM_LS.ndecim = ndecim; % Decimation parameter
        optionsIDIM_LS.filter = 'no'; % [no]: no filter, [lowpass]: low pass filter, [butterworth]: zero-shift butterworth filter
        
        for i = 1:N_i % For each set of initial parameters
            for j = 1:N_t % For each trajectory noise
                tic
                data_struct = Data(j);
                [Theta_LS, ~, ~, ~] =  IDIM_LS_identification(data_struct, optionsIDIM_LS);
                results_LS.times(i, j)=toc;
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('IDIM-LS: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_LS.Thetas(i,j,:)=Theta_LS;
                results_LS.eps(i, j)=norm(Theta_LS-Theta_obj);
            end
        end
        save('Benchmark/Results/results_LS.mat', 'results_LS')
        clear 'Theta_LS';
        %     clear 'results_LS';
        clear 'optionsIDIM_LS';
        disp("%%%%%%%%%%%%%    Finished IDIM-LS    %%%%%%%%%%%%%")
    end % end LS
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Inverse Dynamic Identification Model and Least Square (IDIM-LS)+LP-Filter:
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(2)==1 % LS with filtered acceleration
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting IDIM-LS +LP-Filter    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('Low-Pass Filtered IDIM-LS: First Iteration...'));
        end
        results_LS_f.N_t = N_t;
        results_LS_f.N_i = N_i;
        results_LS_f.t_i = t_i;
        results_LS_f.t_f = t_f;
        results_LS_f.N = N;
        results_LS_f.Theta_obj = Theta_obj;
        results_LS_f.Xhi_obj = Xhi_obj;
        results_LS_f.Initial_points = Initial_pts;
        results_LS_f.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_LS_f.eps = zeros(N_i, N_t);
        results_LS_f.times = zeros(N_i, N_t);
        
        % Options:
        optionsIDIM_LS_f.solver='backslash'; % [backslash]: use the matlab optimized function (x=A\b), [pinv]: use the matlab pseudoinverse function
        optionsIDIM_LS_f.ndecim = ndecim; % Decimation parameter
        optionsIDIM_LS_f.implementation=codeImplementation; % [classic]: do not use mex functions (very slow), [optim]: use mex functions (faster)
        optionsIDIM_LS_f.filter = 'lowpass'; % [no]: no filter, [lowpass]: low pass filter, [butterworth]: zero-shift butterworth filter
        
        % design of the filter for the LS with filtered joint acceleration
        d = fdesign.lowpass('Fp,Fst,Ap,Ast', 100, 120, 0.01, 60, 1000);
        optionsIDIM_LS_f.Hd = design(d, 'equiripple');
        
        for i = 1:N_i % For each set of initial parameters
            for j = 1:N_t
                tic
                data_struct = Data(j);
                [Theta_LS_f, ~, ~, ~] =  IDIM_LS_identification(data_struct, optionsIDIM_LS_f);
                results_LS_f.times(i, j)=toc;
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('Low-Pass Filtered IDIM-LS: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_LS_f.Thetas(i,j,:)=Theta_LS_f;
                results_LS_f.eps(i, j)=norm(Theta_LS_f-Theta_obj);
            end
        end
        save('Benchmark/Results/results_LS_filtered.mat', 'results_LS_f')
        clear 'Theta_LS_f';
        %     clear 'results_LS_f';
        clear 'optionsIDIM_LS_f';
        disp("%%%%%%%%%%%%%    Finished IDIM-LS +LP-Filter    %%%%%%%%%%%%%")
    end % end LS_f
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Inverse Dynamic Identification Model and Least Square (IDIM-LS) with Zero-shift Butterworth filtered acceleration :
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(3)==1 % LS with 2-pass-Butterworth filtered acceleration
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting IDIM-LS + Zero-shift Butterworth Filter    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('Butterworth IDIM-LS: First Iteration...'));
        end
        results_LS_fBW.N_t = N_t;
        results_LS_fBW.N_i = N_i;
        results_LS_fBW.t_i = t_i;
        results_LS_fBW.t_f = t_f;
        results_LS_fBW.N = N;
        results_LS_fBW.Theta_obj = Theta_obj;
        results_LS_fBW.Xhi_obj = Xhi_obj;
        results_LS_fBW.Initial_points = Initial_pts;
        results_LS_fBW.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_LS_fBW.eps = zeros(N_i, N_t);
        results_LS_fBW.times = zeros(N_i, N_t);
        
        % Options:
        optionsIDIM_LS_fBW.solver='backslash'; % [backslash]: use the matlab optimized function (x=A\b), [pinv]: use the matlab pseudoinverse function
        optionsIDIM_LS_fBW.ndecim = ndecim; % Decimation parameter
        optionsIDIM_LS_fBW.implementation=codeImplementation; % [classic]: do not use mex functions (very slow), [optim]: use mex functions (faster)
        optionsIDIM_LS_fBW.filter = 'butterworth'; % [no]: no filter, [lowpass]: low pass filter, [butterworth]: zero-shift butterworth filter
        
        % Butterworth filter parameters:
        optionsIDIM_LS_fBW.freq_fil = 20.0;
        optionsIDIM_LS_fBW.fnyq = fnyq; % Nyquist frequency
        optionsIDIM_LS_fBW.nfilt = 4;
        optionsIDIM_LS_fBW.dt = dt;
        optionsIDIM_LS_fBW.border = 50; % Remove boarder effects, because of diffcent function
        
        for i = 1:N_i % For each set of initial parameters
            for j = 1:N_t
                tic
                data_struct = Data(j);
                [Theta_LS_fBW, ~, ~, ~] =  IDIM_LS_identification(data_struct, optionsIDIM_LS_fBW);
                results_LS_fBW.times(i, j)=toc;
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('Butterworth IDIM-LS: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_LS_fBW.Thetas(i,j,:)=Theta_LS_fBW;
                results_LS_fBW.eps(i, j)=norm(Theta_LS_fBW-Theta_obj);
            end
        end
        save('Benchmark/Results/results_LS_filtered_BW.mat', 'results_LS_fBW')
        clear 'Theta_LS_fBW';
        %     clear 'results_LS'_fBW;
        clear 'optionsIDIM_LS_fBW';
        disp("%%%%%%%%%%%%%    Finished IDIM-LS + Zero-shift Butterworth Filter    %%%%%%%%%%%%%")
    end % end LS_fBW
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Direct and Inverse Dynamic Identification Model (DIDIM):
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(4)==1 % DIDIM
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting DIDIM    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('DIDIM: First Iteration...'));
        end
        results_DIDIM.N_t = N_t;
        results_DIDIM.N_i = N_i;
        results_DIDIM.t_i = t_i;
        results_DIDIM.t_f = t_f;
        results_DIDIM.N = N;
        results_DIDIM.Max_it = 100;
        results_DIDIM.Theta_obj = Theta_obj;
        results_DIDIM.Xhi_obj = Xhi_obj;
        results_DIDIM.Initial_points = Initial_pts;
        results_DIDIM.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_DIDIM.flag = zeros(N_i, N_t);
        results_DIDIM.eps = zeros(N_i, N_t);
        results_DIDIM.times = zeros(N_i, N_t);
        results_DIDIM.iterations = zeros(N_i, N_t);
        results_DIDIM.Thetas_iteration = zeros(N_i, N_t, 17, results_DIDIM.Max_it+1);
        
        % Options:
        optionsDIDIM.debug = false;
        optionsDIDIM.ndecim = ndecim; % Decimation parameter
        optionsDIDIM.implementation=codeImplementation; % [classic]: do not use mex functions (very slow), [optim]: use mex functions (faster)
        optionsDIDIM.solver='backslash'; % [backslash]: use the matlab optimized inverse function (x=A\b), [pinv]: use the matlab pseudoinverse function, [quadprog]: use the matlab quadprog function,  [qpOASES]: uses the qpOASES C++ library
        
        % Stop criteria:
        stopCrit.Max_it = results_DIDIM.Max_it;
        stopCrit.tol_1 = 1e-8;
        stopCrit.tol_2 = 1e-8;
        
        for i = 1:N_i % For each set of initial parameters
            
            fprintf("DIDIM Initial parameter nb: %i\n",i);
            Theta_0 = Initial_pts(:,i)
            
            for j = 1:N_t % For each trajectory noise
                data_struct = Data(j);
                
                try
                    tic
                    [Theta_DIDIM, it_DIDIM, ~, ~, Thetas_DIDIM, flag_DIDIM] = DIDIM_identification(Theta_0, data_struct, stopCrit, optionsDIDIM);
                    results_DIDIM.times(i, j)=toc;
                catch
                    flag_DIDIM = -1;
                    Theta_DIDIM = zeros(17,1);
                    it_DIDIM = 0;
                    Thetas_DIDIM = zeros(17, results_DIDIM.Max_it+1);
                end
                
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('DIDIM: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_DIDIM.flag(i,j)=flag_DIDIM;
                results_DIDIM.Thetas(i,j,:)=Theta_DIDIM;
                results_DIDIM.eps(i, j)=norm(Theta_DIDIM-Theta_obj);
                results_DIDIM.iteration(i,j)=it_DIDIM;
                results_DIDIM.Thetas_iteration(i, j, :, :) = Thetas_DIDIM;
            end
        end
        save('Benchmark/Results/results_DIDIM.mat', 'results_DIDIM')
        clear 'Theta_DIDIM';
        clear 'it_DIDIM';
        clear 'Thetas_DIDIM';
        clear 'flag_DIDIM';
        %     clear 'resultsDIDIM';
        clear 'optionsDIDIM';
        clear 'stopCrit';
        disp("%%%%%%%%%%%%%    Finished DIDIM    %%%%%%%%%%%%%")
    end % end DIDIM
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Closed-Loop Output-Error (CLOE) with joint position input:
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(5)==1 % CLOE_Q
        
        disp("%%%%%%%%%%%%%    Starting CLOE-Q    %%%%%%%%%%%%%")
        
        optionsCLOE_Q.optimizer = 'lsqnonlin';
        %         optionsCLOE_Q.optimizer = 'simplex';
        optionsCLOE_Q.implementation = codeImplementation; % [classic]: do not use mex functions (very slow), [optim]: use mex functions (faster)
        
        switch optionsCLOE_Q.optimizer
            case 'simplex'
                
                % Initialization:
                
                if displayProgression == true
                    waitbar(0, progressBar, sprintf('CLOE-Q: First Iteration...'));
                end
                results_CLOE_Q.N_t = N_t;
                results_CLOE_Q.N_i = N_i;
                results_CLOE_Q.t_i = t_i;
                results_CLOE_Q.t_f = t_f;
                results_CLOE_Q.N = N;
                results_CLOE_Q.Max_it = 20;
                results_CLOE_Q.Theta_obj = Theta_obj;
                results_CLOE_Q.Xhi_obj = Xhi_obj;
                results_CLOE_Q.Initial_points = Initial_pts;
                results_CLOE_Q.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
                results_CLOE_Q.eps = zeros(N_i, N_t);
                results_CLOE_Q.times = zeros(N_i, N_t);
                results_CLOE_Q.iterations = zeros(N_i, N_t);
                results_CLOE_Q.Thetas_iteration = zeros(N_i, N_t, 17, results_CLOE_Q.Max_it+1);
                
                
                for i=1:N_i % For each set of initial parameters
                    
                    i
                    Theta_0 = Initial_pts(:,i)
                    
                    times = zeros(N_t, 1);
                    Thetas = zeros(17, N_t);
                    eps = zeros(1,N_t);
                    iterations = zeros(1, N_t);
                    
                    Max_it = results_CLOE_Q.Max_it;
                    Thetas_iteration = zeros(N_t, 17, Max_it+1);
                    
                    parfor j=1:N_t  % For each trajectory noise
                        j
                        
                        data_struct = Data(j);
                        
                        try
                            tic
                            [Theta_CLOE_Q, ~, it_CLOE_Q, ~, Thetas_CLOE_Q] =  CLOE_Ident_bis(Theta_0, data_struct, t_i, t_f, N, optionsCLOE_Q);
                            times(j)=toc;
                        catch
                            Theta_CLOE_Q = zeros(17,1);
                            it_CLOE_Q = 0;
                            Thetas_CLOE_Q = zeros(17, Max_it+1);
                        end
                        
                        
                        Thetas(:, j)=Theta_CLOE_Q;
                        eps(j)=norm(Theta_CLOE_Q-Theta_obj);%/norm(Theta_obj);
                        iterations(j)=it_CLOE_Q;
                        if displayProgression == true
                            waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('CLOE-Q: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                        end
                        Thetas_iteration(j, :, :) = Thetas_CLOE_Q;
                    end
                    
                    results_CLOE_Q.times(i, :) = times;
                    
                    for j = 1:N_t % For each trajectory noise
                        results_CLOE_Q.Thetas(i,j,:)=Thetas(:,j);
                        results_CLOE_Q.eps(i, j)=eps(j);
                        results_CLOE_Q.iteration(i,j)=iterations(j);
                        results_CLOE_Q.Thetas_iteration(i, j, :, :) = q_iteration(j,:,:);
                    end
                    
                    save('Benchmark/Results/results_CLOE_Q.mat', 'results_CLOE_Q')
                end
                save('Benchmark/Results/results_CLOE_Q.mat', 'results_CLOE_Q')
                
            case 'lsqnonlin'
                
                % Initialization:
                
                if displayProgression == true
                    waitbar(0, progressBar, sprintf('CLOE-Q: First Iteration...'));
                end
                results_CLOE_Q.N_t = N_t;
                results_CLOE_Q.N_i = N_i;
                results_CLOE_Q.t_i = t_i;
                results_CLOE_Q.t_f = t_f;
                results_CLOE_Q.N = N;
                results_CLOE_Q.Theta_obj = Theta_obj;
                results_CLOE_Q.Xhi_obj = Xhi_obj;
                results_CLOE_Q.Initial_points = Initial_pts;
                results_CLOE_Q.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
                results_CLOE_Q.times = zeros(N_i, N_t);
                results_CLOE_Q.iterations = zeros(N_i, N_t);
                
                % As lsqnonlin is used we have :
                results_CLOE_Q.lambdas_upper = zeros(N_i, N_t, 17);
                results_CLOE_Q.lambdas_lower = zeros(N_i, N_t, 17);
                results_CLOE_Q.jacobians = zeros(N_i, N_t, 17);
                
                options = optimset('Display','iter');
                
                for i=1:N_i
                    i
                    Theta_0 = Initial_pts(:,i);
                    
                    times = zeros(N_t, 1);
                    Thetas = zeros(17, N_t);
                    lambdas_upper = zeros(17, N_t);
                    lambdas_lower = zeros(17, N_t);
                    jacobians = zeros(17, N_t);
                    
                    parfor j=1:N_t
                        
                        j
                        data_struct = Data(j);
                        
                        try
                            tic
                            [Theta_CLOE_Q,Resnorm_CLOE_Q,FVAL_CLOE_Q,EXITFLAG_CLOE_Q,OUTPUT_CLOE_Q,lambda_CLOE_Q,jacobian_CLOE_Q] = lsqnonlin(@(Theta) norm(RRR_CLOE_Q(Theta, data_struct, t_i, t_f, N, optionsCLOE_Q))^2, Theta_0, [], [], options);
                            times(j)=toc;
                        catch
                            Theta_CLOE_Q = zeros(17,1);
                            lambda_CLOE_Q = [];
                            jacobian_CLOE_Q = zeros(17,1);
                        end
                        
                        Thetas(:, j)=Theta_CLOE_Q;
                        lambdas_upper(:,j) = lambda_CLOE_Q.upper;
                        lambdas_lower(:,j) = lambda_CLOE_Q.lower;
                        jacobians(:,j) = jacobian_CLOE_Q;
                        iterations(j)=OUTPUT_CLOE_Q.iterations
                    end
                    if displayProgression == true
                        waitbar(((i-1)*N_t+N_t)/((N_i-1)*N_t+N_t), progressBar, sprintf('CLOE-Q: %d%% done...', floor(100*((i-1)*N_t+N_t)/((N_i-1)*N_t+N_t))));
                    end
                    results_CLOE_Q.times(i, :) = times;
                    
                    for j = 1:N_t
                        results_CLOE_Q.Thetas(i,j,:)=Thetas(:,j);
                        results_CLOE_Q.lambdas_upper(i, j, :) = lambdas_upper(:,j);
                        results_CLOE_Q.lambdas_lower(i, j, :) = lambdas_lower(:,j);
                        results_CLOE_Q.jacobians(i, j, :)=jacobians(:, j);
                        results_CLOE_Q.iteration(i,j)=iterations(j);
                    end
                    save('Benchmark/Results/results_CLOE_Q.mat', 'results_CLOE_Q')
                end
                save('Benchmark/Results/results_CLOE_Q.mat', 'results_CLOE_Q')
        end
        disp("%%%%%%%%%%%%%    Finished CLOE-Q    %%%%%%%%%%%%%")
    end % end CLOE_Q
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Closed-Loop Output-Error (CLOE) with joint velocity input:
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(6)==1 % CLOE_Qp
        
        disp("%%%%%%%%%%%%%    Starting CLOE-Qp    %%%%%%%%%%%%%")
        
        optionsCLOE_Qp.optimizer = 'lsqnonlin';
        %         optionsCLOE_Qp.optimizer = 'simplex';
        optionsCLOE_Qp.implementation = codeImplementation; % [classic]: do not use mex functions (very slow), [optim]: use mex functions (faster)
        
        switch optionsCLOE_Qp.optimizer
            case 'simplex'
                
                % Initialization:
                
                if displayProgression == true
                    waitbar(0, progressBar, sprintf('CLOE-Qp: First Iteration...'));
                end
                results_CLOE_Qp.N_t = N_t;
                results_CLOE_Qp.N_i = N_i;
                results_CLOE_Qp.t_i = t_i;
                results_CLOE_Qp.t_f = t_f;
                results_CLOE_Qp.N = N;
                results_CLOE_Qp.Max_it = 1;
                results_CLOE_Qp.Theta_obj = Theta_obj;
                results_CLOE_Qp.Xhi_obj = Xhi_obj;
                results_CLOE_Qp.Initial_points = Initial_pts;
                results_CLOE_Qp.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
                results_CLOE_Qp.eps = zeros(N_i, N_t);
                results_CLOE_Qp.times = zeros(N_i, N_t);
                results_CLOE_Qp.iterations = zeros(N_i, N_t);
                results_CLOE_Qp.Thetas_iteration = zeros(N_i, N_t, 17, results_CLOE_Qp.Max_it+1);
                
                for i = 1:N_i % For each set of initial parameters
                    i
                    Theta_0 = Initial_pts(:,i)
                    times = zeros(N_t, 1);
                    Thetas = zeros(17, N_t);
                    eps = zeros(1,N_t);
                    iterations = zeros(1, N_t);
                    Max_it = results_CLOE_Qp.Max_it;
                    Thetas_iteration = zeros(N_t, 17, Max_it+1);
                    
                    parfor j = 1:N_t % For each trajectory noise
                        j
                        data_struct = Data(j);
                        %
                        try
                            tic
                            [Theta_CLOE_Qp, ~, it_CLOE_Qp, ~, Thetas_CLOE_Qp] =  CLOE_Ident_bis_Qp(Theta_0, data_struct, t_i, t_f, N, optionsCLOE_Qp);
                            times(j)=toc;
                        catch
                            Theta_CLOE_Qp = zeros(17,1);
                            it_CLOE_Qp = 0;
                            Thetas_CLOE_Qp = zeros(17, Max_it+1);
                        end
                        
                        Thetas(:, j)=Theta_CLOE_Qp;
                        eps(j)=norm(Theta_CLOE_Qp-Theta_obj);%/norm(Theta_obj);
                        iterations(j)=it_CLOE_Qp;
                        Thetas_iteration(j, :, :) = Thetas_CLOE_Qp;
                        
                    end
                    if displayProgression == true
                        waitbar(((i-1)*N_t+N_t)/((N_i-1)*N_t+N_t), progressBar, sprintf('CLOE-Q: %d%% done...', floor(100*((i-1)*N_t+N_t)/((N_i-1)*N_t+N_t))));
                    end
                    results_CLOE_Qp.times(i, :) = times;
                    
                    for j = 1:N_t % For each trajectory noise
                        results_CLOE_Qp.Thetas(i,j,:)=Thetas(:,j);
                        results_CLOE_Qp.eps(i, j)=eps(j);
                        results_CLOE_Qp.iteration(i,j)=iterations(j);
                        results_CLOE_Qp.Thetas_iteration(i, j, :, :) = Thetas_iteration(j,:,:);
                    end
                    save('Benchmark/Results/results_CLOE_Qp.mat', 'results_CLOE_Qp')
                end
                save('Benchmark/Results/results_CLOE_Qp.mat', 'results_CLOE_Qp')
                
            case 'lsqnonlin'
                
                % Initialization:
                
                if displayProgression == true
                    waitbar(0, progressBar, sprintf('CLOE-Qp: First Iteration...'));
                end
                results_CLOE_Qp.N_t = N_t;
                results_CLOE_Qp.N_i = N_i;
                results_CLOE_Qp.t_i = t_i;
                results_CLOE_Qp.t_f = t_f;
                results_CLOE_Qp.N = N;
                results_CLOE_Qp.Theta_obj = Theta_obj;
                results_CLOE_Qp.Xhi_obj = Xhi_obj;
                results_CLOE_Qp.Initial_points = Initial_pts;
                results_CLOE_Qp.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
                results_CLOE_Qp.times = zeros(N_i, N_t);
                
                % As lsqnonlin is used :
                results_CLOE_Qp.lambdas_upper = zeros(N_i, N_t, 17);
                results_CLOE_Qp.lambdas_lower = zeros(N_i, N_t, 17);
                results_CLOE_Qp.jacobians = zeros(N_i, N_t, 17);
                results_CLOE_Qp.output = [];
                
                options = optimset('Display','iter');
                for i = 1:N_i
                    i
                    Theta_0 = Initial_pts(:,i);
                    
                    times = zeros(N_t, 1);
                    Thetas = zeros(17, N_t);
                    lambdas_upper = zeros(17, N_t);
                    lambdas_lower = zeros(17, N_t);
                    jacobians = zeros(17, N_t);
                    
                    parfor j = 1:N_t
                        j
                        data_struct = Data(j);
                        
                        try
                            tic
                            [Theta_CLOE_Qp,Resnorm_CLOE_Qp,FVAL_CLOE_Qp,EXITFLAG_CLOE_Qp,OUTPUT_CLOE_Qp,lambda_CLOE_Qp,jacobian_CLOE_Qp] = lsqnonlin(@(Theta) norm(RRR_CLOE_Qp(Theta, data_struct, t_i, t_f, N, optionsCLOE_Qp))^2, Theta_0, [], [], options);
                            times(j)=toc;
                        catch
                            Theta_CLOE_Qp = zeros(17,1);
                            lambda_CLOE_Qp = [];
                            jacobian_CLOE_Qp = zeros(17,1);
                        end
                        
                        Thetas(:, j)=Theta_CLOE_Qp;
                        lambdas_upper(:,j) = lambda_CLOE_Qp.upper;
                        lambdas_lower(:,j) = lambda_CLOE_Qp.lower;
                        jacobians(:,j) = jacobian_CLOE_Qp;
                        iterations(j) = OUTPUT_CLOE_Qp;
                        
                    end
                    if displayProgression == true
                        waitbar(((i-1)*N_t+N_t)/((N_i-1)*N_t+N_t), progressBar, sprintf('CLOE-Qp: %d%% done...', floor(100*((i-1)*N_t+N_t)/((N_i-1)*N_t+N_t))));
                    end
                    results_CLOE_Qp.times(i, :) = times;
                    
                    for j = 1:N_t
                        results_CLOE_Qp.Thetas(i,j,:)=Thetas(:,j);
                        results_CLOE_Qp.lambdas_upper(i, j, :) = lambdas_upper(:,j);
                        results_CLOE_Qp.lambdas_lower(i, j, :) = lambdas_lower(:,j);
                        results_CLOE_Qp.jacobians(i, j, :)=jacobians(:, j);
                        results_CLOE_Qp.iteration(i,j)=iterations(j);
                    end
                    results_CLOE_Qp.iteration(i,j)=iterations(j);
                    save('Benchmark/Results/results_CLOE_Qp.mat', 'results_CLOE_Qp')
                end
                save('Benchmark/Results/results_CLOE_Qp.mat', 'results_CLOE_Qp')
        end
        disp("%%%%%%%%%%%%%    Finished CLOE-Qp    %%%%%%%%%%%%%")
    end % end CLOE_Qp
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Extended Kalman Filter (EKF):
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(7)==1 % EKF
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting EKF    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('DDIM-EKF: First Iteration...'));
        end
        results_EKF.N_t = N_t;
        results_EKF.N_i = N_i;
        results_EKF.t_i = t_i;
        results_EKF.t_f = t_f;
        results_EKF.N = N;
        results_EKF.Theta_obj = Theta_obj;
        results_EKF.Xhi_obj = Xhi_obj;
        results_EKF.Initial_points = Initial_pts;
        results_EKF.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_EKF.States = zeros(N, 23, N_i*N_t); % -> storage of the complete iterative procedure
        results_EKF.Commands = zeros(N, 3, N_i*N_t); % -> storage of the complete iterative procedure
        results_EKF.eps = zeros(N_i, N_t);
        results_EKF.times = zeros(N_i, N_t);
        
        % Options:
        
        optionsKalman.implementation = codeImplementation; % [classic]: custom made implementation, [optim]: custom made optimized implementation, [toolbox] matlab signal processing toolbox
        optionsKalman.type = 'ekf';
        
        for i = 1:N_i % For each set of initial parameters
            %         i
            Theta_0 = Initial_pts(:,i)
            initError = norm(Theta_obj-Theta_0)
            if initError>8
                optionsKalman.initEstimate = 'rough'
                pause(1)
            elseif initError<=8 && initError>4
                optionsKalman.initEstimate = 'medium'
                pause(1)
            else
                optionsKalman.initEstimate = 'fine'
                pause(1)
            end
            
            for j = 1:N_t % For each trajectory noise
                data_struct = Data(j);
                
                tic
                Iteration = (i-1)*N_t+j
                optionsKalman.it=Iteration;
                optionsKalman.itmax=(N_i-1)*N_t+N_t;
                [Theta_EKF, X_EKF, U_EKF, time_EKF, normError_EKF, pNoise_EKF] =  KF_identification(optionsKalman, Theta_0, data_struct, t_i, t_f, N, Theta_obj);
                results_EKF.times(i, j)=toc;
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('DDIM-EKF: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_EKF.Thetas(i,j,:)=Theta_EKF;
                eps = norm(Theta_EKF-Theta_obj)
                results_EKF.eps(i, j)=eps;
                results_EKF.States(:,:,(N_i-1)*i+j)=X_EKF;
                results_EKF.Commands(:,:,(N_i-1)*i+j)=U_EKF;
            end
        end
        save('Benchmark/Results/results_EKF.mat', 'results_EKF')
        disp("%%%%%%%%%%%%%    Finished EKF    %%%%%%%%%%%%%")
    end % end EKF
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Unscented Kalman Filter (UKF):
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(8)==1 % UKF
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting UKF    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('DDIM-UKF: First Iteration...'));
        end
        results_UKF.N_t = N_t;
        results_UKF.N_i = N_i;
        results_UKF.t_i = t_i;
        results_UKF.t_f = t_f;
        results_UKF.N = N;
        results_UKF.Theta_obj = Theta_obj;
        results_UKF.Xhi_obj = Xhi_obj;
        results_UKF.Initial_points = Initial_pts;
        results_UKF.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_UKF.States = zeros(N, 23, N_i*N_t); % -> storage of the complete iterative procedure
        results_UKF.Commands = zeros(N, 3, N_i*N_t); % -> storage of the complete iterative procedure
        results_UKF.eps = zeros(N_i, N_t);
        results_UKF.times = zeros(N_i, N_t);
        
        % Options:
        
        optionsKalman.implementation = codeImplementation; % [classic]: custom made implementation, [optim]: custom made optimized implementation, [toolbox] matlab signal processing toolbox
        optionsKalman.type = 'ukf';
        optionsKalman.sigmaCompute = 'svd'; % [svd]: compute matrix square root using svd, [chol]: compute matrix square root using Cholesky factorization.
        
        for i = 1:N_i % For each set of initial parameters
            %         i
            Theta_0 = Initial_pts(:,i)
            initError = norm(Theta_obj-Theta_0)
            if initError>8
                optionsKalman.initEstimate = 'rough'
                pause(1)
            elseif initError<=8 && initError>4
                optionsKalman.initEstimate = 'medium'
                pause(1)
            else
                optionsKalman.initEstimate = 'fine'
                pause(1)
            end
            
            for j = 1:N_t % For each trajectory noise
                data_struct = Data(j);
                
                tic
                Iteration = (i-1)*N_t+j
                optionsKalman.it=Iteration;
                optionsKalman.itmax=(N_i-1)*N_t+N_t;
                [Theta_UKF, X_UKF, U_UKF, time_UKF, normError_UKF, pNoise_UKF] =  KF_identification(optionsKalman, Theta_0, data_struct, t_i, t_f, N, Theta_obj);
                results_UKF.times(i, j)=toc;
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('DDIM-UKF: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_UKF.Thetas(i,j,:)=Theta_UKF;
                eps = norm(Theta_UKF-Theta_obj)
                results_UKF.eps(i, j)=eps;
                results_UKF.States(:,:,(N_i-1)*i+j)=X_UKF;
                results_UKF.Commands(:,:,(N_i-1)*i+j)=U_UKF;
            end
        end
        save('Benchmark/Results/results_UKF.mat', 'results_UKF')
        disp("%%%%%%%%%%%%%    Finished UKF    %%%%%%%%%%%%%")
    end % end UKF
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Square Root Unscented Kalman Filter (SRUKF):
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if identificationMethods(9)==1 % SRUKF
        
        % Initialization:
        
        disp("%%%%%%%%%%%%%    Starting SRUKF    %%%%%%%%%%%%%")
        if displayProgression == true
            waitbar(0, progressBar, sprintf('DDIM-SRUKF: First Iteration...'));
        end
        results_SRUKF.N_t = N_t;
        results_SRUKF.N_i = N_i;
        results_SRUKF.t_i = t_i;
        results_SRUKF.t_f = t_f;
        results_SRUKF.N = N;
        results_SRUKF.Theta_obj = Theta_obj;
        results_SRUKF.Xhi_obj = Xhi_obj;
        results_SRUKF.Initial_points = Initial_pts;
        results_SRUKF.Thetas = zeros(N_i, N_t, 17); % -> storage of the identified vector for each computation point
        results_SRUKF.States = zeros(N, 23, N_i*N_t); % -> storage of the complete iterative procedure
        results_SRUKF.Commands = zeros(N, 3, N_i*N_t); % -> storage of the complete iterative procedure
        results_SRUKF.eps = zeros(N_i, N_t);
        results_SRUKF.times = zeros(N_i, N_t);
        
        % Options:
        
        optionsKalman.implementation = codeImplementation; % [classic]: custom made implementation, [optim]: custom made optimized implementation, [toolbox] matlab signal processing toolbox
        optionsKalman.type = 'srukf';
        
        for i = 1:N_i % For each set of initial parameters
            %         i
            Theta_0 = Initial_pts(:,i)
            initError = norm(Theta_obj-Theta_0)
            if initError>8
                optionsKalman.initEstimate = 'rough'
                pause(1)
            elseif initError<=8 && initError>4
                optionsKalman.initEstimate = 'medium'
                pause(1)
            else
                optionsKalman.initEstimate = 'fine'
                pause(1)
            end
            
            for j = 1:N_t % For each trajectory noise
                data_struct = Data(j);
                
                tic
                Iteration = (i-1)*N_t+j
                optionsKalman.it=Iteration;
                optionsKalman.itmax=(N_i-1)*N_t+N_t;
                [Theta_SRUKF, X_SRUKF, U_SRUKF, time_SRUKF, normError_SRUKF, pNoise_SRUKF] =  KF_identification(optionsKalman, Theta_0, data_struct, t_i, t_f, N, Theta_obj);
                results_SRUKF.times(i, j)=toc;
                if displayProgression == true
                    waitbar(((i-1)*N_t+j)/((N_i-1)*N_t+N_t), progressBar, sprintf('DDIM-SRUKF: %d%% done...', floor(100*((i-1)*N_t+j)/((N_i-1)*N_t+N_t))));
                end
                results_SRUKF.Thetas(i,j,:)=Theta_SRUKF;
                eps = norm(Theta_SRUKF-Theta_obj)
                results_SRUKF.eps(i, j)=eps;
                results_SRUKF.States(:,:,(N_i-1)*i+j)=X_SRUKF;
                results_SRUKF.Commands(:,:,(N_i-1)*i+j)=U_SRUKF;
            end
        end
        save('Benchmark/Results/results_SRUKF.mat', 'results_SRUKF')
        disp("%%%%%%%%%%%%%    Finished SRUKF    %%%%%%%%%%%%%")
    end % end SRUKF
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if displayProgression == true
        close(progressBar); % Close progress bar object
    end
    disp("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
    disp("%%%%%%%%%%%%%    Computations Completed    %%%%%%%%%%%%%")
    disp("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
elseif ismac
    disp('Mac not supported. So far only Linux is...')
elseif ispc
    disp('Windows not supported. So far only Linux is...')
else
    disp('Platform not recognized. So far only Linux is supported.')
end
