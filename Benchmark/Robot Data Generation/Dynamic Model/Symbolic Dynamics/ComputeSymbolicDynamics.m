disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp('%%%%%%%             Equations in Symbolic form               %%%%%%%');
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp(' ')

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');
disp('DH Parameters (symbolic form):');
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%');

% DH Parameters (in matrix form): [i Theta, d, a, alpha] for respectively:
% i = 1,2,3,cm1,cm2,cm3.

clear all;
close all;

% Load Kinematic and Dynamic Parameters
run('Init_Robot.m');

DHsym = [q1 l1 0 pi/2;...
    q2 0 l2 0;...
    q3 0 l3 0;...
    q1 l4 0 0;...
    q2 0 l5 0;...
    q3 0 l6 0]

%% Joints and End-effector:

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Relative Homogeneous Transformations (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

% Relative Homogeneous Transformations (symbolic form)
T0_W = eye(4);
T1_0 = Homogeneous(1,0,DHsym)
T2_1 = Homogeneous(2,1,DHsym)
T3_2 = Homogeneous(3,2,DHsym)

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Absolute Homogeneous Transformations (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

% Homogeneous transformations in the Robot frame:
T2_0 = Homogeneous(2,0,DHsym);
T3_0 = Homogeneous(3,0,DHsym);

% Homogeneous transformations in the World frame:
T1_W = T0_W*T1_0
T2_W = T0_W*T2_0
T3_W = T0_W*T3_0

% Tensor structure for Homogeneous transformations:
TR_sym(:,:,1) = sym(T0_W);
TR_sym(:,:,2) = T1_W;
TR_sym(:,:,3) = T2_W;
TR_sym(:,:,4) = T3_W;

% Optimized expression of homogeneous transformations in the World frame:
matlabFunction(T1_W,'File','Transforms/T1_Wf');
matlabFunction(T2_W,'File','Transforms/T2_Wf');
matlabFunction(T3_W,'File','Transforms/T3_Wf');


disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Error matrices for Absolute Homogeneous Transformations:')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

error_absolute_trans = zeros(4,4,7);
error_absolute_trans(:,:,1) = T1_W-(T0_W*T1_0);
error_absolute_trans(:,:,2) = T2_W-(T0_W*T1_0*T2_1);
error_absolute_trans(:,:,3) = T3_W-(T0_W*T1_0*T2_1*T3_2);

if error_absolute_trans==zeros(4,4,7)
    fprintf('\n Absolute Homogeneous Transformations seems good ! \n')
else
    fprintf('\n Error in Absolute Homogeneous Transformations !\n')
end

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Forward kinematics (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

Xef = [T3_0(1:3,4)]

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Jacobian matrix (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

J1_W=Jacobian_sym(Tr1,TR_sym)
J2_W=Jacobian_sym(Tr2,TR_sym)
J3_W=Jacobian_sym(Tr3,TR_sym)

J(:,:,1) = J1_W;
J(:,:,2) = J2_W;
J(:,:,3) = J3_W;

matlabFunction(J1_W,'File','Jacobians/J1');
matlabFunction(J2_W,'File','Jacobians/J2');
matlabFunction(J3_W,'File','Jacobians/J3');


%% Centers of Mass:

% Relative Homogeneous Transformations for each CM:
perc = 0;
h = waitbar(0,'Init');

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Relative Homogeneous Transformations for each CM (symbolic equations):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

Tcm1_0=Homogeneous_com(4,DHsym)
Tcm2_1=Homogeneous_com(5,DHsym)
Tcm3_2=Homogeneous_com(6,DHsym)

matlabFunction(Tcm1_0,'File','Transforms/Tcm1_0f');
matlabFunction(Tcm2_1,'File','Transforms/Tcm2_1f');
matlabFunction(Tcm3_2,'File','Transforms/Tcm3_2f');

perc = 5;
waitbar(perc/100, h, sprintf('%d%% done...',perc));

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Absolute Homogeneous Transformations for each CM (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

Tcm2_0 = T1_0*Tcm2_1
Tcm3_0 = T1_0*T2_1*Tcm3_2

Tcm1_W = T0_W*Tcm1_0;
Tcm2_W = T0_W*Tcm2_0;
Tcm3_W = T0_W*Tcm3_0;
Tcm1_W = Tcm1_0;
Tcm2_W = Tcm2_0;
Tcm3_W = Tcm3_0;

TR_sym_cm(:,:,1)=Tcm1_W;
TR_sym_cm(:,:,2)=Tcm2_W;
TR_sym_cm(:,:,3)=Tcm3_W;

perc = 10;
waitbar(perc/100, h, sprintf('%d%% done...',perc));

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Forward kinematics for each CM (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

Xef_cm1 = [Tcm1_0(1:3,4)]
Xef_cm2 = [Tcm2_0(1:3,4)]
Xef_cm3 = [Tcm3_0(1:3,4)]


disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Jacobian matrix for each CM (symbolic form):')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

Jcm1_W = Jacobian_sym_cm(Trcm1,TR_sym,TR_sym_cm)
Jcm2_W = Jacobian_sym_cm(Trcm2,TR_sym,TR_sym_cm)
Jcm3_W = Jacobian_sym_cm(Trcm3,TR_sym,TR_sym_cm)


matlabFunction(Jcm1_W,'File','Jacobians/Jcm1');
matlabFunction(Jcm2_W,'File','Jacobians/Jcm2');
matlabFunction(Jcm3_W,'File','Jacobians/Jcm3');


Jcm(:,:,1) = Jcm1_W;
Jcm(:,:,2) = Jcm2_W;
Jcm(:,:,3) = Jcm3_W;

disp('Computing J_dot...')
Jdcm1_W = DIFF(Jcm1_W, Q, Qp)
Jdcm2_W = DIFF(Jcm2_W, Q, Qp)
Jdcm3_W = DIFF(Jcm3_W, Q, Qp)

matlabFunction(Jdcm1_W,'File','Jacobians/Jdcm1');
matlabFunction(Jdcm2_W,'File','Jacobians/Jdcm2');
matlabFunction(Jdcm3_W,'File','Jacobians/Jdcm3');

perc = 20;
waitbar(perc/100, h, sprintf('%d%% done...',perc));

[M_ne,C_ne,M_symb,C_symb,G_symb,A,B] = Lagrange_EOM(Jcm,TR_sym_cm, m, I, gv, Q, Qp, Tau, noise, Theta, dt);

perc = 60;
waitbar(perc/100, h, sprintf('%d%% done...',perc));
matlabFunction(A,'File','Dynamics/AA');
matlabFunction(B,'File','Dynamics/B');
matlabFunction(M_ne,'File','Dynamics/M_NE');
perc = 70;
waitbar(perc/100, h, sprintf('%d%% done...',perc));
matlabFunction(C_ne,'File','Dynamics/C_NE');
perc = 80;
waitbar(perc/100, h, sprintf('%d%% done...',perc));
matlabFunction(M_symb,'File','Dynamics/M');
perc = 90;
waitbar(perc/100, h, sprintf('%d%% done...',perc));
matlabFunction(C_symb,'File','Dynamics/C');
perc = 95;
waitbar(perc/100, h, sprintf('%d%% done...',perc));
matlabFunction(G_symb,'File','Dynamics/G');
perc = 100;
waitbar(perc/100, h, sprintf('%d%% done...',perc));

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('DONE: stopping simulation...')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')