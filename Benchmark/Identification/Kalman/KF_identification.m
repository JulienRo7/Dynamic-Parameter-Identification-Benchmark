function [Theta_KF, X, U, time, normError, pNoise] = KF_identification(filterOptions, Theta_0, data_struct, t_0, t_end, Nsteps, Theta_real)

%% Kalman Filter Parameter Initialization

[x, P, Rv, Rn, alpha, beta, kappa, paramSize, pNoiseAdaptParams, X, U, normError, pNoise, time, control, kalmanFilterToolbox] = initKalman(filterOptions, Theta_0, data_struct, Nsteps);

it_max=find(data_struct.t<=t_end, 1, 'last');
it_min=find(data_struct.t>t_0, 1, 'first');
k = ceil((it_max-it_min)/Nsteps);
iteration=0;
maxParam=10; % Saturation for the parameters value

%% Kalman Filter Loop

for index=max(it_min,k+1):k:it_max
    
    % Compute torque command:
    [u,iDQ] = computeCommand(x, data_struct.t(index), data_struct, control, index, k);
    control.iDQ = iDQ;
    
    % Acquire measurement:
    y = acquireMeasurement(data_struct, index);
    
    % Process noise annealing for the parameters (inspired by the ReBEL toolkit from Rudolph Van der Merwe):
    [Rv, pNoiseAdaptParams] = annealingNoiseCovariance(Rv, pNoiseAdaptParams, paramSize);
    
    % %     % Saturation of the estimated state vector to avoid divergence:
    %     x(end-paramSize+1:end) = min(maxParam*ones(paramSize,1),max(-maxParam*ones(paramSize,1),x(end-paramSize+1:end)));
    %     x(end-2:end) = max(zeros(3,1),x(end-2:end));
    
    % Nonlinear Kalman Filter:
    [x, P, status] = iterateKalman(index, k, filterOptions, data_struct, x, u, P, y, Rv, Rn, alpha, beta, kappa, kalmanFilterToolbox);
    
    if strcmp(status, 'error')
        break;
    end
    
    %     Theta = [x(end-paramSize+1:end),Theta_real]
    
    iteration = iteration+1;
    errorNorm=norm(x(end-paramSize+1:end)-Theta_real);
    normError(iteration) = errorNorm;
    pNoise(iteration) = pNoiseAdaptParams.cov(1);
    X(iteration,:)=x';
    U(iteration,:)=u';
    time(iteration)=data_struct.t(index);
end
Theta_KF = x(end-paramSize+1:end);

end

