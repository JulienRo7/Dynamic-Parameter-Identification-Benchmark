function H_m =  Homogeneous_com(i,DH)
 
        TransXi = [1 0 0 DH(i,3); 0 1 0 0; 0 0 1 0; 0 0 0 1];
        TransZi = [1 0 0 0; 0 1 0 0; 0 0 1 DH(i,2); 0 0 0 1];
        rotXi = [1 0 0 0; 0 cos(DH(i,4)) -sin(DH(i,4)) 0; 0 sin(DH(i,4)) cos(DH(i,4)) 0; 0 0 0 1];
        rotZi = [cos(DH(i,1)) -sin(DH(i,1)) 0 0; sin(DH(i,1)) cos(DH(i,1)) 0 0; 0 0 1 0; 0 0 0 1];
        
        U = (rotZi*TransZi*TransXi*rotXi);

 H_m=U;
end

