function [T] = ComputeTheta(Xhi)

% Xhi = [l1, l2, l3, l4, l5, l6, m1, m2, m3, I111, I112, I113, I122, I123, I133, I211, I212, I213, I222, I223, I233, I311, I312, I313, I322, I323, I333, Fv1, Fv2, Fv3];

l1 = Xhi(1);
l2 = Xhi(2);
l3 = Xhi(3);
l4 = Xhi(4);
l5 = Xhi(5);
l6 = Xhi(6);
m1 = Xhi(7);
m2 = Xhi(8);
m3 = Xhi(9);
I111 = Xhi(10);
I112 = Xhi(11);
I113 = Xhi(12);
I122 = Xhi(13);
I123 = Xhi(14);
I133 = Xhi(15);
I211 = Xhi(16);
I212 = Xhi(17);
I213 = Xhi(18);
I222 = Xhi(19);
I223 = Xhi(20);
I233 = Xhi(21);
I311 = Xhi(22);
I312 = Xhi(23);
I313 = Xhi(24);
I322 = Xhi(25);
I323 = Xhi(26);
I333 = Xhi(27);
Fv1 = Xhi(28);
Fv2 = Xhi(29);
Fv3 = Xhi(30);
% Fc1 = param(31);
% Fc2 = param(32);
% Fc3 = param(33);

T = [ m3*l2^2 + m2*l5^2 + m3*l6^2 + I133 + I222 + I322; % Theta(1)
                             - m3*l2^2 - m2*l5^2 + I211 - I222; % Theta(2)
                                                          I213; % Theta(3)
                                                      l2*l6*m3; % Theta(4)
                                      m3*l2^2 + m2*l5^2 + I233; % Theta(5)
                                       - m3*l6^2 + I311 - I322; % Theta(6)
                                                m3*l6^2 + I333; % Theta(7)
                                                 l2*m3 + l5*m2; % Theta(8)
                                                         l6*m3; % Theta(9)
                                                          I212; % Theta(10)
                                                          I223; % Theta(11)
                                                          I312; % Theta(12)
                                                          I313; % Theta(13)
                                                          I323; % Theta(14)
                                                          Fv1;
                                                          Fv2;
                                                          Fv3];
%                                                           Fc1;
%                                                           Fc2;
%                                                           Fc3];
end

