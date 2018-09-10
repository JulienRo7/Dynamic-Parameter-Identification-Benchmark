%% Trajectory optimization

%% -> Choice of a criterion
% conditionning of the W matrix for LS method.
% C = k1*cond(W) + k2/sig_min
%   - cond(W) needs to be as close as possible to 1 (it is superior to 1)
%   - sig_min needs to be as big as possible
% Thus C has to be as close as possible to 1 (it is superior to 1)
% k1 and k2 have to be chosen

%% -> Parametrization of the trajectory


%% -> Optimization
%   - computation of the criterion on the trajectory
%   - iteration
t_0 = 0;
t_f = 20;
title('Joint Postions')
l1 = legend(['$q_1$'; '$q_2$'; '$q_3$']) ;
l1.Interpreter = 'latex';

figure
plot(tps, Points(4:6,:))
title('Joint Velocities')
l2 = legend(['$\dot{q}_1$'; '$\dot{q}_2$'; '$\dot{q}_3$']) ;
l2.Interpreter = 'latex';

figure
plot(tps, Points(7:9,:))
title('Joint accelerations')
l3 = legend('$\ddot{q}_1$', '$\ddot{q}_2$', '$\ddot{q}_3$');
l3.Interpreter = 'latex';