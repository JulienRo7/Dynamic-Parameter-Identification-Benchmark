function [Rv, pNoiseAdaptParams] = annealingNoiseCovariance(Rv, pNoiseAdaptParams, paramSize)

% Annealing of for the process noise covariance matrix.

pNoiseAdaptParams.cov = sqrt(max(pNoiseAdaptParams.annealFactor*(pNoiseAdaptParams.cov.^2) , pNoiseAdaptParams.variance));
Rv(end-paramSize+1:end,end-paramSize+1:end)= diag(pNoiseAdaptParams.cov); % Only the parameter covariance is annealed

end

