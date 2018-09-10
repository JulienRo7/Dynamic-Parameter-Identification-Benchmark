function tau = RRR_control(u)
%% Generate the joint torque in order for the RR robot to follow the desired trajectory

DQ = [u(1); u(2); u(3)];
Kp = diag([u(4); u(5); u(6)]);

iDQ = [u(7); u(8); u(9)];
Ki = diag([u(10); u(11); u(12)]);

DQp = [u(13); u(14); u(15)];
Kd = diag([u(16); u(17); u(18)]);

tau =  -Kp*DQ - Ki*iDQ - Kd*DQp;
% tau = [0; 0; 0];


end
