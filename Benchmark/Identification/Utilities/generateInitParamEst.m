function [Xhi_obj, Theta_obj, Initial_pts] = generateInitParamEst(N_i)

% This function returns the set of initial parameters used for
% identification

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Real parameters:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% The following values are the one used in the simulation, thus each method should return a parameter vector Theta as close as possible to Theta_obj given in this section of the code

% length
l1 = 0.60;
l2 = 0.50;
l3 = 0.55;
l4 = 0.25;
l5 = 0.25;
l6 = 0.45;

% masses
m1 = 20;
m2 = 10;
m3 = 15;

% Inertia matrix of the first link around its center of mass
I111 = 0;
I112 = 0;
I113 = 0;
I122 = 0;
I123 = 0;
I133 = 0.5;

% Inertia matrix of the second link around its center of mass
I211 = 0.33;
I212 = 0;
I213 = 0;
I222 = 0.52;
I223 = 0;
I233 = 0.52;

% Inertia matrix of the third link around its center of mass
I311 = 0.40;
I312 = 0;
I313 = 0;
I322 = 0.67;
I323 = 0;
I333 = 0.67;

% Viscous friction coefficients
Fv1 = 1;
Fv2 = 1;
Fv3 = 1;

Xhi_obj = [l1, l2, l3, l4, l5, l6, m1, m2, m3, I111, I112, I113, I122, I123, I133, I211, I212, I213, I222, I223, I233, I311, I312, I313, I322, I323, I333, Fv1, Fv2, Fv3];

% Real value of the parameter vector:
Theta_obj = ComputeTheta(Xhi_obj);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Initial parameter estimates:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

rng(0) % -> initialization of the pseudo-random numbers in order to have the same results each time the benchmark is started

% Initial_pts = [0.1*Theta_obj, ones(17,1), Theta_0_LS]; % Some special initial points
Initial_pts = []; % Some special initial points

% random initial points around the objective

randn(1, 30);
randn(1, 30);
randn(1, 30);
randn(1, 30);
randn(1, 30);
randn(1, 30);
randn(1, 30);
randn(1, 30);
randn(1, 30);

while size(Initial_pts, 2)<N_i
    sd = 0.15;
    Initial_pts = [Initial_pts, ComputeTheta(Xhi_obj + sd*randn(1, 30))];
end
end

