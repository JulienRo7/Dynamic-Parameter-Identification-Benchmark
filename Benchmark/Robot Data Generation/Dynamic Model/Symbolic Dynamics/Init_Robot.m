%% Switch Symbolic/Numerical:

Symb = 1; % 1 to Trigger symbolic equations, 0 to launch the simulation

%     Weitght = diag([1,1,1,0,0,0]);
%     Weitght = diag([1,1,1,0.1,0.1,0.1]);
%     Weitght = diag([0.1,0.1,0.1,1,1,1]);
%     Weitght = diag([1,1,1,1,1,1]);
%     Weitght = diag([0,0,0,1,1,1]);

%% Transformations (joints and center of mass):

Tr1 = [2]; % [Rotation]
Tr2 = [2 2]; % [Rotation, Rotation]
Tr3 = [2 2 2]; % [Rotation, Rotation, Rotation]
Trcm1 = [2]; % [Rotation]
Trcm2 = [2 2]; % [Rotation, Rotation]
Trcm3 = [2 2 2]; % [Rotation, Rotation, Rotation]

% Number of joints

nb_joints = 3;
if Symb == 0
    
    % Joint limits
    
    limU = [pi;pi;pi];
    
    limL = [-pi;-pi;-pi];
    
    %% Kinematic Parameters:
    
    l1 = 0.3;   % [m]
    l2 = 0.3;   % [m]
    l3 = 0.3;   % [m]
    l4 = 0.3/2;   % [m]
    l5 = 0.3/2;   % [m]
    l6 = 0.3/2;   % [m]
    
    %% Dynamic Parameters:
    
    % Mass:
    m1 = 1;     % [kg]
    m2 = 1;   % [kg]
    m3 = 1;   % [kg]
    
    % Inertia:
    I111 = 1;
    I112 = 1;
    I113 = 1;
    I122 = 1;
    I123 = 1;
    I133 = 1;
    
    I211 = 1;
    I212 = 1;
    I213 = 1;
    I222 = 1;
    I223 = 1;
    I233 = 1;
    
    I311 = 1;
    I312 = 1;
    I313 = 1;
    I322 = 1;
    I323 = 1;
    I333 = 1;
    
    I(:,:,1) = [I111 I112 I113; ...
        I112 I122 I123; ...
        I113 I123 I133];
    
    I(:,:,2) = I(:,:,1);
    I(:,:,3) = I(:,:,1);
    
    
    %Gravity:
    gx = 0; % [m/s²]
    gy = 0; % [m/s²]
    gz = 0*9.81; % [m/s²]
    %Viscous Friction Matrix:
    Beta(1,1) = 0.01;
    Beta(2,2) = 0.01;
    Beta(3,3) = 0.01;
    
elseif Symb == 1
    
    % Symbolic parameters:
    
    dt = sym('dt','real');
    
    tau1 = sym('tau1','real');
    tau2 = sym('tau2','real');
    tau3 = sym('tau3','real');
    
    Tau = [tau1; tau2; tau3];
    
    q1 = sym('q1','real');
    q2 = sym('q2','real');
    q3 = sym('q3','real');
    
    Q = [q1; q2; q3];
    
    qp1 = sym('qp1','real');
    qp2 = sym('qp2','real');
    qp3 = sym('qp3','real');
    
    Qp = [qp1; qp2; qp3];
    
    qpp1 = sym('qpp1','real');
    qpp2 = sym('qpp2','real');
    qpp3 = sym('qpp3','real');
    
    Qpp = [qpp1; qpp2; qpp3];
    
    l1 = sym('l1','real');
    l2 = sym('l2','real');
    l3 = sym('l3','real');
    l4 = sym('l4','real');
    l5 = sym('l5','real');
    l6 = sym('l6','real');
    m1 = sym('m1','real');
    m2 = sym('m2','real');
    m3 = sym('m3','real');
    
    m = [m1; m2; m3];
    
    L = [l1; l2; l3; l4; l5; l6];
    
    gx = sym('gx','real');
    gy = sym('gy','real');
    gz = sym('gz','real');
    gv=[gx;gy;gz];
    
    Beta1 = sym('Beta1','real');
    Beta2 = sym('Beta2','real');
    Beta3 = sym('Beta3','real');
    Beta = diag([Beta1 Beta2 Beta3]);
    
    I111 = sym('I111','real');
    I112 = sym('I112','real');
    I113 = sym('I113','real');
    I122 = sym('I122','real');
    I123 = sym('I123','real');
    I133 = sym('I133','real');
    
    I211 = sym('I211','real');
    I212 = sym('I212','real');
    I213 = sym('I213','real');
    I222 = sym('I222','real');
    I223 = sym('I223','real');
    I233 = sym('I233','real');
    
    I311 = sym('I311','real');
    I312 = sym('I312','real');
    I313 = sym('I313','real');
    I322 = sym('I322','real');
    I323 = sym('I323','real');
    I333 = sym('I333','real');
    
    Fv1 = sym('Fv1','real');
    Fv2 = sym('Fv2','real');
    Fv3 = sym('Fv3','real');
    
    FV = [Fv1;Fv2;Fv3];
    
    Fc1 = sym('Fc1','real');
    Fc2 = sym('Fc2','real');
    Fc3 = sym('Fc3','real');
    
    FC = [Fc1;Fc2;Fc3];
    
    
    I(:,:,1) = [I111 I112 I113; ...
        I112 I122 I123; ...
        I113 I123 I133];
    
    I(:,:,2) = [I211 I212 I213; ...
        I212 I222 I223; ...
        I213 I223 I233];
    
    I(:,:,3) = [I311 I312 I313; ...
        I312 I322 I323; ...
        I313 I323 I333];
    
    n1 = sym('n1','real');
    n2 = sym('n2','real');
    n3 = sym('n3','real');
    n4 = sym('n4','real');
    n5 = sym('n5','real');
    n6 = sym('n6','real');
    n7 = sym('n7','real');
    n8 = sym('n8','real');
    n9 = sym('n9','real');
    n10 = sym('n10','real');
    n11 = sym('n11','real');
    n12 = sym('n12','real');
    n13 = sym('n13','real');
    n14 = sym('n14','real');
    n15 = sym('n15','real');
    n16 = sym('n16','real');
    n17 = sym('n17','real');
    n18 = sym('n18','real');
    n19 = sym('n19','real');
    n20 = sym('n20','real');
    n21 = sym('n21','real');
    n22 = sym('n22','real');
    n23 = sym('n23','real');
    n24 = sym('n24','real');
    n25 = sym('n25','real');
    n26 = sym('n26','real');
    
%     noise = [n1;n2;n3;n4;n5;n6;n7;n8;n9;n10;n11;n12;n13;n14;n15;n16;n17;n18;n19;n20;n21;n22;n23;n24;n25;n26];
    noise = [n1;n2;n3;n4;n5;n6;n7;n8;n9;n10;n11;n12;n13;n14;n15;n16;n17;n18;n19;n20;n21;n22;n23];
    
    t1 = sym('t1','real');
    t2 = sym('t2','real');
    t3 = sym('t3','real');
    t4 = sym('t4','real');
    t5 = sym('t5','real');
    t6 = sym('t6','real');
    t7 = sym('t7','real');
    t8 = sym('t8','real');
    t9 = sym('t9','real');
    t10 = sym('t10','real');
    t11 = sym('t11','real');
    t12 = sym('t12','real');
    t13 = sym('t13','real');
    t14 = sym('t14','real');
    t15 = sym('t15','real');
    t16 = sym('t16','real');
    t17 = sym('t17','real');
    t18 = sym('t18','real');
    t19 = sym('t19','real');
    t20 = sym('t20','real');
    
%     Theta = [t1;t2;t3;t4;t5;t6;t7;t8;t9;t10;t11;t12;t13;t14;t15;t16;t17;t18;t19;t20];
    Theta = [t1;t2;t3;t4;t5;t6;t7;t8;t9;t10;t11;t12;t13;t14;t15;t16;t17];
    
else
    
    % Error Message:
    fprintf('\n Error : Incorrect value for the parameter "Symb".\n');
    fprintf('\n Must be either 0 (for numerical simulation) or 1 (for symbolic computation of robot equations)\n');
    fprintf('Stopping simulation...')
    set_param('Robot_Simulator','SimulationCommand','stop'); % Stop the simulation.
    
end
