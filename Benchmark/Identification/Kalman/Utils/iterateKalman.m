function [x, P, status] = iterateKalman(index, k, filterOptions, data_struct, x, u, P, y, Rv, Rn, alpha, beta, kappa, filterObjectToolbox)

status = 'ok';

switch (filterOptions.type)
    case 'ekf' % Extended Kalman Filter
        switch (filterOptions.implementation)
            case 'classic'
                [x, P, ~] = ekf_opt(data_struct.t(index-k), data_struct.t(index), x, u, P, y, Rv, Rn);
            case 'optim'
                [x, P, ~] = ekf_opt_mex(data_struct.t(index-k), data_struct.t(index), x, u, P, y, Rv, Rn);
            case 'toolbox'
                % The 'kalmanFilter' structure is defined in the initKalman() function. It contains the toolbox filter settings.
                filterObjectToolbox.ProcessNoise = Rv;
                [x, P] = correct(filterObjectToolbox,y);
                predict(filterObjectToolbox,u);
            otherwise
                fprintf('\n Error : Incorrect filter type. \n');
                status = 'error';
        end
    case 'ukf' % Unscented Kalman Filter
        switch filterOptions.sigmaCompute
            case 'chol'
                computeMethod = false;
            case 'svd'
                computeMethod = true;
        end
        switch (filterOptions.implementation)
            case 'classic'
                [x, P, ~] = ukf_opt(data_struct.t(index-k), data_struct.t(index), x, u, P, y, Rv, Rn, alpha, beta, kappa, computeMethod);
            case 'optim'
                [x, P, ~] = ukf_opt_mex(data_struct.t(index-k), data_struct.t(index), x, u, P, y, Rv, Rn, alpha, beta, kappa, computeMethod);
            case 'toolbox'
                % The 'kalmanFilter' structure is defined in the initKalman() function. It contains the toolbox filter settings.
                filterObjectToolbox.ProcessNoise = Rv;
                [x, P] = correct(filterObjectToolbox,y);
                predict(filterObjectToolbox,u);
            otherwise
                fprintf('\n Error : Incorrect filter type. \n');
                status = 'error';
        end
    case 'srukf' % Square Root Unscented Kalman Filter
        S = chol(P)';
        Sv = chol(Rv)';
        Sn = chol(Rn)';
        switch (filterOptions.implementation)
            case 'classic'
                [x, S, ~] = srukf_opt(data_struct.t(index-k), data_struct.t(index), x, u, S, y, Sv, Sn, alpha, beta, kappa);
            case 'optim'
                [x, S, ~] = srukf_opt_mex(data_struct.t(index-k), data_struct.t(index), x, u, S, y, Sv, Sn, alpha, beta, kappa);
            otherwise
                fprintf('\n Error : Incorrect filter type. \n');
                status = 'error';
        end
        P=S*S';
    otherwise
        fprintf('\n Error : Unknown filter type. \n');
        status = 'error';
end

end

