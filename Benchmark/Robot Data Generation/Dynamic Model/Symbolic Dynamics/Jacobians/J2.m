function J2_W = J2(l2,q1,q2)
%J2
%    J2_W = J2(L2,Q1,Q2)

%    This function was generated by the Symbolic Math Toolbox version 8.0.
%    06-Jun-2018 00:23:23

t2 = cos(q1);
t3 = cos(q2);
t4 = sin(q1);
t5 = sin(q2);
J2_W = reshape([-l2.*t3.*t4,l2.*t2.*t3,0.0,0.0,0.0,1.0,-l2.*t2.*t5,-l2.*t4.*t5,l2.*t3,t4,-t2,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,3]);