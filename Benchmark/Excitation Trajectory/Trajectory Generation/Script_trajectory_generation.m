%% Trajectory optimization

%% -> Choice of a criterion
% conditionning of the W matrix for LS method.
% C = k1*cond(W) + k2/sig_min
%   - cond(W) needs to be as close as possible to 1 (it is superior to 1)
%   - sig_min needs to be as big as possible
% Thus C has to be as close as possible to 1 (it is superior to 1)
% k1 and k2 have to be chosen

%% -> Parametrization of the trajectory
t_0 = 0;
t_f = 10;
N = 2000;

f = 0.1; 
omega = 2*pi*f;

n_ddl = 3;
n_f = 5;

q10 = 0;
q20 = pi/2;
q30 = 0.1;

r = [omega; q10; q20; q30];

Qmax = [2*pi; pi; pi; 4*pi; 2*pi; 2*pi; 8*pi; 8*pi; 8*pi];
Qmax = 20*ones(9,1);


%% setting constraints : Parameter identification for industrial robots with a 
% constraints on the initial position 
Aeq = zeros(9, 30);
beq = zeros(9,1);

for i=1:n_ddl
   for j=1:n_f
      Aeq(i, 2*n_f*(i-1)+n_f+j)=1/(omega*j); % -> set the initial position to the desired position qi0
      beq(i)=0;
      
      Aeq(3+i, 2*n_f*(i-1)+j)=1; % -> set the initial velocities to 0
      
      Aeq(6+i, 2*n_f*(i-1)+n_f+j)=omega*j; % -> set the initial acceleration to 0
   end 
end

% Aeq
% beq


% traj_nl_constraint(rand(30,1), r, Qmax, n_ddl, n_f)
%% Trajectory  Optimization


p_min = zeros(30,1);
val_min = trajectory_criterion(p_min, r, t_0, t_f, N, n_ddl, n_f);

max_it = 1;
it= 0;

options = optimoptions('fmincon','Display','iter', 'MaxFunctionEvaluations', 10000);
while it<max_it && val_min > 5
    p_optim = fmincon(@(p) trajectory_criterion(p, r, t_0, t_f, N, n_ddl, n_f), -2 + 4*rand(30, 1), [], [], Aeq, beq, [], [], @(p) traj_nl_constraint(p, r, Qmax, n_ddl, n_f), options);
    
    val = trajectory_criterion(p_optim, r, t_0, t_f, N, n_ddl, n_f);
    if val < val_min
        p_min = p_optim
        val_min = val
    end
    
    it = it +1
end

p_min 
val_min

%% Computation of the trajectory
tps = linspace(t_0, t_f, N);
state = zeros(9,N);

for i=1:N
    state(:,i) = trajectory_gen(tps(i), p_min, r, n_ddl, n_f);
end


%% Display of the results

plot(tps, state(1:3,:))
title('Joint Postions')
l1 = legend(['$q_1$'; '$q_2$'; '$q_3$']) ;
l1.Interpreter = 'latex';

figure
plot(tps, state(4:6,:))
title('Joint Velocities')
l2 = legend(['$\dot{q}_1$'; '$\dot{q}_2$'; '$\dot{q}_3$']) ;
l2.Interpreter = 'latex';

figure
plot(tps, state(7:9,:))
title('Joint accelerations')
l3 = legend('$\ddot{q}_1$', '$\ddot{q}_2$', '$\ddot{q}_3$');
l3.Interpreter = 'latex';