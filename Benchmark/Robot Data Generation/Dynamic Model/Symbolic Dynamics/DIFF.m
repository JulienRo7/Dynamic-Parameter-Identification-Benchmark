function [ A_dot ] = DIFF(A, Var, Var_diff)

[m,n] = size(A);


A_dot = sym(zeros(size(A)));

for i = 1:m
    for j = 1:n
	tmp = sym(0);
        for k = 1:n
            A_dot(i,j) = A_dot(i,j) + diff(A(i,j),Var(k))*Var_diff(k);
        end
    end
end
A_dot = combine(simplify(A_dot));
