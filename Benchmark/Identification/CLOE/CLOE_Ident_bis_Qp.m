function [Theta, fval, it, flag, Thetas] = CLOE_Ident_bis_Qp(Theta_0, data_struct, t_0, t_f, N, optionsCLOE)

%     Theta=Theta_0;

%     options = optimoptions('fmincon','Display','iter', 'algorithm', 'sqp');
    options = optimset('Display','iter');
    
    Theta_it  = Theta_0;
    Theta_next_it = Theta_0;
    
    it = 1;
    max_it = 1;
    
    F = norm(RRR_CLOE_Qp(Theta_0, data_struct, t_0, t_f, N, optionsCLOE));
    stop_1 = 1;
    stop_2 = 1;
    S1 = 1e-4;
    S2 = 1e-3;
    
    Thetas = zeros(17, max_it+1);   
    
    n=11;
    alpha = 0.5;
%     figure
    
    while it <= max_it && stop_1 > S1 && stop_2 > S2
        Thetas(:,it)=Theta_it;
        
        for i=1:numel(Theta_it)
    %         Theta_next_it(i) = fmincon(@(Khi) norm(RRR_CLOE_Q_1_1(Khi,i,Theta_it, data_struct, t_0, t_f, N, optionsCLOE)), Theta_it(i), [], [], [], [], [], [], [], options)
            fprintf('Iteration %d, Parameter %d', it, i)
            Theta_next_it(i) = fminsearch(@(Khi) norm(RRR_CLOE_Qp_1(Khi,i,Theta_next_it, data_struct, t_0, t_f, N, optionsCLOE)), Theta_next_it(i), options);
% 
%             V = linspace(Theta_next_it(i)-alpha, Theta_next_it(i)+alpha, n);
%             error = zeros(n,1);
%             for j = 1:n
%                 Theta_bis = Theta_it;
%                 Theta_bis(i)=V(j);
%                 error(j)=norm(RRR_CLOE_Q(Theta_bis, data_struct, t_0, t_f, N, optionsCLOE));
%             end
%     %         error
%             subplot(3, 5, i)
%             hold on
%             plot(V, error);
%             plot(Theta_it(i), norm(RRR_CLOE_Q(Theta_it, data_struct, t_0, t_f, N, optionsCLOE)), 'r+');
%             Theta_bis = Theta_it;
%             Theta_bis(i)=Theta_next_it(i);
%             plot(Theta_next_it(i), norm(RRR_CLOE_Q(Theta_bis, data_struct, t_0, t_f, N, optionsCLOE)), 'g+');
%             hold off
%             drawnow
        end
        
        stop_1 = norm(Theta_next_it-Theta_it)/norm(Theta_it);
        stop_2 = abs(norm(RRR_CLOE_Qp(Theta_next_it, data_struct, t_0, t_f, N, optionsCLOE))-F);
        
        F = norm(RRR_CLOE_Qp(Theta_next_it, data_struct, t_0, t_f, N, optionsCLOE));
        Theta_it = Theta_next_it
        it = it+1;
    
    end
    Theta = Theta_next_it;
    Thetas(:,it)=Theta;

        fval = norm(RRR_CLOE_Qp(Theta, data_struct, t_0, t_f, N, optionsCLOE));
    
    if it == max_it+1
        flag = 1;
    elseif stop_1 <= S1
        flag = 2;
    elseif stop_2 <= S2
        flag = 3;
    else
        flag = 0;
    end
end