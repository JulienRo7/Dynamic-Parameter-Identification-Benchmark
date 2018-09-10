function [out] = Forward_Dynamics(u)
%% Computes the dynamics of the 3DoF robot

t=u(1);

q1=u(2);
q2=u(3);
q3=u(4);

qp1=u(5);
qp2=u(6);
qp3=u(7);

l1=u(8);
l2=u(9);
l3=u(10);
l4=u(11);
l5=u(12);
l6=u(13);

m1=u(14);
m2=u(15);
m3=u(16);

I111=u(17);
I112=u(18);
I113=u(19);
I122=u(20);
I123=u(21);
I133=u(22);

I211=u(23);
I212=u(24);
I213=u(25);
I222=u(26);
I223=u(27);
I233=u(28);

I311=u(29);
I312=u(30);
I313=u(31);
I322=u(32);
I323=u(33);
I333=u(34);

Fv = diag([u(35); u(36); u(37)]); %-> viscous friction
Fc = diag([u(38); u(39); u(40)]); %-> coulomb friction

tau =  [u(41); u(42); u(43)];


gx = 0;
gy = 0;
gz = 9.81; 
% minus needed because there was a mistake in the simbolic computation at
% the time but too much trouble to correct the matrix below will be right
% the next time

Qp=[qp1 qp2 qp3]';

% global det_M
% if t==0
%     det_M=[];
% end

                                          
%  M = [ I133 + I211/2 + I222/2 + I311/2 + I322/2 - (I311*cos(2*q2 + 2*q3))/2 + (I322*cos(2*q2 + 2*q3))/2 + I312*sin(2*q2 + 2*q3) + (l2^2*m3)/2 + (l5^2*m2)/2 + (l6^2*m3)/2 - (I211*cos(2*q2))/2 + (I222*cos(2*q2))/2 + I212*sin(2*q2) + (l2^2*m3*cos(2*q2))/2 + (l5^2*m2*cos(2*q2))/2 + (l6^2*m3*cos(2*q2 + 2*q3))/2 + l2*l6*m3*cos(q3) + l2*l6*m3*cos(2*q2 + q3), I323*cos(q2 + q3) + I313*sin(q2 + q3) + I223*cos(q2) + I213*sin(q2), I323*cos(q2 + q3) + I313*sin(q2 + q3);
%         I323*cos(q2 + q3) + I313*sin(q2 + q3) + I223*cos(q2) + I213*sin(q2),      m3*l2^2 + 2*m3*cos(q3)*l2*l6 + m2*l5^2 + m3*l6^2 + I233 + I333,     m3*l6^2 + l2*m3*cos(q3)*l6 + I333;
%         I323*cos(q2 + q3) + I313*sin(q2 + q3),                                   m3*l6^2 + l2*m3*cos(q3)*l6 + I333,                        m3*l6^2 + I333];
%                                
% C = [ - qp2*((m3*sin(2*q2)*l2^2)/2 + m3*sin(2*q2 + q3)*l2*l6 + (m2*sin(2*q2)*l5^2)/2 + (m3*sin(2*q2 + 2*q3)*l6^2)/2 - I312*cos(2*q2 + 2*q3) - (I311*sin(2*q2 + 2*q3))/2 + (I322*sin(2*q2 + 2*q3))/2 - I212*cos(2*q2) - (I211*sin(2*q2))/2 + (I222*sin(2*q2))/2) - qp3*((I322*sin(2*q2 + 2*q3))/2 - (I311*sin(2*q2 + 2*q3))/2 - I312*cos(2*q2 + 2*q3) + (l6^2*m3*sin(2*q2 + 2*q3))/2 + (l2*l6*m3*sin(q3))/2 + (l2*l6*m3*sin(2*q2 + q3))/2), qp3*(I313*cos(q2 + q3) - I323*sin(q2 + q3)) - qp1*((m3*sin(2*q2)*l2^2)/2 + m3*sin(2*q2 + q3)*l2*l6 + (m2*sin(2*q2)*l5^2)/2 + (m3*sin(2*q2 + 2*q3)*l6^2)/2 - I312*cos(2*q2 + 2*q3) - (I311*sin(2*q2 + 2*q3))/2 + (I322*sin(2*q2 + 2*q3))/2 - I212*cos(2*q2) - (I211*sin(2*q2))/2 + (I222*sin(2*q2))/2) + qp2*(I313*cos(q2 + q3) - I323*sin(q2 + q3) + I213*cos(q2) - I223*sin(q2)), qp2*(I313*cos(q2 + q3) - I323*sin(q2 + q3)) - qp1*((I322*sin(2*q2 + 2*q3))/2 - (I311*sin(2*q2 + 2*q3))/2 - I312*cos(2*q2 + 2*q3) + (l6^2*m3*sin(2*q2 + 2*q3))/2 + (l2*l6*m3*sin(q3))/2 + (l2*l6*m3*sin(2*q2 + q3))/2) + qp3*(I313*cos(q2 + q3) - I323*sin(q2 + q3));
%         qp1*((m3*sin(2*q2)*l2^2)/2 + m3*sin(2*q2 + q3)*l2*l6 + (m2*sin(2*q2)*l5^2)/2 + (m3*sin(2*q2 + 2*q3)*l6^2)/2 - I312*cos(2*q2 + 2*q3) - (I311*sin(2*q2 + 2*q3))/2 + (I322*sin(2*q2 + 2*q3))/2 - I212*cos(2*q2) - (I211*sin(2*q2))/2 + (I222*sin(2*q2))/2),                                                                                                                                                                                                                                                                                                                                                             -l2*l6*m3*qp3*sin(q3),                                                                                                                                                                                                                                       -l2*l6*m3*sin(q3)*(qp2 + qp3);
%         qp1*((I322*sin(2*q2 + 2*q3))/2 - (I311*sin(2*q2 + 2*q3))/2 - I312*cos(2*q2 + 2*q3) + (l6^2*m3*sin(2*q2 + 2*q3))/2 + (l2*l6*m3*sin(q3))/2 + (l2*l6*m3*sin(2*q2 + q3))/2),                                                                                                                                                                                                                                                                                                                                                              l2*l6*m3*qp2*sin(q3),                                                                                                                                                                                                                                                                   0];
%  
% G = [                                                                                                                              (gy*cos(q1) - gx*sin(q1))*(l2*m3*cos(q2) + l5*m2*cos(q2) + l6*m3*cos(q2 + q3));
%       gz*m3*(l6*cos(q2 + q3) + l2*cos(q2)) + gz*l5*m2*cos(q2) - gx*m3*cos(q1)*(l6*sin(q2 + q3) + l2*sin(q2)) - gy*m3*sin(q1)*(l6*sin(q2 + q3) + l2*sin(q2)) - gx*l5*m2*cos(q1)*sin(q2) - gy*l5*m2*sin(q1)*sin(q2);
%                                                                                                                                      -l6*m3*(gx*sin(q2 + q3)*cos(q1) - gz*cos(q2 + q3) + gy*sin(q2 + q3)*sin(q1))];                                         

M = Inertia_M(I133,I211,I212,I213,I222,I223,I233,I311,I312,I313,I322,I323,I333,l2,l5,l6,m2,m3,q2,q3);

C = CorCen_C(I211,I212,I213,I222,I223,I311,I312,I313,I322,I323,l2,l5,l6,m2,m3,q2,q3,qp1,qp2,qp3);

G = Gravity_G(gx,gy,gz,l2,l5,l6,m2,m3,q1,q2,q3);



% beta=zeros(3,3);
% 
% Cor = C*Qp;
    
% tau = G;

Qpp = M\(tau - C*Qp - G - Fv*Qp - Fc*sign(Qp));

%% Computation of the mecanical energy

Ec =  1/2*Qp'*M*Qp;

Ep = l4*gz*m2*sin(q2)+(l2*sin(q2)+l6*sin(q2+q3))*m3*gz;

Em = Ec+Ep;

out = [Qpp; Ec; Ep; Ec+Ep];

%% dynamics of the end effector
% This part doesn't work because det(J*J')=0 so JTmp can't be computed

% Xpp=zeros(3,1);
% 
% J=[ -sin(q1)*(l3*cos(q2 + q3) + l2*cos(q2)), -cos(q1)*(l3*sin(q2 + q3) + l2*sin(q2)), -l3*sin(q2 + q3)*cos(q1);
%     cos(q1)*(l3*cos(q2 + q3) + l2*cos(q2)), -sin(q1)*(l3*sin(q2 + q3) + l2*sin(q2)), -l3*sin(q2 + q3)*sin(q1);
%     0,            l3*cos(q2 + q3) + l2*cos(q2),          l3*cos(q2 + q3);
%     0,                                 sin(q1),                  sin(q1);
%     0,                                -cos(q1),                 -cos(q1);
%     1,                                       0,                        0];
% 
% Jp=[   qp2*sin(q1)*(l3*sin(q2 + q3) + l2*sin(q2)) - qp1*cos(q1)*(l3*cos(q2 + q3) + l2*cos(q2)) + l3*qp3*sin(q2 + q3)*sin(q1),   qp1*sin(q1)*(l3*sin(q2 + q3) + l2*sin(q2)) - qp2*cos(q1)*(l3*cos(q2 + q3) + l2*cos(q2)) - l3*qp3*cos(q2 + q3)*cos(q1),   l3*qp1*sin(q2 + q3)*sin(q1) - l3*qp3*cos(q2 + q3)*cos(q1) - l3*qp2*cos(q2 + q3)*cos(q1);
%        - qp1*sin(q1)*(l3*cos(q2 + q3) + l2*cos(q2)) - qp2*cos(q1)*(l3*sin(q2 + q3) + l2*sin(q2)) - l3*qp3*sin(q2 + q3)*cos(q1), - qp2*sin(q1)*(l3*cos(q2 + q3) + l2*cos(q2)) - qp1*cos(q1)*(l3*sin(q2 + q3) + l2*sin(q2)) - l3*qp3*cos(q2 + q3)*sin(q1), - l3*qp1*sin(q2 + q3)*cos(q1) - l3*qp2*cos(q2 + q3)*sin(q1) - l3*qp3*cos(q2 + q3)*sin(q1);
%        0,                                                              - qp2*(l3*sin(q2 + q3) + l2*sin(q2)) - l3*qp3*sin(q2 + q3),                                                              -l3*sin(q2 + q3)*(qp2 + qp3);
%        0,                                                                                                             qp1*cos(q1),                                                                               qp1*cos(q1);
%        0,                                                                                                             qp1*sin(q1),                                                                               qp1*sin(q1);
%        0,                                                                                                                       0,                                                                                         0];
% 
% Jmp =[    -(2*sin(q1)*(l3*cos(q2 + q3) + l2*cos(q2)))/(l2^2*cos(2*q2) + l3^2*cos(2*q2 + 2*q3) + l2^2 + l3^2 + 2*l2*l3*cos(q3) + 2*l2*l3*cos(2*q2 + q3) + 2),     (2*cos(q1)*(l3*cos(q2 + q3) + l2*cos(q2)))/(l2^2*cos(2*q2) + l3^2*cos(2*q2 + 2*q3) + l2^2 + l3^2 + 2*l2*l3*cos(q3) + 2*l2*l3*cos(2*q2 + q3) + 2),                                                                                                                                          0,                                                            0,                                                             0, 1/((l2^2*cos(2*q2))/2 + (l3^2*cos(2*q2 + 2*q3))/2 + l2^2/2 + l3^2/2 + l2*l3*cos(q3) + l2*l3*cos(2*q2 + q3) + 1);
%           -(cos(q1)*(sin(q2) + (l3^2*sin(q2))/2 - (l3^2*sin(q2 + 2*q3))/2))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)),                                                   -(sin(q1)*(sin(q2) + (l3^2*sin(q2))/2 - (l3^2*sin(q2 + 2*q3))/2))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)),                                                          (2*cos(q2) - l3^2*cos(q2 + 2*q3) + l3^2*cos(q2))/(l2*(l3^2 - l3^2*cos(2*q3) + 2)),       -(l3*cos(q3)*sin(q1))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)),         (l3*cos(q1)*cos(q3))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)),                                                                                                               0;
%           -(cos(q1)*(l3^2*cos(q3)^2*sin(q2) - l3^2*sin(q2) - sin(q2) + l3^2*cos(q2)*cos(q3)*sin(q3) + l2*l3*cos(q2)*sin(q3)))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)), -(sin(q1)*(l3^2*cos(q3)^2*sin(q2) - l3^2*sin(q2) - sin(q2) + l3^2*cos(q2)*cos(q3)*sin(q3) + l2*l3*cos(q2)*sin(q3)))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)), -(cos(q2) + l3^2*cos(q2) - l3^2*cos(q2)*cos(q3)^2 + l2*l3*sin(q2)*sin(q3) + l3^2*cos(q3)*sin(q2)*sin(q3))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)), (sin(q1)*(l2 + l3*cos(q3)))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)), -(cos(q1)*(l2 + l3*cos(q3)))/(l2*(l3^2 - l3^2*cos(q3)^2 + 1)),                                                                                                               0];
% 
% JTmp = J'*inv(J*J')
% 
% Xp = J*Qp;
% 
% Mx=JTmp*M*Jmp;
% 
% Cx=JTmp*C*Jmp - JTmp*M*Jmp*Jp*Jmp;
% 
% Gx=JTmp*G;
% 
% Xpp = Mx\(F - Cx*Xp - Gx);
end

