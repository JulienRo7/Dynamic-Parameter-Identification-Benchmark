function [t, X, Qpp] = integrate_RRR_dyn_CL(X_0, Theta, t_0, t_f, N) %#codegen

% X = [Qp;Q]

t = linspace(t_0, t_f, N); % Sampling times
T = (t_f-t_0)/N;

X = zeros(numel(X_0), N); % State of the robot: joint positions and joint velocities

iDq = zeros(3, N); % integral of error in  position
Qpp = zeros(3, N);

X(:,1)=X_0;


% opts = odeset('RelTol',1e-2,'AbsTol',1e-4);

for i = 2:N
    [U, iDq] =  controler_RRR(t, X, i, iDq, T);
    
    % Xp = [Qpp;Qp]
    Xp=RRR_dyn_CL(X(:,i-1), U, Theta);
    Qpp(:,i-1) = Xp(1:3);
    
%     timer = tic;
    [~ , Y_i] = ode45(@(t, y) RRR_dyn_CL(y, U, Theta), [t(i-1) t(i)], X(:,i-1));
    X(:,i) = Y_i(end,:)';
end

%% Plotting for debug

% 
% Xd = zeros(3, N);
% for i = 1:N
%    xd = traj_gen_RRR(t(i));
%    Xd(:,i)=xd(4:6);
% end
% 
% 
% figure
% subplot(3,1,1)
% hold on
% plot(t, X(4, :));
% plot(t, Xd(1,:));
% % plot(t, Qpp(1,:));
% % plot(t, iDq(1,:));
% hold off
% legend('q1', 'qd1')
% 
% subplot(3,1,2)
% hold on
% plot(t, X(5, :));
% plot(t, Xd(2,:));
% % plot(t, Qpp(2,:));
% % plot(t, iDq(2,:));
% hold off
% legend('q2', 'qd2')
% 
% subplot(3,1,3)
% hold on
% plot(t, X(6, :));
% plot(t, Xd(3,:));
% % plot(t, Qpp(3,:));
% % plot(t, iDq(3,:));
% hold off
% legend('q3', 'qd3')

end