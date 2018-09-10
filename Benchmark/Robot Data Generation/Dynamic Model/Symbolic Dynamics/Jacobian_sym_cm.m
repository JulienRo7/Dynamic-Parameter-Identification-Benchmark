function J = Jacobian_sym_cm(JType,TR, TRm)

% This function computes row by row, the Jacobian matrix associated with 
% a given transformation. TR is given WRT the world frame !!!

[~,~,nb_joints] = size(TR);
n = length(JType);
J = sym('J', [6, nb_joints-1]);
J = J-J;

for i = 1:n 
        Z_im1 = TR(1:3,1:3,i)*[0;0;1]; 
        P = TRm(1:3,4,n)-TR(1:3,4,i);

    if(JType(i) == 2) % Revolute joint
        J(1:3,i) = cross(Z_im1,P);
        J(4:6,i) = Z_im1;
    elseif(JType(i) == 1) % Prismatic joint
        J(1:3,i) = Z_im1;
        J(4:6,i) = [0;0;0];
    else
        display('Error !')
    end
end
J = combine(simplify(J));
end