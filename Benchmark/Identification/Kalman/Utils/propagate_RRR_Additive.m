function x = propagate_RRR_Additive(t_km1, t_k, x_km1, u_km1, q_km1)

opts = odeset('RelTol',1e-2,'AbsTol',1e-4);

% Here x_km1 refers to the augmented state:
Theta = x_km1(7:end);

[~, y]=ode45(@(t, y) RRR_dyn_CL(y, u_km1, Theta), [t_km1 t_k], x_km1(1:6), opts);

n=size(y, 1);

x = [y(n,:)';Theta]+q_km1;

end