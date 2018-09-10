function Error=RRR_CLOE_Qp_1(val, I, Theta,data_struct, t_0, t_f, N, optionsCLOE)
%% Error function for closed loop output error identification of the parameter vector khi



%% Computing of Ys

theta = Theta;
theta(I) = val;

% try
%     timer =tic;
%     [t_s, y_s]=ode45(@(t, y) RRR_CL_dyn(t, y, theta, data_struct, timer), [t_0 t_f], [0; pi/2; 0.1; 0; 0; 0; 0; 0; 0]);
% catch
%     options = odeset('AbsTol',1e-3,'Reltol',1e-2) 
%     fprintf('Trying lighter tolerances!\n')
%     timer =tic;
%     [t_s, y_s]=ode45(@(t, y) RRR_CL_dyn(t, y, theta, data_struct, timer), [t_0 t_f], [0; pi/2; 0.1; 0; 0; 0; 0; 0; 0], options);
% end

y_0 = [0; 0; 0; 0; pi/2; 0.1];

if strcmp(optionsCLOE.implementation,'optim')
    [~,  y_s] = integrate_RRR_dyn_CL_mex(y_0, theta, t_0, t_f, N);
elseif strcmp(optionsCLOE.implementation,'classic')
    [~,  y_s] = integrate_RRR_dyn_CL(y_0, theta, t_0, t_f, N);
else
    error("CLOE: unknown option");
end


% n = size(t_s, 1);
% t_min = t_0;
% t_max = min(t_f, t_s(n));

n = N;
t_min = t_0;
t_max=t_f;

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

% if t_max == t_f
    Error = Y-Ys;
% else
%     Error = (Y-Ys)*t_f/t_max;
% end

    
% norm(Error)


end