function Error=RRR_CLOE_Qp(Theta, data_struct, t_0, t_f, N, optionsCLOE)
%% Error function for closed loop output error identification of the parameter vector khi
% Khi = [l1; l2; m1; m2; I133; I233; g]
% optional: Khi can be extended with Beta1 and Beta2
% global data_struct %cpt

% Need to decide what is Y: Y=[q(t0); q(t1); ...; q(ti); ...; q(tn)] or
% Y=[q(t0); qp(t0); q(t1); qp(t2); ...; q(ti); qp(ti); ...; q(tn); qp(tn)]
% Have to try both...
% But first things first let's use the fisrt one first xD
% cpt=cpt+1


%% Computing of Ys
% Ys is computed using the model with the parameters of Khi

% Question: do I compute the inertia matrix inside the dynamics or do I
% pass it as a mass matrix to the ode function?
% -> for now it will be computed in the dynamics function

% For closed loop identification y is extended with the integral of the
% error
% timer = tic;
% [t_s, y_s]=ode45(@(t, y) RRR_CL_dyn(t, y, Theta, data_struct, timer), [t_0 t_f], [0; pi/2; 0.1; 0; 0; 0; 0; 0; 0]);

X_0 = [0; 0; 0; 0; pi/2; 0.1];

if strcmp(optionsCLOE.implementation,'optim')
    [~,  y_s] = integrate_RRR_dyn_CL_mex(X_0, Theta, t_0, t_f, N);
elseif strcmp(optionsCLOE.implementation,'classic')
    [~,  y_s] = integrate_RRR_dyn_CL(X_0, Theta, t_0, t_f, N);
else
    error("CLOE: unknown option");
end

% n = size(t_s, 1);
% t_min = t_0;
% t_max = min(t_f, t_s(n));

t_min = t_0;
t_max = t_f;

%% Sampling of Y and Ys to have the measures at the time point
t=linspace(t_min, t_max, N);

Y=zeros(3*N, 1);
Ys=zeros(3*N,1);

for k=1:N
    % fullfilment of Y
    
    i=find(data_struct.t==t(k), 1, 'first');
    
    if isempty(i)
        %if the time step is not in the list of sampled data then a linear
        %interpolation is done
        i=find(data_struct.t<=t(k), 1, 'last');
        j=find(data_struct.t>t(k), 1, 'first');
        
        Y(3*k-2:3*k)=[data_struct.qp1(i)+(data_struct.qp1(j)-data_struct.qp1(i))/(data_struct.t(j)-data_struct.t(i))*(t(k)-data_struct.t(i));
            data_struct.qp2(i)+(data_struct.qp2(j)-data_struct.qp2(i))/(data_struct.t(j)-data_struct.t(i))*(t(k)-data_struct.t(i));
            data_struct.qp3(i)+(data_struct.qp3(j)-data_struct.qp3(i))/(data_struct.t(j)-data_struct.t(i))*(t(k)-data_struct.t(i))];
    else
        % else the right value is taken
        Y(3*k-2:3*k)=[data_struct.qp1(i);
            data_struct.qp2(i);
            data_struct.qp3(i)];
    end
    
    % fullfilment of Ys
    %     i=find(t_s==t(k), 1, 'first');
    %
    %     if isempty(i)
    %         %if the time step is not in the list of sampled data then a linear
    %         %interpolation is done
    %         i=find(t_s<=t(k), 1, 'last');
    %         j=find(t_s>t(k), 1, 'first');
    %
    %         Ys(3*k-2:3*k)=[y_s(i,4)+(y_s(j,4)-y_s(i,4))/(t_s(j)-t_s(i))*(t(k)-t_s(i));
    %                        y_s(i,5)+(y_s(j,5)-y_s(i,5))/(t_s(j)-t_s(i))*(t(k)-t_s(i));
    %                        y_s(i,6)+(y_s(j,6)-y_s(i,6))/(t_s(j)-t_s(i))*(t(k)-t_s(i))];
    %     else
    %         % else the right value is taken
    Ys(3*k-2:3*k)=[y_s(1,k);
        y_s(2,k);
        y_s(3,k)];
    %     end
    
end


if t_max == t_f
    Error = Y-Ys;
else
    Error = (Y-Ys)*t_f/t_max;
end

% norm(Error)


end