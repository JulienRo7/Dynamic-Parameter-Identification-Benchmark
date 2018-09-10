function [x, P, Rv, Rn, alpha, beta, kappa, paramSize, pNoiseAdaptParams, X, U, normError, pNoise, time, control, kalmanFilter] = initKalman(filterOptions, Theta_0, data_struct, N)

% Initial augmented state estimate:
x = [data_struct.qp1(1);
    data_struct.qp2(1);
    data_struct.qp3(1);
    data_struct.q1(1);
    data_struct.q2(1);
    data_struct.q3(1);
    Theta_0];

% Sizes:
[paramSize,~]=size(Theta_0);
[stateAugSize,~]=size(x);
stateSize = stateAugSize-paramSize;

X =  zeros(N, stateAugSize);
U =  zeros(N, 3);
normError =  zeros(N, 1);
pNoise =  zeros(N, 1);
time =  zeros(N, 1);

% UKF tunning parameters:
%       0 <  Alpha <= 1     
%       0 <= Beta          
%       0 <= Kappa <= 3   

alpha = 1e-1;
beta  = 2;
kappa = 0;

P = eye(stateAugSize); % Initial covariance = covariance of the noise
Rn = 3.046e-10*eye(3); % Measurement noise covariance
Rv = eye(stateAugSize); % Process noise covariance
Rv(1:stateSize,1:stateSize) = diag([7e-4, 7e-4, 7e-4, 2e-5, 2e-5, 2e-5]);

switch(filterOptions.initEstimate)
    case 'fine'
        P(stateSize+1:end,stateSize+1:end) = 1e-3*eye(paramSize);
        Rv(stateAugSize-paramSize+1:end,stateAugSize-paramSize+1:end) = 1e-4*eye(paramSize);  
        pNoiseAdaptParams.annealFactor = 0.5;  
        pNoiseAdaptParams.variance = 1e-9;
        alpha = 2e-1;
    case 'medium'
        P(stateSize+1:end,stateSize+1:end) = 1e-2*eye(paramSize);
        Rv(stateSize+1:end,stateSize+1:end) = 7e-4*eye(paramSize);  
        pNoiseAdaptParams.annealFactor = 0.9; 
        pNoiseAdaptParams.variance = 3e-7;
        alpha = 0.55e-3;
    case 'rough'
        P(stateSize+1:end,stateSize+1:end) = eye(paramSize);
        Rv(stateSize+1:end,stateSize+1:end) = 1e-2*eye(paramSize); 
        pNoiseAdaptParams.annealFactor = 0.9;  
        pNoiseAdaptParams.variance = 1e-7;
        alpha = 1e-3;
    otherwise
        fprintf('\n Error : Incorrect filter type. \n');
end

% PID values
control.Kp=diag([1000 1750 1750]);
control.Ki=diag([400 750 750]);
control.Kd=diag([100 400 400]);
control.iDQ = zeros(3,1);

% If using the kalman filters provided by the toolbox, initialize them
if strcmp(filterOptions.type,'ekf') && strcmp(filterOptions.implementation, 'toolbox')
    kalmanFilter = extendedKalmanFilter(@propagate_RRR, @measurement_RRR, x, 'HasAdditiveProcessNoise',true, 'HasAdditiveMeasurementNoise',true);
    kalmanFilter.ProcessNoise = Rv;
    kalmanFilter.MeasurementNoise = Rn;
elseif strcmp(filterOptions.type,'ukf') && strcmp(filterOptions.implementation, 'toolbox')
    kalmanFilter = unscentedKalmanFilter(@propagate_RRR, @measurement_RRR, x, 'HasAdditiveProcessNoise',true, 'HasAdditiveMeasurementNoise',true);
    kalmanFilter.ProcessNoise = Rv;
    kalmanFilter.MeasurementNoise = Rn;
    kalmanFilter.Alpha = alpha;
    kalmanFilter.Beta = beta;
    kalmanFilter.Kappa = kappa;
else
    kalmanFilter = 0;
end

% Init Covariance Annealing Parameters
dv = diag(Rv);  % grab diagonal
pNoiseAdaptParams.cov = dv(end-paramSize+1:end); % extract the part of the diagonal that relates to the 'parameter section'

end

