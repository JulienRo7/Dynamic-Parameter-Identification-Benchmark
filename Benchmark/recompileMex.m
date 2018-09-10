function [compileTime] = recompileMex(list)

tic
disp("####################################################################################");
disp("####################################################################################");
disp("####################################################################################");
disp("Recompile mex functions...");
disp("####################################################################################");
disp("####################################################################################");
disp("####################################################################################");
disp(" ");


if (list(1) == 1)
    codegen -v -config:mex -o 'Benchmark/Identification/Utilities/torqueVector_mex' -d 'Benchmark/Identification/Utilities/codegen/mex/torqueVector' -O enable:openmp -O enable:inline -report torqueVector -args {coder.typeof(ones(10001,3), [], 1)}
end

if (list(2) == 1)
    codegen -v -config:mex -o 'Benchmark/Identification/Utilities/observationMatrix_mex' -d 'Benchmark/Identification/Utilities/codegen/mex/observationMatrix' -O enable:openmp -O enable:inline -report observationMatrix -args {coder.typeof(ones(10001,3), [], 1), coder.typeof(ones(10001,3), [], 1), coder.typeof(ones(10001,3), [], 1)}
end

if (list(3) == 1)
    codegen -v -config:mex -o 'Benchmark/Identification/Utilities/integrate_RRR_dyn_CL_mex' -d 'Benchmark/Identification/Utilities/codegen/mex/integrate_RRR_dyn_CL' -O enable:openmp -O enable:inline -report integrate_RRR_dyn_CL -args {coder.typeof(ones(6,1), [], 1), coder.typeof(ones(17,1), [], 1), coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.typeof(0, [], 0)}
end

if (list(4) == 1)
    disp("Expect 10 min compile time for the EKF due to the jacobian matrix: be patient !");
    codegen -v -config:mex -o 'Benchmark/Identification/Kalman/EKF/ekf_opt_mex' -d 'Benchmark/Identification/Kalman/Utils/codegen/mex/ekf_opt' -O enable:openmp -O enable:inline -report ekf_opt -args {coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.typeof(ones(23,1), [], 1), coder.typeof(ones(3,1), [], 1), coder.typeof(ones(23,23), [], 1), coder.typeof(ones(3,1), [], 1), coder.typeof(ones(23,23), [], 1), coder.typeof(ones(3,3), [], 1)}
end

if (list(5) == 1)
    codegen -v -config:mex -o 'Benchmark/Identification/Kalman/UKF/ukf_opt_mex' -d 'Benchmark/Identification/Kalman/Utils/codegen/mex/ukf_opt' -O enable:openmp -O enable:inline -report ukf_opt -args {coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.typeof(ones(23,1), [], 1), coder.typeof(ones(3,1), [], 1), coder.typeof(ones(23,23), [], 1), coder.typeof(ones(3,1), [], 1), coder.typeof(ones(23,23), [], 1), coder.typeof(ones(3,3), [], 1), coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.newtype('logical', [], 0)}
end

if (list(6) == 1)
    codegen -v -config:mex -o 'Benchmark/Identification/Kalman/UKF/srukf_opt_mex' -d 'Benchmark/Identification/Kalman/Utils/codegen/mex/srukf_opt' -O enable:openmp -O enable:inline -report srukf_opt -args {coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.typeof(ones(23,1), [], 1), coder.typeof(ones(3,1), [], 1), coder.typeof(ones(23,23), [], 1), coder.typeof(ones(3,1), [], 1), coder.typeof(ones(23,23), [], 1), coder.typeof(ones(3,3), [], 1), coder.typeof(0, [], 0), coder.typeof(0, [], 0), coder.typeof(0, [], 0)}
end

compileTime = toc;
end

