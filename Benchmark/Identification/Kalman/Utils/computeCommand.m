function [u,iDQ] = computeCommand(x, t, data_struct, control, index, k)

% This function computes the control torque 

q1=x(4);
q2=x(5);
q3=x(6);

Q=[q1; q2; q3];

qp1=x(1);
qp2=x(2);
qp3=x(3);

Qp=[qp1; qp2; qp3];

% Getting the desired position and velocity

traj = traj_gen_RRR(t);

Qd=traj(4:6);

Qdp=traj(1:3);

DeltaQ=Q-Qd;
DeltaQp=Qp-Qdp;

% Saturation for the command:
maxCommand = 500;

% Control Torque:
u = min(maxCommand*ones(3,1),max(-maxCommand*ones(3,1),-control.Kp*DeltaQ - control.Ki*control.iDQ - control.Kd*DeltaQp));

iDQ = control.iDQ+DeltaQ*(data_struct.t(index)-data_struct.t(index-k));

end