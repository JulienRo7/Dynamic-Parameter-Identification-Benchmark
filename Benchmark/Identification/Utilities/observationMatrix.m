function [W] = observationMatrix(Q, Qp, Qpp) %#codegen

[m,n]=size(Q);
W = zeros( m*n, 17);

gx = 0;
gy = 0;
gz = 9.81; %gravity vector

% Building of the observation matrix W for the current iteration of Theta:
    for i=1:m

        q1 = Q(i,1);
        q2 = Q(i,2);
        q3 = Q(i,3);
        qp1 = Qp(i,1);
        qp2 = Qp(i,2);
        qp3 = Qp(i,3);
        qpp1 = Qpp(i,1);
        qpp2 = Qpp(i,2);
        qpp3 = Qpp(i,3);
        
        % Compute the observation matrix:
        W(3*i-2:3*i,:) = regressor(gx,gy,gz,q1,q2,q3,qp1,qp2,qp3,qpp1,qpp2,qpp3);

    end
end

