clear all 
close all
load("results_LS.mat")
load("results_LS_filtered.mat")
load("results_LS_filtered_BW.mat")
load("results_DIDIM.mat")
load("results_CLOE_Q.mat")
load("results_CLOE_Qp.mat")
load("results_EKF.mat")
load("results_UKF.mat")

%%

N_i = 10;
% N_t = results_DIDIM.N_t;
N_t = 10;

%% Computation of the error on initial points


eps_0 = zeros(1, N_i);

Theta_obj =  results_DIDIM.Theta_obj;

for i=1:N_i
    theta = results_DIDIM.Initial_points(:, i);
    eps_0(i) = norm(theta-Theta_obj);
end

eps_0

%% results for the points "close" to the objective 

% [convergence_ratio.LS, average_error.LS, std_error.LS, average_time.LS, std_time.LS, eps.LS] = statistics(results_LS.Thetas(4:10, :, :),results_LS.times(4:10, :), eps_0, Theta_obj, 6, N_t);
% [convergence_ratio.LS_f, average_error.LS_f, std_error.LS_f, average_time.LS_f, std_time.LS_f, eps.LS_f] = statistics(results_LS_f.Thetas(4:10, :, :),results_LS_f.times(4:10, :), eps_0, Theta_obj, 6, N_t);
eps.LS = zeros(N_i, N_t);

for i=1:N_i
    for j=1:N_t
        theta = reshape(results_LS.Thetas(i, j, :), 17, 1);
        eps.LS(i, j) = norm(theta-Theta_obj);
    end
end

average_error.LS = mean(mean(eps.LS(4:10,:)));
std_error.LS = std(reshape(eps.LS(4:10,:), numel(eps.LS(4:10,:)), 1));
average_time.LS = mean(mean(results_LS.times(4:10,:)));
std_time.LS = std(reshape(results_LS.times(4:10,:), numel(results_LS.times(4:10,:)), 1));


eps.LS_f = zeros(N_i, N_t);

for i=1:N_i
    for j=1:N_t
        theta = reshape(results_LS_f.Thetas(i, j, :), 17, 1);
        eps.LS_f(i, j) = norm(theta-Theta_obj);
        Theta_LS_f(:,j) = theta;
    end
end


%     LS_f_mean = mean(Theta_LS,2);
%     LS_f_std = std(Theta_LS,0,2);
    
average_error.LS_f = mean(mean(eps.LS_f(4:10,:)));
std_error.LS_f = std(reshape(eps.LS_f(4:10,:), numel(eps.LS_f(4:10,:)), 1));
average_time.LS_f = mean(mean(results_LS_f.times(4:10,:)));
std_time.LS_f = std(reshape(results_LS_f.times(4:10,:), numel(results_LS_f.times(4:10,:)), 1));


eps.LS_fBW = zeros(N_i, N_t);

for i=1:N_i
    for j=1:N_t
        theta = reshape(results_LS_fBW.Thetas(i, j, :), 17, 1);
        eps.LS_fBW(i, j) = norm(theta-Theta_obj);
        Theta_LS_fBW(:,j) = theta;
    end
end


%     LS_f_mean = mean(Theta_LS,2);
%     LS_f_std = std(Theta_LS,0,2);
    
average_error.LS_fBW = mean(mean(eps.LS_fBW(4:10,:)));
std_error.LS_fBW = std(reshape(eps.LS_fBW(4:10,:), numel(eps.LS_fBW(4:10,:)), 1));
average_time.LS_fBW = mean(mean(results_LS_fBW.times(4:10,:)));
std_time.LS_fBW = std(reshape(results_LS_fBW.times(4:10,:), numel(results_LS_fBW.times(4:10,:)), 1));


[convergence_ratio.DIDIM, average_error.DIDIM, std_error.DIDIM, average_time.DIDIM, std_time.DIDIM, mean_quality.DIDIM, std_quality.DIDIM, eps.DIDIM, quality.DIDIM] = statistics(results_DIDIM.Thetas(4:10, :, :),results_DIDIM.times(4:10, :), eps_0(4:10), Theta_obj, 6, N_t);
[convergence_ratio.CLOE_Q, average_error.CLOE_Q, std_error.CLOE_Q, average_time.CLOE_Q, std_time.CLOE_Q, mean_quality.CLOE_Q, std_quality.CLOE_Q, eps.CLOE_Q, quality.CLOE_Q] = statistics(results_CLOE_Q.Thetas(4:10, :, :),results_CLOE_Q.times(4:10, :), eps_0(4:10), Theta_obj, 6, N_t);
[convergence_ratio.CLOE_Qp, average_error.CLOE_Qp, std_error.CLOE_Qp, average_time.CLOE_Qp, std_time.CLOE_Qp, mean_quality.CLOE_Qp, std_quality.CLOE_Qp, eps.CLOE_Qp, quality.CLOE_Qp] = statistics(results_CLOE_Qp.Thetas(4:10, :, :),results_CLOE_Qp.times(4:10, :), eps_0(4:10), Theta_obj, 6, N_t);
[convergence_ratio.EKF, average_error.EKF, std_error.EKF, average_time.EKF, std_time.EKF, mean_quality.EKF, std_quality.EKF, eps.EKF, quality.EKF] = statistics(results_EKF.Thetas(4:10, :, :),results_EKF.times(4:10, :), eps_0(4:10), Theta_obj, 6, 3);
[convergence_ratio.UKF, average_error.UKF, std_error.UKF, average_time.UKF, std_time.UKF, mean_quality.UKF, std_quality.UKF, eps.UKF, quality.UKF] = statistics(results_UKF.Thetas(4:10, :, :),results_UKF.times(4:10, :), eps_0(4:10), Theta_obj, 6, N_t);



%% number of time each algo is the best

% best = zeros(N_i, 10);
% % 1 -> LS
% % 2 -> LS filtered
% % 3 -> DIDIM
% % 4 -> CLOE_Q
% 
% for i=1:N_i
%     for j = 1:3
%        
%         
%         min_val = min([eps.LS(i,j), eps.LS_f(i,j), eps.DIDIM(i,j), eps.CLOE_Q(i,j), eps.CLOE_Qp(i,j), eps.EKF(i, j), eps.UKF(i,j)]);
%         
%         if min_val == eps.LS(i,j)
%             best(i,j)=1;
%         end
%         
%         if min_val == eps.LS_f(i,j)
%             best(i,j)=2;
%         end
%         
%         if min_val == eps.DIDIM(i,j)
%             best(i,j)=3;
%         end
%         
%         if min_val == eps.CLOE_Q(i,j)
%             best(i,j)=4;
%         end
%         
%         if min_val == eps.CLOE_Qp(i,j)
%             best(i,j)=5;
%         end
%         
%         if min_val == eps.EKF(i,j)
%             best(i,j)=6;
%         end
%         
%         if min_val == eps.UKF(i,j)
%             best(i,j)=7
%         end
%         
%     end
% end
% 
% best
%% plots
convergence_ratio

close all


methods = categorical({'IDIM-LS', 'IDIM-LS filtered', 'IDIM-LS filtered BW', 'DIDIM', 'CLOE position', 'CLOE velocities', 'EKF', 'UKF'});
methods = reordercats(methods,{'IDIM-LS', 'IDIM-LS filtered','IDIM-LS filtered BW', 'DIDIM', 'CLOE position', 'CLOE velocities', 'EKF', 'UKF'});

figure
colormap parula
cmap = colormap;

averages = [average_error.LS, average_error.LS_f, average_error.LS_fBW,average_error.DIDIM, average_error.CLOE_Q, average_error.CLOE_Qp, average_error.EKF, average_error.UKF];
subplot(3,1,1)
bm = bar(methods, averages, 0.5, 'FaceColor', 'flat');
for k = 1:7
   bm.CData(k,:) =  cmap(8*k,:);
end
text(1:length(averages),averages,num2str(averages',3),'vert','bottom','horiz','center'); 
box off
yticks(1:2:17);
ylim([0 17]);
xticks([]);
grid on
grid minor
title("Average error")

std_deviations = [std_error.LS, std_error.LS_f, std_error.LS_fBW, std_error.DIDIM, std_error.CLOE_Q, std_error.CLOE_Qp, std_error.EKF, std_error.UKF];
subplot(3, 1, 2);
bs = bar(methods, std_deviations, 0.5, 'FaceColor', 'flat');
for k = 1:7
   bs.CData(k,:) =  cmap(8*k,:);
end
text(1:length(std_deviations),std_deviations,num2str(std_deviations','%.1e'),'vert','bottom','horiz','center'); 
box off
grid on
grid minor
xticks([]);
ylim([0 3.5])
title("Error Standard Deviation")

times = [average_time.LS, average_time.LS_f,average_time.LS_fBW, average_time.DIDIM, average_time.CLOE_Q, average_time.CLOE_Qp, average_time.EKF, average_time.UKF];
subplot(3,1,3)
bt = bar(methods, log10(times+1), 0.5, 'FaceColor', 'flat');
    for k = 1:7
       bt.CData(k,:) =  cmap(8*k,:);
    end
text(1:length(times),log10(times+1),num2str(times','%.1us'),'vert','bottom','horiz','center'); 
yticks(log10([1 2 10 60 600 3600]));
ylim([0 log10(20000)]);
grid on
yticklabels({'0', '1s', '10s', '1min', '10min', '1h'}); 
box off
title("Average Computation time")

% 
% 
% %% Statistics on the 3 first initial points
% 
% average_error_1.LS = mean(mean(eps.LS(1,:)));
% std_error_1.LS = std(reshape(eps.LS(1,:), numel(eps.LS(1,:)), 1));
% average_time_1.LS = mean(mean(results_LS.times(1,:)));
% std_time_1.LS = std(reshape(results_LS.times(1,:), numel(results_LS.times(1,:)), 1));
% 
% average_error_1.LS_f = mean(mean(eps.LS_f(1,:)));
% std_error_1.LS_f = std(reshape(eps.LS_f(1,:), numel(eps.LS(1,:)), 1));
% average_time_1.LS_f = mean(mean(results_LS_f.times(1,:)));
% std_time_1.LS_f = std(reshape(results_LS_f.times(1,:), numel(results_LS.times(1,:)), 1));
% 
% % [convergence_ratio_1.LS, average_error_1.LS, std_error_1.LS, average_time_1.LS, std_time_1.LS, mean_quality_1.DIDIM, std_quality_1.DIDIM, eps.LS] = statistics(results_LS.Thetas(1, :, :),results_LS.times(1, :), eps_0, Theta_obj, 1, N_t);
% % [convergence_ratio_1.LS_f, average_error_1.LS_f, std_error_1.LS_f, average_time_1.LS_f, std_time_1.LS_f, mean_quality_1.DIDIM, std_quality_1.DIDIM, eps.LS_f] = statistics(results_LS_f.Thetas(1, :, :),results_LS_f.times(1, :), eps_0, Theta_obj, 1, N_t);
% [convergence_ratio_1.DIDIM, average_error_1.DIDIM, std_error_1.DIDIM, average_time_1.DIDIM, std_time_1.DIDIM, mean_quality_1.DIDIM, std_quality_1.DIDIM, eps_1.DIDIM, quality_1.DIDIM] = statistics(results_DIDIM.Thetas(1, :, :),results_DIDIM.times(1, :), eps_0(1), Theta_obj, 1, N_t);
% [convergence_ratio_1.CLOE_Q, average_error_1.CLOE_Q, std_error_1.CLOE_Q, average_time_1.CLOE_Q, std_time_1.CLOE_Q, mean_quality_1.CLOE_Q, std_quality_1.CLOE_Q, eps_1.CLOE_Q, quality_1.CLOE_Q] = statistics(results_CLOE_Q.Thetas(1, :, :),results_CLOE_Q.times(1, :), eps_0(1), Theta_obj, 1, N_t);
% [convergence_ratio_1.CLOE_Qp, average_error_1.CLOE_Qp, std_error_1.CLOE_Qp, average_time_1.CLOE_Qp, std_time_1.CLOE_Qp, mean_quality_1.CLOE_Qp, std_quality_1.CLOE_Qp, eps_1.CLOE_Qp, quality_1.CLOE_Qp] = statistics(results_CLOE_Qp.Thetas(1, :, :),results_CLOE_Qp.times(1, :), eps_0(1), Theta_obj, 1, N_t);
% [convergence_ratio_1.EKF, average_error_1.EKF, std_error_1.EKF, average_time_1.EKF, std_time_1.EKF, mean_quality_1.EKF, std_quality_1.EKF, eps_1.EKF, quality_1.EKF] = statistics(results_EKF.Thetas(1, :, :),results_EKF.times(1, :), eps_0(1), Theta_obj, 1, 3);
% [convergence_ratio_1.UKF, average_error_1.UKF, std_error_1.UKF, average_time_1.UKF, std_time_1.UKF, mean_quality_1.UKF, std_quality_1.UKF, eps_1.UKF, quality_1.UKF] = statistics(results_UKF.Thetas(1, :, :),results_UKF.times(1, :), eps_0(1), Theta_obj, 1, N_t);
% 
% average_error_2.LS = mean(mean(eps.LS(2,:)));
% std_error_2.LS = std(reshape(eps.LS(2,:), numel(eps.LS(2,:)), 1));
% average_time_2.LS = mean(mean(results_LS.times(2,:)));
% std_time_2.LS = std(reshape(results_LS.times(2,:), numel(results_LS.times(2,:)), 1));
% 
% average_error_2.LS_f = mean(mean(eps.LS_f(2,:)));
% std_error_2.LS_f = std(reshape(eps.LS_f(2,:), numel(eps.LS_f(2,:)), 1));
% average_time_2.LS_f = mean(mean(results_LS_f.times(2,:)));
% std_time_2.LS_f = std(reshape(results_LS_f.times(2,:), numel(results_LS.times(2,:)), 1));
% 
% % [convergence_ratio_2.LS, average_error_2.LS, std_error_2.LS, average_time_2.LS, std_time_2.LS, eps.LS] = statistics(results_LS.Thetas(2, :, :),results_LS.times(2, :), eps_0, Theta_obj, 1, N_t);
% % [convergence_ratio_2.LS_f, average_error_2.LS_f, std_error_2.LS_f, average_time_2.LS_f, std_time_2.LS_f, eps.LS_f] = statistics(results_LS_f.Thetas(2, :, :),results_LS_f.times(2, :), eps_0, Theta_obj, 1, N_t);
% [convergence_ratio_2.DIDIM, average_error_2.DIDIM, std_error_2.DIDIM, average_time_2.DIDIM, std_time_2.DIDIM, mean_quality_2.DIDIM, std_quality_2.DIDIM, eps_2.DIDIM, quality_2.DIDIM] = statistics(results_DIDIM.Thetas(2, :, :),results_DIDIM.times(2, :), eps_0(2), Theta_obj, 1, N_t);
% [convergence_ratio_2.CLOE_Q, average_error_2.CLOE_Q, std_error_2.CLOE_Q, average_time_2.CLOE_Q, std_time_2.CLOE_Q, mean_quality_2.CLOE_Q, std_quality_2.CLOE_Q, eps_2.CLOE_Q, quality_2.CLOE_Q] = statistics(results_CLOE_Q.Thetas(2, :, :),results_CLOE_Q.times(2, :), eps_0(2), Theta_obj, 1, N_t);
% [convergence_ratio_2.CLOE_Qp, average_error_2.CLOE_Qp, std_error_2.CLOE_Qp, average_time_2.CLOE_Qp, std_time_2.CLOE_Qp, mean_quality_2.CLOE_Qp, std_quality_2.CLOE_Qp, eps_2.CLOE_Qp, quality_2.CLOE_Qp] = statistics(results_CLOE_Qp.Thetas(2, :, :),results_CLOE_Qp.times(2, :), eps_0(2), Theta_obj, 1, N_t);
% [convergence_ratio_2.EKF, average_error_2.EKF, std_error_2.EKF, average_time_2.EKF, std_time_2.EKF, mean_quality_2.EKF, std_quality_2.EKF, eps_2.EKF, quality_2.EKF] = statistics(results_EKF.Thetas(2, :, :),results_EKF.times(2, :), eps_0(2), Theta_obj, 1, N_t);
% [convergence_ratio_2.UKF, average_error_2.UKF, std_error_2.UKF, average_time_2.UKF, std_time_2.UKF, mean_quality_2.UKF, std_quality_2.UKF, eps_2.UKF, quality_2.UKF] = statistics(results_UKF.Thetas(2, :, :),results_UKF.times(2, :), eps_0(2), Theta_obj, 1, N_t);
% 
% 
% average_error_3.LS = mean(mean(eps.LS(3,:)));
% std_error_3.LS = std(reshape(eps.LS(3,:), numel(eps.LS(3,:)), 1));
% average_time_3.LS = mean(mean(results_LS.times(3,:)));
% std_time_3.LS = std(reshape(results_LS.times(3,:), numel(results_LS.times(3,:)), 1));
% 
% average_error_3.LS_f = mean(mean(eps.LS_f(3,:)));
% std_error_3.LS_f = std(reshape(eps.LS_f(3,:), numel(eps.LS_f(3,:)), 1));
% average_time_3.LS_f = mean(mean(results_LS_f.times(3,:)));
% std_time_3.LS_f = std(reshape(results_LS_f.times(3,:), numel(results_LS_f.times(3,:)), 1));
% 
% % [convergence_ratio_3.LS, average_error_3.LS, std_error_3.LS, average_time_3.LS, std_time_3.LS, eps.LS] = statistics(results_LS.Thetas(3, :, :),results_LS.times(3, :), eps_0, Theta_obj, 1, N_t);
% % [convergence_ratio_3.LS_f, average_error_3.LS_f, std_error_3.LS_f, average_time_3.LS_f, std_time_3.LS_f, eps.LS_f] = statistics(results_LS_f.Thetas(3, :, :),results_LS_f.times(3, :), eps_0, Theta_obj, 1, N_t);
% [convergence_ratio_3.DIDIM, average_error_3.DIDIM, std_error_3.DIDIM, average_time_3.DIDIM, std_time_3.DIDIM, mean_quality_3.DIDIM, std_quality_3.DIDIM, eps_3.DIDIM, quality_3.DIDIM] = statistics(results_DIDIM.Thetas(3, :, :),results_DIDIM.times(3, :), eps_0(3), Theta_obj, 1, N_t);
% [convergence_ratio_3.CLOE_Q, average_error_3.CLOE_Q, std_error_3.CLOE_Q, average_time_3.CLOE_Q, std_time_3.CLOE_Q, mean_quality_3.CLOE_Q, std_quality_3.CLOE_Q, eps_3.CLOE_Q, quality_3.CLOE_Q] = statistics(results_CLOE_Q.Thetas(3, :, :),results_CLOE_Q.times(3, :), eps_0(3), Theta_obj, 1, N_t);
% [convergence_ratio_3.CLOE_Qp, average_error_3.CLOE_Qp, std_error_3.CLOE_Qp, average_time_3.CLOE_Qp, std_time_3.CLOE_Qp, mean_quality_3.CLOE_Qp, std_quality_3.CLOE_Qp, eps_3.CLOE_Qp, quality_3.CLOE_Qp] = statistics(results_CLOE_Qp.Thetas(3, :, :),results_CLOE_Qp.times(3, :), eps_0(3), Theta_obj, 1, N_t);
% [convergence_ratio_3.EKF, average_error_3.EKF, std_error_3.EKF, average_time_3.EKF, std_time_3.EKF, mean_quality_3.EKF, std_quality_3.EKF, eps_3.EKF, quality_3.EKF] = statistics(results_EKF.Thetas(3, :, :),results_EKF.times(3, :), eps_0(3), Theta_obj, 1, 3);
% [convergence_ratio_3.UKF, average_error_3.UKF, std_error_3.UKF, average_time_3.UKF, std_time_3.UKF, mean_quality_3.UKF, std_quality_3.UKF, eps_3.UKF, quality_3.UKF] = statistics(results_UKF.Thetas(3, :, :),results_UKF.times(3, :), eps_0(3), Theta_obj, 1, N_t);
% 
% 
% %%  plots for the 3 first initial points
% 
% figure
% colormap parula
% cmap = colormap;
% % 
% averages = [average_error_1.LS, average_error_2.LS, average_error_3.LS;
%             average_error_1.LS_f, average_error_2.LS_f, average_error_3.LS_f;
%             average_error_1.LS_fBW, average_error_2.LS_fBW, average_error_3.LS_fBW;
%             average_error_1.DIDIM, average_error_2.DIDIM, average_error_3.DIDIM;
%             average_error_1.CLOE_Q, average_error_2.CLOE_Q, average_error_3.CLOE_Q;
%             average_error_1.CLOE_Qp, average_error_2.CLOE_Qp, average_error_3.CLOE_Qp;
%             average_error_1.EKF, average_error_2.EKF, average_error_3.EKF;
%             average_error_1.UKF, average_error_2.UKF, average_error_3.UKF];
% subplot(3,1,1)
% bm = bar(methods, averages, 0.5, 'FaceColor', 'flat');
% for j=1:3
%     for k = 1:7
%         text(k-0.3+0.225*j, averages(k, j)+1.5,num2str(averages(k, j),3),'vert','bottom','horiz','center', 'rotation', 90); 
%     end
% end
% 
% % box off
% yticks(0:2:19);
% ylim([0 19]);
% xticks([]);
% grid on
% grid minor
% title("Average error")
% legend('1st initial point', '2nd initial point', '3rd initial point')
% 
% std_deviations = [std_error_1.LS, std_error_2.LS, std_error_3.LS;
%                 std_error_1.LS_f, std_error_2.LS_f, std_error_3.LS_f;
%                 std_error_1.LS_fBW, std_error_2.LS_fBW, std_error_3.LS_fBW;
%                 std_error_1.DIDIM, std_error_2.DIDIM, std_error_3.DIDIM;
%                 std_error_1.CLOE_Q, std_error_2.CLOE_Q, std_error_3.CLOE_Q;
%                 std_error_1.CLOE_Qp, std_error_2.CLOE_Qp, std_error_3.CLOE_Qp;
%                 std_error_1.EKF, std_error_2.EKF, std_error_3.EKF;
%                 std_error_1.UKF, std_error_2.UKF, std_error_3.UKF];
% subplot(3, 1, 2);
% bs = bar(methods, std_deviations, 0.5, 'FaceColor', 'flat');
% for j=1:3
%     for k = 1:7
%         if j == 2 && k==3
%             text(k-0.3+0.225*j, std_deviations(k, j), num2str(std_deviations(k, j),'%.1e'),'vert','bottom','horiz','center');
%         else
%             text(k-0.3+0.225*j, std_deviations(k, j)+0.3, num2str(std_deviations(k, j),'%.1e'),'vert','bottom','horiz','center', 'rotation', 90);
%         end
%         
%     end
% end
% grid on
% grid minor
% xticks([]);
% % ylim([0 3])
% title("Error Standard Deviation")
% 
% 
% times =  [average_time_1.LS, average_time_2.LS, average_time_3.LS;
%             average_time_1.LS_f, average_time_2.LS_f, average_time_3.LS_f;
%             average_time_1.LS_fBW, average_time_2.LS_fBW, average_time_3.LS_fBW;
%             average_time_1.DIDIM, average_time_2.DIDIM, average_time_3.DIDIM;
%             average_time_1.CLOE_Q, average_time_2.CLOE_Q, average_time_3.CLOE_Q;
%             average_time_1.CLOE_Qp, average_time_2.CLOE_Qp, average_time_3.CLOE_Qp;
%             average_time_1.EKF, average_time_2.EKF, average_time_3.EKF;
%             average_time_1.UKF, average_time_2.UKF, average_time_3.UKF];
% subplot(3,1,3)
% bt = bar(methods, log10(times+1), 0.5, 'FaceColor', 'flat');
% for j=1:3
%     for k = 1:7
%         if j ==1 && k==4
%             text(k-0.3, log10(times(k,j)+1),num2str(times(k, j),'%.1us'),'vert','bottom','horiz','center', 'rotation', 90); 
%         else
%             text(k-0.3+0.225*j, log10(times(k,j)+1)+0.8,num2str(times(k, j),'%.1us'),'vert','bottom','horiz','center', 'rotation', 90); 
%         end
%         
%     end
% end
% yticks(log10([1 2 10 60 600 3600 36000]));
% ylim([0 log10(360000)]);
% grid on
% yticklabels({'0', '1s', '10s', '1min', '10min', '1h', '10h'}); 
% % box off
% title("Average Computation time")