function Qdesired = traj_gen_RRR(u)
%% Generate a desired trajectory in the joint space for the RR robot 

t=u;

% Dt = 1;
% omega_1= 1*2*pi/Dt;
% omega_2= 2*omega_1;
% 
% if t <= Dt
%     Q = [0; pi/2; 0];
%     Qp = zeros(3,1);
%      
% elseif t>Dt && t <= 2*Dt
%     Q = [0; pi/5; pi/5];
%     Qp = zeros(3,1);
% 
% elseif t>2*Dt && t<=3*Dt
%     Q = [pi/2; pi/5; pi/5];
%     Qp = zeros(3,1);
%      
% elseif t>4*Dt && t <= 6*Dt
%     Q = [-pi/2; -pi/5; -pi/5-pi/2];
%     Qp = zeros(3,1);
% 
% elseif t > 6*Dt && t <= 10*Dt
%     Q = [-pi/2 + (t-6*Dt)*pi/8; -pi/5 + (t-6*Dt)*(pi/2+pi/5)/4; -pi/5-pi/2 + (t-6*Dt)*(pi/5+pi/2)/4];
%     Qp = [pi/8; (pi/2+pi/5)/4; (pi/5+pi/2)/4];
% else
%     Q = [0; pi/2; 0];
%     Qp = zeros(3,1);
% end



%%
% A1 = 3*pi/2;
% A2 = 4*pi/5;
% A3 = 4*pi/5;
% 
% T1 = 10;
% T2 = 5;
% T3 = 3;
% 
% f1 = 1/T1;
% f2 = 1/T2;
% f3 = 1/T3;
% 
% Q  = [ A1 * sin(2*pi*f1*t);pi/2+A2 * sin(2*pi*f2*t); A3 * sin(2*pi*f3*t)];
% Qp = [ 2*pi*f1*A1*cos(2*pi*f1*t);2*pi*f2*A2*cos(2*pi*f2*t); 2*pi*f3*A3 * cos(2*pi*f3*t)];

% Q =  [-pi/2; 0; 0];
% Qp = [0; 0; 0];

%%
p = [  1.0232
   -1.3361
    1.4907
   -0.0364
   -1.1414
   -0.0956
    0.5488
   -0.3174
   -0.7890
    0.6212
    0.1440
   -1.3454
   -0.4648
    0.4712
    1.1950
   -0.5457
    1.7466
   -0.9469
   -0.0857
    0.0472
   -0.8960
    1.8578
    1.1808
   -0.2942
   -1.8484
    1.0053
   -3.4190
    1.9982
    0.4955
   -0.4288];

f = 0.1; 
omega = 2*pi*f;

q10 = 0;
q20 = pi/2;
q30 = 0.1;
n_f = 5;

r = [omega; q10; q20; q30];

state = trajectory_gen(t, p, r, 3, n_f);

Q = state(1:3);
Qp = state(4:6);

Qdesired=[Qp;Q];
end

function Q1 = Q1_trap(t, A, T)
    if t<=T/6
        Q1 = -6*A/T*t;
    elseif t<=T/3
        Q1 = -A;
    elseif t<=2*T/3
        Q1 = -A + 6*A/T*(t-T/3);
    elseif t<=5*T/6 
        Q1 = A;
    elseif t<=T
        Q1 = A - 6*A/T*(t-5*T/6);
    else
        Q1 = 0;
    end
end

function Qp1 = Qp1_trap(t, A, T)
    if t<=T/6
        Qp1 = -6*A/T;
    elseif t<=T/3
        Qp1 = 0;
    elseif t<=2*T/3
        Qp1 = 6*A/T;
    elseif t<=5*T/6 
        Qp1 = 0;
    elseif t<=T
        Qp1 = -6*A/T;
    else
        Qp1 = 0;
    end
end