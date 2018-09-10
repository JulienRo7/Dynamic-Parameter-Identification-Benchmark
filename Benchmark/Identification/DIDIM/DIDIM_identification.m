function [Theta_DIDIM, it, W, EPS, Thetas, flag]=DIDIM_identification(Theta_0, data_struct, stopCrit, optionsDIDIM)

% Identify the dynamics parameters of the robot using the DIDIM method:
% Tau = W * Theta
% at each iteration minimizes : ||Tau - W(Theta(k)) * Theta ||
%                       Theta(k+1)=argmin(||Tau - W(Theta(k)) * Theta ||)
%

%% Starting conditions:

N = numel(data_struct.t(:));
X_0 = [0; 0; 0; 0; pi/2; 0.1]; % X = [Qp;Q]:
Theta = Theta_0;
eps = 1;
EPS = zeros(1,stopCrit.Max_it);
Thetas = zeros(17, stopCrit.Max_it+1);
crit_1=1;
crit_2=1;

%% Data decimation and construction of Y_tau:

Tau1_decim = decimate(data_struct.tau1(:),optionsDIDIM.ndecim);
Tau2_decim = decimate(data_struct.tau2(:),optionsDIDIM.ndecim);
Tau3_decim = decimate(data_struct.tau3(:),optionsDIDIM.ndecim);
Tau_decim = [Tau1_decim, Tau2_decim, Tau3_decim];

N_decim = numel(Tau1_decim);
W_ndec=zeros(3*N, 17);
W=zeros(3*N_decim, 17);
Y_tau=zeros(3*N_decim, 1);

if strcmp(optionsDIDIM.implementation,'optim')
    % Compute the sampled vector:
    Y_tau = torqueVector_mex(Tau_decim);
elseif strcmp(optionsDIDIM.implementation,'classic')
    % Compute the sampled vector:
    Y_tau = torqueVector(Tau_decim);
else
    error("DIDIM: unknown option");
end

%% DIDIM algorithm:

%iteration counter
it = 1;
EPS(it)=eps;
Thetas(:,it)=Theta;

while (( (crit_1 >= stopCrit.tol_1) && (crit_2 >= stopCrit.tol_2 ) ) && (it<stopCrit.Max_it))
    
    % Simulation of the robot:
    if strcmp(optionsDIDIM.implementation,'optim')
        % Simulation of the robot using the current parameters:
        [~, X_it, Qpp] = integrate_RRR_dyn_CL_mex(X_0, Theta, data_struct.t(1), 2*data_struct.t(end), 2*N);
    elseif strcmp(optionsDIDIM.implementation,'classic')
        % Simulation of the robot using the current parameters:
        [~, X_it, Qpp] = integrate_RRR_dyn_CL(X_0, Theta, data_struct.t(1), 2*data_struct.t(end), 2*N);
    else
        error("DIDIM: unknown implementation option");
    end

    Q_it = [X_it(4,10002:end)', X_it(5,10002:end)', X_it(6,10002:end)'];
    Qp_it = [X_it(1,10002:end)', X_it(2,10002:end)', X_it(3,10002:end)'];
    Qpp_it = [Qpp(1,10002:end)', Qpp(2,10002:end)', Qpp(3,10002:end)'];
    
    if strcmp(optionsDIDIM.implementation,'optim')
        % Building of the observation matrix W for the current iteration of Theta:
        W_ndec = observationMatrix_mex(Q_it, Qp_it, Qpp_it);
    elseif strcmp(optionsDIDIM.implementation,'classic')
        % Building of the observation matrix W for the current iteration of Theta:
        W_ndec = observationMatrix(Q_it, Qp_it, Qpp_it);
    else
        error("DIDIM: unknown option");
    end
    
    % Decimation filter
    
    for col=1:17
        W(1:3:end,col) = decimate(W_ndec(1:3:end,col),optionsDIDIM.ndecim);
        W(2:3:end,col) = decimate(W_ndec(2:3:end,col),optionsDIDIM.ndecim);
        W(3:3:end,col) = decimate(W_ndec(3:3:end,col),optionsDIDIM.ndecim);
    end
    
    % Solving the LS problem:
    
    if strcmp(optionsDIDIM.solver,'backslash')
        
        Theta_next_it = W\Y_tau;
        
    elseif strcmp(optionsDIDIM.solver,'pinv')
        
        Theta_next_it = pinv(W)*Y_tau;
        
    elseif strcmp(optionsDIDIM.solver,'quadprog')
        
        Theta_next_it = quadprog(W'*W, -Y_tau'*W ,[] ,[] ,[], [], Theta_0-5*ones(17,1), Theta_0+5*ones(17,1), [], optimoptions(@quadprog,'Display', 'off','Algorithm','interior-point-convex'));
        
    elseif strcmp(optionsDIDIM.solver,'qpOASES')
        
        [Theta_next_it,~,~,~,~] = qpOASES(W'*W, (-Y_tau'*W)', Theta_0-5*ones(17,1), Theta_0+5*ones(17,1));
        
    else
        error("DIDIM: unknown option");
    end
    
    % Computation of the new error:
    eps_next_it = norm(Y_tau - W*Theta);
    
    % Stop criteria:
    crit_1 =  abs((eps_next_it - eps)/eps);
    crit_2 = max(abs((Theta_next_it-Theta)./Theta));
    
    % Actualization of the values:
    
    eps = eps_next_it;
    it = it+1;
    EPS(it)=eps;
    Theta =  Theta_next_it
    Thetas(:,it)=Theta;
end

if optionsDIDIM.debug == true
    Q = data_struct.q1(:);
    Err=100*(Q(2:end)-(X_it(4,:))');
    % Plotting for debug:
    figure
    title('Trajectory DIDIM')
    plot(X_it(4,:),'--','LineWidth',2)
    hold on
    plot(Q(2:end),'LineWidth',1)
    hold on
    plot(Err)
    xlabel('Samples');
    ylabel('Q');
    legend('q1 simulated','q1 robot','100x error')
    grid on
    grid minor
    pause
end

%return of the result
Theta_DIDIM = Theta;

if crit_1 < stopCrit.tol_1
    flag = 1;
    fprintf("crit_1 < tol_1");
else
    if crit_2 < stopCrit.tol_2
        flag = 2;
        fprintf("crit_2 < tol_2");
    else
        if it >= stopCrit.Max_it
            flag = 3;
            fprintf("Reached iteration limit");
        else
            flag = 0;
            fprintf("Error...");
        end
    end
end

end