function y = acquireMeasurement(data_struct, index)

% This function returns the reference joint trajectory of the robot (whose 
% dynamic parameters are to be identified) at a given epoch.

 y = [data_struct.q1(index);
        data_struct.q2(index);
        data_struct.q3(index)];

end