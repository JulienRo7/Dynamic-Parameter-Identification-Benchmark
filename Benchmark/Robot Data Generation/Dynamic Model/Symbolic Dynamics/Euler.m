function E = Euler(T)
% Each rotation matrix can be seen as a system of 9 equations with
% 3 unknowns Phi, Theta and Psi:

R = T(1:3,1:3);
Theta = asin(R(3,1));
Phi = atan2(R(2,1)/cos(Theta),R(1,1)/cos(Theta));
Psi = atan2(R(3,2)/cos(Theta),R(3,3)/cos(Theta));
E=[Phi;Theta;Psi];
end


