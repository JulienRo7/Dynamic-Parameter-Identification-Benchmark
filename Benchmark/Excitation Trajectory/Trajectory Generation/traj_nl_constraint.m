function [c, ceq] = traj_nl_constraint(p, r, Qmax, n_ddl, n_f)


omega = r(1);


Q  = abs(r(2:n_ddl+1)); %-> non linear constraint to ensure that joint positions stay within limits
Qp = zeros(3, 1); %-> non linear constraint to ensure that joint velocities stay within limits
Qpp= zeros(3, 1); %-> non linear constraint to ensure that joint accelerations stay within limits

for i=1:n_ddl
    for j=1:n_f
        Aij = p(2*n_f*(i-1)+j);
        Bij = p(2*n_f*(i-1)+n_f+j);
        
        Q(i) = Q(i) + 1/(j*omega)*sqrt(Aij^2+Bij^2);
        
        Qp(i) = Qp(i) + sqrt(Aij^2+Bij^2);
        
        Qpp(i) = Qpp(i) + j*sqrt(Aij^2+Bij^2);
    end
end

Qpp = Qpp*omega;



c = [Q; Qp; Qpp]-Qmax; % State - State_max <= 0

ceq =[];

end