function J = trajectory_criterion(p, r, t_0, t_f, N, n_ddl, n_f)

W = zeros(3*N, 20);
tps=linspace(t_0, t_f, N);



for i=1:N
    
    State = trajectory_gen(tps(i), p, r, n_ddl, n_f);
    
    q1 = State(1);
    q2 = State(2);
    q3 = State(3);
    
    qp1 = State(4);
    qp2 = State(5);
    qp3 = State(6);
    
    qpp1 = State(7);
    qpp2 = State(8);
    qpp3 = State(9);
   
    gx = 0;
    gy = 0;
    gz = 9.81;
    
    W(3*i-2:3*i,:)=[ qpp1, qpp1/2 - (qpp1*cos(2*q2))/2 + qp1*qp2*sin(2*q2), cos(q2)*qp2^2 + qpp2*sin(q2), qpp1*cos(q3) + qpp1*cos(2*q2 + q3) - qp1*qp3*sin(q3) - 2*qp1*qp2*sin(2*q2 + q3) - qp1*qp3*sin(2*q2 + q3),    0, qpp1/2 - (qpp1*cos(2*q2 + 2*q3))/2 + qp1*qp2*sin(2*q2 + 2*q3) + qp1*qp3*sin(2*q2 + 2*q3),           0, (gy*cos(q1 + q2))/2 - (gx*sin(q1 + q2))/2 + (gy*cos(q1 - q2))/2 - (gx*sin(q1 - q2))/2, (gy*cos(q2 - q1 + q3))/2 + (gx*sin(q2 - q1 + q3))/2 + (gy*cos(q1 + q2 + q3))/2 - (gx*sin(q1 + q2 + q3))/2, qpp1*sin(2*q2) + 2*qp1*qp2*cos(2*q2), - sin(q2)*qp2^2 + qpp2*cos(q2), qpp1*sin(2*q2 + 2*q3) + 2*qp1*qp2*cos(2*q2 + 2*q3) + 2*qp1*qp3*cos(2*q2 + 2*q3), cos(q2 + q3)*qp2^2 + 2*cos(q2 + q3)*qp2*qp3 + cos(q2 + q3)*qp3^2 + qpp2*sin(q2 + q3) + qpp3*sin(q2 + q3), - sin(q2 + q3)*qp2^2 - 2*sin(q2 + q3)*qp2*qp3 - sin(q2 + q3)*qp3^2 + qpp2*cos(q2 + q3) + qpp3*cos(q2 + q3), qp1,    0,    0, sign(qp1),          0,          0;
                        0,                            -(qp1^2*sin(2*q2))/2,                 qpp1*sin(q2),                 sin(2*q2 + q3)*qp1^2 - sin(q3)*qp3^2 - 2*qp2*sin(q3)*qp3 + 2*qpp2*cos(q3) + qpp3*cos(q3), qpp2,                                                              -(qp1^2*sin(2*q2 + 2*q3))/2, qpp2 + qpp3,                                  gz*cos(q2) - gx*cos(q1)*sin(q2) - gy*sin(q1)*sin(q2),                                       gz*cos(q2 + q3) - gx*sin(q2 + q3)*cos(q1) - gy*sin(q2 + q3)*sin(q1),                     -qp1^2*cos(2*q2),                   qpp1*cos(q2),                                                         -qp1^2*cos(2*q2 + 2*q3),                                                                                        qpp1*sin(q2 + q3),                                                                                          qpp1*cos(q2 + q3),    0, qp2,    0,          0, sign(qp2),          0;
                        0,                                               0,                            0,                                      (sin(2*q2 + q3)/2 + sin(q3)/2)*qp1^2 + sin(q3)*qp2^2 + qpp2*cos(q3),    0,                                                              -(qp1^2*sin(2*q2 + 2*q3))/2, qpp2 + qpp3,                                                                                     0,                                       gz*cos(q2 + q3) - gx*sin(q2 + q3)*cos(q1) - gy*sin(q2 + q3)*sin(q1),                                    0,                              0,                                                         -qp1^2*cos(2*q2 + 2*q3),                                                                                        qpp1*sin(q2 + q3),                                                                                          qpp1*cos(q2 + q3),    0,    0, qp3,          0,          0, sign(qp3)];
    
end

k1 = 1;
k2 = 100;

S = svd(W);

sig_min = min(S);
C = cond(W'*W);

J = k1*C+k2*1/sig_min;

end