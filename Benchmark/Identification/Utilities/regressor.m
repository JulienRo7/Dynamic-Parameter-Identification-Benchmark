function regressor = regressor(gx,gy,gz,q1,q2,q3,qp1,qp2,qp3,qpp1,qpp2,qpp3)
%REGRESSOR
%    REGRESSOR = REGRESSOR(GX,GY,GZ,Q1,Q2,Q3,QP1,QP2,QP3,QPP1,QPP2,QPP3)

%    This function was generated by the Symbolic Math Toolbox version 8.0.
%    13-Apr-2018 14:57:52

t2 = q2.*2.0;
t3 = q3+t2;
t4 = sin(t3);
t5 = qpp1.*(1.0./2.0);
t6 = q3.*2.0;
t7 = t2+t6;
t8 = sin(t7);
t9 = q1+q2;
t10 = q1-q2;
t11 = -q1+q2+q3;
t12 = q1+q2+q3;
t13 = sin(t2);
t14 = cos(t2);
t15 = qp2.^2;
t16 = sin(q2);
t17 = cos(q2);
t18 = cos(t7);
t19 = q2+q3;
t20 = sin(t19);
t21 = cos(t19);
t22 = qp3.^2;
t23 = sin(q3);
t24 = qp1.^2;
t25 = cos(q3);
t26 = cos(q1);
t27 = sin(q1);
t28 = qpp2+qpp3;
t29 = gz.*t21;
t30 = t29-gx.*t20.*t26-gy.*t20.*t27;
t31 = qpp1.*t20;
t32 = qpp1.*t21;
regressor = reshape([qpp1,0.0,0.0,t5-qpp1.*t14.*(1.0./2.0)+qp1.*qp2.*t13,t13.*t24.*(-1.0./2.0),0.0,qpp2.*t16+t15.*t17,qpp1.*t16,0.0,qpp1.*t25+qpp1.*cos(t3)-qp1.*qp2.*t4.*2.0-qp1.*qp3.*t4-qp1.*qp3.*t23,qpp2.*t25.*2.0+qpp3.*t25+t4.*t24-t22.*t23-qp2.*qp3.*t23.*2.0,qpp2.*t25+t15.*t23+t24.*(t4.*(1.0./2.0)+t23.*(1.0./2.0)),0.0,qpp2,0.0,t5-qpp1.*t18.*(1.0./2.0)+qp1.*qp2.*t8+qp1.*qp3.*t8,t8.*t24.*(-1.0./2.0),t8.*t24.*(-1.0./2.0),0.0,t28,t28,gy.*cos(t9).*(1.0./2.0)+gy.*cos(t10).*(1.0./2.0)-gx.*sin(t9).*(1.0./2.0)-gx.*sin(t10).*(1.0./2.0),gz.*t17-gx.*t16.*t26-gy.*t16.*t27,0.0,gy.*cos(t11).*(1.0./2.0)+gy.*cos(t12).*(1.0./2.0)+gx.*sin(t11).*(1.0./2.0)-gx.*sin(t12).*(1.0./2.0),t30,t30,qpp1.*t13+qp1.*qp2.*t14.*2.0,-t14.*t24,0.0,qpp2.*t17-t15.*t16,qpp1.*t17,0.0,qpp1.*t8+qp1.*qp2.*t18.*2.0+qp1.*qp3.*t18.*2.0,-t18.*t24,-t18.*t24,qpp2.*t20+qpp3.*t20+t15.*t21+t21.*t22+qp2.*qp3.*t21.*2.0,t31,t31,qpp2.*t21+qpp3.*t21-t15.*t20-t20.*t22-qp2.*qp3.*t20.*2.0,t32,t32, qp1, 0, 0, 0, qp2, 0, 0, 0, qp3],[3,17]);

% , sign(qp1), 0, 0, 0, sign(qp2), 0, 0, 0, sign(qp3)