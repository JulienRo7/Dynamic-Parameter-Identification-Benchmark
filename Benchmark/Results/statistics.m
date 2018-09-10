function [convergence_ratio, mean_error, std_error, mean_time, std_time, mean_quality, std_quality, EPS, Quality] = statistics(thetas, times, initial_eps, theta_obj, N_i, N_t)

converged_errors = [];
converged_times = [];

EPS = zeros(N_i, N_t);
Quality = ones(N_i, N_t);
convergence_ratio = 0;

for i=1:N_i
    for j=1:N_t
        theta = reshape(thetas(i, j, :), 17, 1);
        EPS(i, j) = norm(theta-theta_obj);
        
        if EPS(i,j)< initial_eps(i)
            convergence_ratio = convergence_ratio+1;
            converged_errors = [converged_errors, EPS(i,j)];
            converged_times = [converged_times, times(i,j)];
            Quality(i,j)=initial_eps(i)/EPS(i,j);
        end
    end
end

convergence_ratio = convergence_ratio/(N_i*N_t);
mean_error = mean(converged_errors);
std_error = std(converged_errors);
mean_time = mean(converged_times);
std_time = std(converged_times);
mean_quality = mean(mean(Quality));
std_quality = std(reshape(Quality, numel(Quality), 1));
