function Xp=RRR_dyn_CL(X, tau, Theta)
% Return the closed loop dynamics of the RRR robots with a torque input tau
% X = [Qp;Q]

%% Dynamics
qp1=X(1);
qp2=X(2);
qp3=X(3);

q1=X(4);
q2=X(5);
q3=X(6);

Qp=[qp1; qp2; qp3];

gx = 0; % [m/s²]
gy = 0; % [m/s²]
gz = 9.81; % [m/s²]

M = M_theta(Theta, q2, q3);
C = C_theta(Theta, q2, q3, qp1, qp2, qp3);
G = G_theta(Theta, gx, gy, gz, q1, q2, q3);                         
Fv = diag(Theta(15:17));
        

%% computation of the joint acceleration

K=1e2;
Qpp = min(K*ones(3,1),max(-K*ones(3,1),M\(tau - C*Qp - G - Fv*Qp)));

Xp=[Qpp; Qp];
end