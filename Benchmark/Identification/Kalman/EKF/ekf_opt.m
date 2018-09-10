function [x, P, K, inov, x_kkm1, P_kkm1, P_xy, P_yy] = ekf_opt(t_km1, t_k, x_km1, u_km1, P_km1, y_k, Rv, Rn)
%#codegen

% EKF: Extended Kalman Filter

% Authors: Julien Roux, Quentin Leboutet, Alexandre Janot

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% INPUTS:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% x_km1:    state mean at time k-1
% P_km1:    state covariance at time k-1
% u_km1:    control input at time k-1
% y_k:      noisy observation at time k
% Rv:       process noise covariance matrix
% Rn:       observation noise covariance matrix

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OUTPUTS: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% x:        estimated state
% P:        estimated state covariance
% K:        Kalman Gain
% inov:     inovation signal
% x_kkm1:   predicted state mean
% P_kkm1:   predicted state covariance
% P_xy:     predicted state and observation covariance
% P_yy:     inovation covariance  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Dimensions:
Xdim = length(x_km1);           % Number of states
Vdim = size(Rv, 1);             % Number of noise states
Ydim = size(Rn, 1);             % Number of observations

% Expected prediction and measurement:
x_kkm1 = propagate_RRR_Additive(t_km1, t_k, x_km1, u_km1, zeros(Vdim,1));    
y_kkm1 = x_kkm1(4:6);                

% Calculate the Jacobian using the state at k-1:
dt = t_k-t_km1;
A = stateJacobian(dt,x_km1,u_km1,zeros(Vdim,1));
B = eye(Xdim);%noiseJacobian(x_km1);
C = [zeros(3), eye(3), zeros(3,17)];
D = eye(3);

% Compute innovation vector:
inov = y_k - y_kkm1;

% Compute covariance of the prediction:
P_kkm1 = A*P_km1*A' + B*Rv*B';

% Compute covariance of predicted observation and predicted state:
P_xy = P_kkm1*C';

% Compute covariance of predicted observation:
P_yy =   C*P_kkm1*C' + D*Rn*D';

% Kalman gain:
K = P_xy / P_yy;

% State correction:
x = x_kkm1 + K*inov;

% Covariance correction:
% P = P_kkm1 * (eye(Xdim) - K * C);
P = P_kkm1 - K*P_yy*K';

end % ekf
