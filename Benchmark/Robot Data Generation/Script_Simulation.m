% Script that launch a number numSims of Monte Carlo Simulation with different seeds for
% the noise generation.

clear all
close all

%% Initialization

mdl = 'controled_robot';
isModelOpen = bdIsLoaded(mdl);
open_system(mdl);

numSims = 10;

simIn(1:numSims)=Simulink.SimulationInput(mdl)

for i = 1:numSims
    simIn(i) = setBlockParameter(simIn(i), [mdl '/Noise'], 'Seed', ['[', num2str(3*i),' ', num2str(3*i+1),' ', num2str(3*i+2), ']']);
end


%% Simulation

try
    simOut = parsim(simIn, 'ShowProgress', 'on'); % If the parallel Toolbox is detected
catch
    fprintf('Parallel toolbox not installed. Launching simulations sequentially...')
    for i = numSims:-1:1
        simOut(i) = sim(simIn(i));
    end
end

%% Postprocessing


for i = numSims:-1:1
    
    data_struct.t = simOut(i).tout(1:10:end)-10;
    
    data_struct.q1 = simOut(i).logsout.get('Q_m').Values.Data(:,1,:);
    data_struct.q2 = simOut(i).logsout.get('Q_m').Values.Data(:,2,:);
    data_struct.q3 = simOut(i).logsout.get('Q_m').Values.Data(:,3,:);
    
    data_struct.qp1 = simOut(i).logsout.get('Qp_m').Values.Data(:,1,:);
    data_struct.qp2 = simOut(i).logsout.get('Qp_m').Values.Data(:,2,:);
    data_struct.qp3 = simOut(i).logsout.get('Qp_m').Values.Data(:,3,:);
    
    data_struct.qpp1 = simOut(i).logsout.get('Qpp_m').Values.Data(:,1,:);
    data_struct.qpp2 = simOut(i).logsout.get('Qpp_m').Values.Data(:,2,:);
    data_struct.qpp3 = simOut(i).logsout.get('Qpp_m').Values.Data(:,3,:);
    
    data_struct.tau1 = simOut(i).logsout.get('Torque').Values.Data(:,1,:);
    data_struct.tau2 = simOut(i).logsout.get('Torque').Values.Data(:,2,:);
    data_struct.tau3 = simOut(i).logsout.get('Torque').Values.Data(:,3,:);
    
    data_struct.q1_real = simOut(i).logsout.get('Q_real').Values.Data(:,1,:);
    data_struct.q2_real = simOut(i).logsout.get('Q_real').Values.Data(:,2,:);
    data_struct.q3_real = simOut(i).logsout.get('Q_real').Values.Data(:,3,:);
    
    data_struct.qp1_real = simOut(i).logsout.get('Qp_real').Values.Data(:,1,:);
    data_struct.qp2_real = simOut(i).logsout.get('Qp_real').Values.Data(:,2,:);
    data_struct.qp3_real = simOut(i).logsout.get('Qp_real').Values.Data(:,3,:);
    
    data_struct.qpp1_real = simOut(i).logsout.get('Qpp_real').Values.Data(:,1,:);
    data_struct.qpp2_real = simOut(i).logsout.get('Qpp_real').Values.Data(:,2,:);
    data_struct.qpp3_real = simOut(i).logsout.get('Qpp_real').Values.Data(:,3,:);
    
    Data(i) = data_struct;
end

save('RRR_traj_6.mat', 'Data')

fprintf('Job done !')
