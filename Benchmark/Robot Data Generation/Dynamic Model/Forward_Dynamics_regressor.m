function [out] = Forward_Dynamics_regressor(u)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here

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

beta = diag([u(35); u(36); u(37)]);

tau =  [u(38); u(39); u(40)];

g=9.81; 

Qp=[qp1 qp2 qp3]';

Theta = [ m3*l2^2 + m2*l5^2 + m3*l6^2 + I133 + I222 + I322;
                         - m3*l2^2 - m2*l5^2 + I211 - I222;
                                                      I213;
                                                  l2*l6*m3;
                                  m3*l2^2 + m2*l5^2 + I233;
                                   - m3*l6^2 + I311 - I322;
                                            m3*l6^2 + I333;
                                             l2*m3 + l5*m2;
                                                     l6*m3;
                                                      I212;
                                                      I223;
                                                      I312;
                                                      I313;
                                                      I323];

% Theta = [8.8156
%    -5.4098
%     0.3547
%     3.3241
%     5.4414
%    -3.2529
%     4.0025
%     9.7948
%     6.8369
%     0.0411
%    -0.0747
%     0.1160
%     0.1111
%     0.0110];

M = [ Theta(1) + Theta(2)/2 + Theta(6)/2 - (Theta(6)*cos(2*q2 + 2*q3))/2 + Theta(12)*sin(2*q2 + 2*q3) - (Theta(2)*cos(2*q2))/2 + Theta(10)*sin(2*q2) + Theta(4)*cos(q3) + Theta(4)*cos(2*q2 + q3),...
      Theta(14)*cos(q2 + q3) + Theta(13)*sin(q2 + q3) + Theta(11)*cos(q2) + Theta(3)*sin(q2),...
      Theta(14)*cos(q2 + q3) + Theta(13)*sin(q2 + q3);
      Theta(14)*cos(q2 + q3) + Theta(13)*sin(q2 + q3) + Theta(11)*cos(q2) + Theta(3)*sin(q2),...
      Theta(5) + 2*Theta(4)*cos(q3) + Theta(7),...
      Theta(7) + Theta(4)*cos(q3);
      Theta(14)*cos(q2 + q3) + Theta(13)*sin(q2 + q3),...                
      Theta(7) + Theta(4)*cos(q3),...                       
      Theta(7)];


C = [ - qp2*(Theta(4)*sin(2*q2 + q3) + (-Theta(6)*sin(2*q2 + 2*q3))/2 - Theta(12)*cos(2*q2 + 2*q3) - Theta(10)*cos(2*q2) - (Theta(2)*sin(2*q2))/2) - qp3*((-Theta(6)*sin(2*q2 + 2*q3))/2 - Theta(12)*cos(2*q2 + 2*q3) + (Theta(4)*sin(q3))/2 + (Theta(4)*sin(2*q2 + q3))/2), ...
        qp3*(Theta(13)*cos(q2 + q3) - Theta(14)*sin(q2 + q3)) - qp1*(Theta(4)*sin(2*q2 + q3)- Theta(12)*cos(2*q2 + 2*q3) + (-Theta(6)*sin(2*q2 + 2*q3))/2 - Theta(10)*cos(2*q2) - (Theta(2)*sin(2*q2))/2) + qp2*(Theta(13)*cos(q2 + q3) - Theta(14)*sin(q2 + q3) + Theta(3)*cos(q2) - Theta(11)*sin(q2)),...
        qp2*(Theta(13)*cos(q2 + q3) - Theta(14)*sin(q2 + q3)) - qp1*((-Theta(6)*sin(2*q2 + 2*q3))/2 - Theta(12)*cos(2*q2 + 2*q3) + (Theta(4)*sin(q3))/2 + (Theta(4)*sin(2*q2 + q3))/2) + qp3*(Theta(13)*cos(q2 + q3) - Theta(14)*sin(q2 + q3));
        qp1*(Theta(4)*sin(2*q2 + q3) + (-Theta(6)*sin(2*q2 + 2*q3))/2 - Theta(12)*cos(2*q2 + 2*q3) - Theta(10)*cos(2*q2) - (Theta(2)*sin(2*q2))/2),...
      - Theta(4)*qp3*sin(q3),...
      - Theta(4)*sin(q3)*(qp2 + qp3);
        qp1*((-Theta(6)*sin(2*q2 + 2*q3))/2 - Theta(12)*cos(2*q2 + 2*q3) + (Theta(4)*sin(q3))/2 + (Theta(4)*sin(2*q2 + q3))/2),...
        Theta(4)*qp2*sin(q3),...
        0];

G = [                                    0;
      g*Theta(9)*cos(q2 + q3) + g*Theta(8)*cos(q2);
                       g*Theta(9)*cos(q2 + q3)];

Qpp = M\(tau - C*Qp - G - beta*Qp);
%% Energy
Ec =  1/2*Qp'*M*Qp;

Ep = l4*g*m2*sin(q2)+(l2*sin(q2)+l6*sin(q2+q3))*m3*g;

Em = Ec+Ep;

out = [Qpp; Ec; Ep; Em];

end

