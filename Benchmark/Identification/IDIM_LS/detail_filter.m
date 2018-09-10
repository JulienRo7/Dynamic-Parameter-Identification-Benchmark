%% Test for the low pass filtering

load('RRR_traj_6.mat')
data_struct = Data(10);

t  = data_struct.t;
fs = 1e3;
%% generation of the desired acceleration trajectory

X = zeros(numel(t), 6);
for i =1:numel(t)
    X(i, :) = traj_gen_RRR(t(i))';
end

qp_d = X(:, 4);

%% Low-Pass Filter:

qpp = reshape(data_struct.qpp1, numel(data_struct.qpp1),1);

qpp_real = reshape(data_struct.qpp1_real, numel(data_struct.qpp1_real),1);

d = fdesign.lowpass('Fp,Fst,Ap,Ast', 100, 120, 0.01, 60, 1000);
Hd = design(d, 'equiripple');
fvtool(Hd)

qpp_f = filter(Hd, qpp);


%% 2 Pass Butterworth Filter:

% Butterworth filter parameters:
filtParam.freq_fil = 20.0;
filtParam.fnyq = fs/2; % Nyquist frequency
filtParam.nfilt = 4;
filtParam.dt = 1/fs;

% Remove boarder effects, because of diffcent function:
filtParam.n_border = 50;

ob = filtParam.freq_fil/filtParam.fnyq;
[b,a] = butter(filtParam.nfilt,ob);

q1_f = filtfilt(b,a,data_struct.q1(:));
q2_f = filtfilt(b,a,data_struct.q2(:));
q3_f = filtfilt(b,a,data_struct.q3(:));

% Velocity
qp1_f = diffcent(q1_f,filtParam.dt);
qp2_f = diffcent(q2_f,filtParam.dt);
qp3_f = diffcent(q3_f,filtParam.dt);

% Acceleration
qpp1_f = diffcent(qp1_f,filtParam.dt);
qpp2_f = diffcent(qp2_f,filtParam.dt);
qpp3_f = diffcent(qp3_f,filtParam.dt);
qpp_fBW = qpp1_f;

figure
title('Acceleration filtering')
hold on
plot(t, qpp);
plot(t, qpp_f);
plot(t, qpp_fBW);
plot(t, qpp_real);
hold off
legend('Not Filtered', 'Low-Pass Filtered', '2-Pass-Butterworth','Real', 'Orientation','horizontal')
xlabel('Time [s]')
ylabel('Qpp')
grid on
grid minor