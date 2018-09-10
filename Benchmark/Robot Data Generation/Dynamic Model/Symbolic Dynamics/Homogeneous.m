function H = Homogeneous(i,j,DH)
    
T = [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1];
    for k = j+1:1:i

        TransX = [1 0 0 DH(k,3); 0 1 0 0; 0 0 1 0; 0 0 0 1];
        TransZ = [1 0 0 0; 0 1 0 0; 0 0 1 DH(k,2); 0 0 0 1];
        rotX = [1 0 0 0; 0 cos(DH(k,4)) -sin(DH(k,4)) 0; 0 sin(DH(k,4)) cos(DH(k,4)) 0; 0 0 0 1];
        rotZ = [cos(DH(k,1)) -sin(DH(k,1)) 0 0; sin(DH(k,1)) cos(DH(k,1)) 0 0; 0 0 1 0; 0 0 0 1];
        
        T = T*(rotZ*TransZ*TransX*rotX);
    end
 H=T;
end


