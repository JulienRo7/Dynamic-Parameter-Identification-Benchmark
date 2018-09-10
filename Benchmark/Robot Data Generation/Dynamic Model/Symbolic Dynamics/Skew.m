function [S] = Skew(v)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
S = [0,-v(3), v(2);
    v(3),0,-v(1);
    -v(2), v(1), 0];
end

