function J = Jacobian_sym(JType,TR)

% This function computes row by row, the Jacobian matrix associated with 
% a given transformation. TR is given WRT the world frame !!!

[~,~,nb_joints] = size(TR);
n = length(JType);
J = sym('J', [6, nb_joints-1]);
J = J-J;

for i = 1:n 
        Z = TR(1:3,1:3,i)*[0;0;1]; 
        P = TR(1:3,4,n+1)-TR(1:3,4,i);

    if(JType(i) == 2) % Revolute joint
        J(1:3,i) = cross(Z,P);
        J(4:6,i) = Z;
    elseif(JType(i) == 1) % Prismatic joint
        J(1:3,i) = Z;
        J(4:6,i) = [0;0;0];
    else
        display('Error !')
    end
end
J = combine(simplify(J));
end