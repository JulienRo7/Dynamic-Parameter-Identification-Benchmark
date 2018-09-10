function [Y_tau] = torqueVector(Tau) %#codegen

% Building the sampled torque vector
[m,n]=size(Tau);
Y_tau = zeros(m*n, 1);

for i=1:m
    for j=1:n
        Y_tau((i-1)*n+j)=Tau(i,j);
    end
end

end
