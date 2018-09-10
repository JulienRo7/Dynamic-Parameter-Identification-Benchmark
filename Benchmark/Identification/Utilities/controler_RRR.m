function [u, iDq] = controler_RRR(t, X, i, iDq, T)

Xd = traj_gen_RRR(t(i-1));

if i == 2
    iDq(:,i-1) = T*(X(4:6, i-1)-Xd(4:6));
else
    iDq(:,i-1) = iDq(:,i-2) + T*(X(4:6, i-1)-Xd(4:6));
end


Kp=diag([1000 1750 1750]);
Ki=diag([400 750 750]);
Kd=diag([100 400 400]);

DeltaQ = X(4:6, i-1)- Xd(4:6);
DeltaQp = X(1:3, i-1)- Xd(1:3);

u = -Kp*DeltaQ - Kd*DeltaQp - Ki*iDq(:,i-1);

end