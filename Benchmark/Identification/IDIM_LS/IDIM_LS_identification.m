function [Theta_LS, cond, sig_min, W] = IDIM_LS_identification(data_struct, optionsIDIM_LS)

%% Data decimation and filtering

switch optionsIDIM_LS.filter
    case 'no'
        
        % Torque
        Tau1_decim = decimate(data_struct.tau1(:),optionsIDIM_LS.ndecim);
        Tau2_decim = decimate(data_struct.tau2(:),optionsIDIM_LS.ndecim);
        Tau3_decim = decimate(data_struct.tau3(:),optionsIDIM_LS.ndecim);
        
        % Position
        Q1 = data_struct.q1(:);
        Q2 = data_struct.q2(:);
        Q3 = data_struct.q3(:);
        
        % Velocity
        Qp1 = data_struct.qp1(:);
        Qp2 = data_struct.qp2(:);
        Qp3 = data_struct.qp3(:);
        
        % Acceleration
        Qpp1 = data_struct.qpp1(:);
        Qpp2 = data_struct.qpp2(:);
        Qpp3 = data_struct.qpp3(:);
        
    case 'lowpass'
        
        % Torque
        Tau1_decim = decimate(data_struct.tau1(:),optionsIDIM_LS.ndecim);
        Tau2_decim = decimate(data_struct.tau2(:),optionsIDIM_LS.ndecim);
        Tau3_decim = decimate(data_struct.tau3(:),optionsIDIM_LS.ndecim);
        
        % Position
        Q1 = data_struct.q1(:);
        Q2 = data_struct.q2(:);
        Q3 = data_struct.q3(:);
        
        % Velocity
        Qp1 = data_struct.qp1(:);
        Qp2 = data_struct.qp2(:);
        Qp3 = data_struct.qp3(:);
        
        % Low-pass Filtered Acceleration
        Qpp1 = filter(optionsIDIM_LS.Hd, data_struct.qpp1(:));
        Qpp2 = filter(optionsIDIM_LS.Hd, data_struct.qpp2(:));
        Qpp3 = filter(optionsIDIM_LS.Hd, data_struct.qpp3(:));
        
    case 'butterworth'
        
        % Butterworth parameters
        ob = optionsIDIM_LS.freq_fil/optionsIDIM_LS.fnyq;
        [b,a] = butter(optionsIDIM_LS.nfilt,ob);
        
        q1_f = filtfilt(b,a,data_struct.q1(:));
        q2_f = filtfilt(b,a,data_struct.q2(:));
        q3_f = filtfilt(b,a,data_struct.q3(:));
        
        qp1_f = diffcent(q1_f,optionsIDIM_LS.dt);
        qp2_f = diffcent(q2_f,optionsIDIM_LS.dt);
        qp3_f = diffcent(q3_f,optionsIDIM_LS.dt);
        
        qpp1_f = diffcent(qp1_f,optionsIDIM_LS.dt);
        qpp2_f = diffcent(qp2_f,optionsIDIM_LS.dt);
        qpp3_f = diffcent(qp3_f,optionsIDIM_LS.dt);
        
        % Decimate Torque + remove border
        Tau1_decim = decimate(data_struct.tau1(optionsIDIM_LS.border:end),optionsIDIM_LS.ndecim);
        Tau2_decim = decimate(data_struct.tau2(optionsIDIM_LS.border:end),optionsIDIM_LS.ndecim);
        Tau3_decim = decimate(data_struct.tau3(optionsIDIM_LS.border:end),optionsIDIM_LS.ndecim);
        
        % Decimate Position + remove border
        Q1 = q1_f(optionsIDIM_LS.border:end);
        Q2 = q2_f(optionsIDIM_LS.border:end);
        Q3 = q3_f(optionsIDIM_LS.border:end);
        
        % Decimate Velocity + remove border
        Qp1= qp1_f(optionsIDIM_LS.border:end);
        Qp2 = qp2_f(optionsIDIM_LS.border:end);
        Qp3 = qp3_f(optionsIDIM_LS.border:end);
        
        % Decimate Acceleration + remove border
        Qpp1= qpp1_f(optionsIDIM_LS.border:end);
        Qpp2= qpp2_f(optionsIDIM_LS.border:end);
        Qpp3 = qpp3_f(optionsIDIM_LS.border:end);
        
    otherwise
        
        error("IDIM_LS: Unknown filter type !");
end

N = numel(data_struct.t(:));
N_decim = numel(Tau1_decim);
Tau_decim = [Tau1_decim, Tau2_decim, Tau3_decim];
Q = [Q1, Q2, Q3];
Qp = [Qp1, Qp2, Qp3];
Qpp = [Qpp1, Qpp2, Qpp3];
W=zeros(3*N_decim, 17);
W_ndec=zeros(3*N, 17);
Y_tau=zeros(3*N_decim, 1);

%% Populating W and Y_tau

if strcmp(optionsIDIM_LS.implementation,'optim')
    % Compute the sampled vector:
    Y_tau = torqueVector_mex(Tau_decim);
    % Compute the observation matrix:
    W_ndec = observationMatrix_mex(Q, Qp, Qpp);
elseif strcmp(optionsIDIM_LS.implementation,'classic')
    % Compute the sampled vector:
    Y_tau = torqueVector(Tau_decim);
    % Compute the observation matrix:
    W_ndec = observationMatrix(Q, Qp, Qpp);
else
    error("IDIM_LS: unknown option");
end

for col=1:17
    W(1:3:end,col) = decimate(W_ndec(1:3:end,col),optionsIDIM_LS.ndecim);
    W(2:3:end,col) = decimate(W_ndec(2:3:end,col),optionsIDIM_LS.ndecim);
    W(3:3:end,col) = decimate(W_ndec(3:3:end,col),optionsIDIM_LS.ndecim);
end

%% Solving the LS problem:

if strcmp(optionsIDIM_LS.solver,'backslash')
    
    Theta_LS = W\Y_tau;
    
elseif strcmp(optionsIDIM_LS.solver,'pinv')
    
    Theta_LS = pinv(W)*Y_tau;
    
else
    error("IDIM_LS: unknown option");
end

s=svd(W);
cond = max(s)/min(s);
sig_min = min(s);

end