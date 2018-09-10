function [M_ne,C_ne,M_l,C_l,G_l,A,B] = Lagrange_EOM(Jcm, TR_sym_cm, m, I, gv, Q, Qp, Tau, noise, Theta, dt)

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Symbolic Matrix form of Lagrangian Dynamics Equations:')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
[~,~,nb_joints] = size(TR_sym_cm);
%% Compute the symbolic eq for the Inertia Matrix:

fprintf('\n Computing M... \n');
M_l = zeros(nb_joints);
for i = 1:nb_joints
    M_l = M_l + m(i)*Jcm(1:3,:,i)'*Jcm(1:3,:,i) + Jcm(4:6,:,i)'*TR_sym_cm(1:3,1:3,i)*I(:,:,i)*TR_sym_cm(1:3,1:3,i)'*Jcm(4:6,:,i);
end
fprintf('\n Simplifying M... \n');
M_l = combine(simplify(M_l))
error = M_l'-M_l;
error = combine(simplify(error, 'Steps', 500))
if error == zeros(nb_joints,nb_joints)
    fprintf('\n First dynamic property verified!! \n The M Matrix is symmetric \n');
end
%% Compute the symbolic eq for the Centripetal and Coriolis Matrix:
C_l = sym('C_symb', [nb_joints, nb_joints]);
C_l = C_l-C_l;
fprintf('\n Computing C... \n');
%C_symb = zeros(nb_joints);
for k = 1:nb_joints
    for j = 1:nb_joints
        for i = 1:nb_joints
            Ci_symb(k,j,i) = (1/2)*(diff(M_l(k,j),Q(i)) + diff(M_l(k,i),Q(j)) - diff(M_l(i,j),Q(k)))*Qp(i);
            C_l(k,j) = C_l(k,j) + Ci_symb(k,j,i);
        end
    end
end
fprintf('\n Simplifying C... \n');
C_l = combine(simplify(C_l))

%% Compute the symbolic eq for the Gravitational Torques Vector:

% Potential Energies:

fprintf('\n Coputing Potential energv(2) ...\n');
for i=1:nb_joints
    P(i) = m(i)*gv'*TR_sym_cm(1:3,4,i);
end

% Total Potential Energv(2):

fprintf('\n Computing PT... \n');
PT = combine(simplify(sum(P)))
fprintf('\n Computing G... \n');
for i = 1:nb_joints
    tmp3(i) = diff(PT,Q(i));    % Partial derrivation of PT wrt q_i
end
G_l = tmp3';
fprintf('\n Simplifying G... \n');
G_l = combine(simplify(G_l))

%% Verification of Dynamic properties
fprintf('\nVerification of Dynamic properties...\n');
M_dot = DIFF(M_l, Q, Qp);
N = M_dot - 2*C_l;
N = simplify(N);
error_N = N'+N;
error_N = simplify(error_N);

if error_N == zeros(nb_joints,nb_joints)
    fprintf('\n Second dynamic property verified!! \n The N Matrix is skew symmetric \n');
end

disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Symbolic Matrix form of Newton-Euler Dynamics Equations:')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

M_ne = zeros(nb_joints);
C_ne = zeros(nb_joints,1);
for i = 1:nb_joints
    M_ne = M_ne + m(i)*Jcm(1:3,:,i)'*Jcm(1:3,:,i) + Jcm(4:6,:,i)'*TR_sym_cm(1:3,1:3,i)*I(:,:,i)*TR_sym_cm(1:3,1:3,i)'*Jcm(4:6,:,i);
    C_ne = C_ne + m(i)*Jcm(1:3,:,i)'*DIFF(Jcm(1:3,:,i), Q, Qp) +Jcm(4:6,:,i)'*TR_sym_cm(1:3,1:3,i)*I(:,:,i)*DIFF(TR_sym_cm(1:3,1:3,i)'*Jcm(4:6,:,i), Q, Qp) -  Jcm(4:6,:,i)'*TR_sym_cm(1:3,1:3,i)*Skew(I(:,:,i)*TR_sym_cm(1:3,1:3,i)'*Jcm(4:6,:,i)*Qp)*TR_sym_cm(1:3,1:3,i)'*Jcm(4:6,:,i);
end

M_ne = combine(simplify(M_ne))
C_ne = combine(simplify(C_ne))

% Test

fprintf('\nVerification of Equivalance between Newton-Euler and Lagrange...\n');

ErrM = simplify(M_ne - M_l)
Errh = simplify(C_ne - C_l)


disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('Extraction of the EKF jacobians:')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
disp('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')

disp('theta:')
% theta_sym = [m(3)*L(2)^2 + m(2)*L(5)^2 + m(3)*L(6)^2 + I(3,3,1) + I(2,2,2) + I(2,2,3); % Theta(1)
%     - m(3)*L(2)^2 - m(2)*L(5)^2 + I(1,1,2) - I(2,2,2); % Theta(2)
%     I(1,3,2); % Theta(3)
%     L(2)*L(6)*m(3); % Theta(4)
%     m(3)*L(2)^2 + m(2)*L(5)^2 + I(3,3,2); % Theta(5)
%     - m(3)*L(6)^2 + I(1,1,3) - I(2,2,3); % Theta(6)
%     m(3)*L(6)^2 + I(3,3,3); % Theta(7)
%     L(2)*m(3) + L(5)*m(2); % Theta(8)
%     L(6)*m(3); % Theta(9)
%     I(2,1,2); % Theta(10)
%     I(2,3,2); % Theta(11)
%     I(1,2,3); % Theta(12)
%     I(1,3,3); % Theta(13)
%     I(2,3,3); % Theta(14)
%     FV(1);
%     FV(2);
%     FV(3);
%     FC(1);
%     FC(2);
%     FC(3)]

M = [ Theta(1) + Theta(2)/2 + Theta(6)/2 - (Theta(6)*cos(2*Q(2) + 2*Q(3)))/2 + Theta(12)*sin(2*Q(2) + 2*Q(3)) - (Theta(2)*cos(2*Q(2)))/2 + Theta(10)*sin(2*Q(2)) + Theta(4)*cos(Q(3)) + Theta(4)*cos(2*Q(2) + Q(3)),...
      Theta(14)*cos(Q(2) + Q(3)) + Theta(13)*sin(Q(2) + Q(3)) + Theta(11)*cos(Q(2)) + Theta(3)*sin(Q(2)),...
      Theta(14)*cos(Q(2) + Q(3)) + Theta(13)*sin(Q(2) + Q(3));
      Theta(14)*cos(Q(2) + Q(3)) + Theta(13)*sin(Q(2) + Q(3)) + Theta(11)*cos(Q(2)) + Theta(3)*sin(Q(2)),...
      Theta(5) + 2*Theta(4)*cos(Q(3)) + Theta(7),...
      Theta(7) + Theta(4)*cos(Q(3));
      Theta(14)*cos(Q(2) + Q(3)) + Theta(13)*sin(Q(2) + Q(3)),...                
      Theta(7) + Theta(4)*cos(Q(3)),...                       
      Theta(7)]


C = [ - Qp(2)*(Theta(4)*sin(2*Q(2) + Q(3)) + (-Theta(6)*sin(2*Q(2) + 2*Q(3)))/2 - Theta(12)*cos(2*Q(2) + 2*Q(3)) - Theta(10)*cos(2*Q(2)) - (Theta(2)*sin(2*Q(2)))/2) - Qp(3)*((-Theta(6)*sin(2*Q(2) + 2*Q(3)))/2 - Theta(12)*cos(2*Q(2) + 2*Q(3)) + (Theta(4)*sin(Q(3)))/2 + (Theta(4)*sin(2*Q(2) + Q(3)))/2), ...
        Qp(3)*(Theta(13)*cos(Q(2) + Q(3)) - Theta(14)*sin(Q(2) + Q(3))) - Qp(1)*(Theta(4)*sin(2*Q(2) + Q(3))- Theta(12)*cos(2*Q(2) + 2*Q(3)) + (-Theta(6)*sin(2*Q(2) + 2*Q(3)))/2 - Theta(10)*cos(2*Q(2)) - (Theta(2)*sin(2*Q(2)))/2) + Qp(2)*(Theta(13)*cos(Q(2) + Q(3)) - Theta(14)*sin(Q(2) + Q(3)) + Theta(3)*cos(Q(2)) - Theta(11)*sin(Q(2))),...
        Qp(2)*(Theta(13)*cos(Q(2) + Q(3)) - Theta(14)*sin(Q(2) + Q(3))) - Qp(1)*((-Theta(6)*sin(2*Q(2) + 2*Q(3)))/2 - Theta(12)*cos(2*Q(2) + 2*Q(3)) + (Theta(4)*sin(Q(3)))/2 + (Theta(4)*sin(2*Q(2) + Q(3)))/2) + Qp(3)*(Theta(13)*cos(Q(2) + Q(3)) - Theta(14)*sin(Q(2) + Q(3)));
        Qp(1)*(Theta(4)*sin(2*Q(2) + Q(3)) + (-Theta(6)*sin(2*Q(2) + 2*Q(3)))/2 - Theta(12)*cos(2*Q(2) + 2*Q(3)) - Theta(10)*cos(2*Q(2)) - (Theta(2)*sin(2*Q(2)))/2),...
      - Theta(4)*Qp(3)*sin(Q(3)),...
      - Theta(4)*sin(Q(3))*(Qp(2) + Qp(3));
        Qp(1)*((-Theta(6)*sin(2*Q(2) + 2*Q(3)))/2 - Theta(12)*cos(2*Q(2) + 2*Q(3)) + (Theta(4)*sin(Q(3)))/2 + (Theta(4)*sin(2*Q(2) + Q(3)))/2),...
        Theta(4)*Qp(2)*sin(Q(3)),...
        0]

G = [                                                                                                               (gv(2)*cos(Q(1)) - gv(1)*sin(Q(1)))*(Theta(8)*cos(Q(2)) + Theta(9)*cos(Q(2) + Q(3)));
        gv(3)*Theta(9)*cos(Q(2) + Q(3)) + gv(3)*Theta(8)*cos(Q(2)) - gv(1)*Theta(9)*cos(Q(1))*sin(Q(2) + Q(3)) - gv(1)*Theta(8)*cos(Q(1))*sin(Q(2)) - gv(2)*Theta(9)*sin(Q(1))*sin(Q(2) + Q(3)) - gv(2)*Theta(8)*sin(Q(1))*sin(Q(2));
                                                                                                         -Theta(9)*(gv(1)*sin(Q(2) + Q(3))*cos(Q(1)) - gv(3)*cos(Q(2) + Q(3)) + gv(2)*sin(Q(2) + Q(3))*sin(Q(1)))]
 

                                     
FV = diag(Theta(15:17));
% FC = diag(Theta(18:20));

disp('State vector:')
x = [Qp;Q;Theta]
[dimx,~] = size(x);

disp('State function:')
% f = simplify([M\(Tau - C*Qp - G - FV*Qp - FC*sign(Qp)); Qp; Theta] + noise)
f = x+[M\(Tau - C*Qp - G - FV*Qp); Qp; sym(zeros(17,1))]*dt + noise

[dimf,~] = size(f);

disp('State Jacobian:')
% for i = 1:dimx
%     for j = 1:dimf
%         testA(i,j) = diff(f(j),x(i));
%     end
% end

A=jacobian(f,x)
% ErrorA = simplify(A - testA)

dis('Noise Jacobian:')
% for i = 1:dimf
%     for j = 1:dimx
%         testB(i,j) = diff(f(i),noise(j));
%     end
% end

B=jacobian(f,noise)
% ErrorB = simplify(B - testB)

end