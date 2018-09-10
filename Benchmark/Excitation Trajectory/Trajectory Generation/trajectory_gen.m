function state = trajectory_gen(t, p, r, n_ddl, n_f)
%% return the state of the robot folowing the trajectory
% t is the desired time
% p is the parameter vector
% r is the fixed parameter vector
% state contains positions, velocities and acceleration of the robot in the
% joint space

omega = r(1); %-> omega is fixed and the same for each joint in order to have periodic trajectory
q10 = r(2);
q20 = r(3);
q30 = r(4);

% n_ddl = 3;
% N = 5;


Q = [q10; q20; q30];
Qp = zeros(n_ddl, 1);
Qpp = zeros(n_ddl, 1);

for i=1:n_ddl
    for j=1:n_f
        Aij = p(2*n_f*(i-1)+j);
        Bij = p(2*n_f*(i-1)+n_f+j);
        
        Cojt = cos(omega*j*t);
        Sojt = sin(omega*j*t);
        
        Q(i) = Q(i) + Aij/(omega*j)*Sojt - Bij/(omega*j)*Cojt;
        Qp(i) = Qp(i) + Aij*Cojt + Bij*Sojt;
        Qpp(i) = Qpp(i) + Bij*j*Cojt - Aij*j*Sojt;
    end
    Qpp(i) = omega*Qpp(i);
end

state = [Q; Qp; Qpp];



end