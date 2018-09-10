MATLAB="/opt/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/quentin/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for ekf_opt" > ekf_opt_mex.mki
echo "CC=$CC" >> ekf_opt_mex.mki
echo "CFLAGS=$CFLAGS" >> ekf_opt_mex.mki
echo "CLIBS=$CLIBS" >> ekf_opt_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> ekf_opt_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> ekf_opt_mex.mki
echo "CXX=$CXX" >> ekf_opt_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> ekf_opt_mex.mki
echo "CXXLIBS=$CXXLIBS" >> ekf_opt_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> ekf_opt_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> ekf_opt_mex.mki
echo "LDFLAGS=$LDFLAGS" >> ekf_opt_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> ekf_opt_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> ekf_opt_mex.mki
echo "Arch=$Arch" >> ekf_opt_mex.mki
echo "LD=$LD" >> ekf_opt_mex.mki
echo OMPFLAGS= >> ekf_opt_mex.mki
echo OMPLINKFLAGS= >> ekf_opt_mex.mki
echo "EMC_COMPILER=gcc" >> ekf_opt_mex.mki
echo "EMC_CONFIG=optim" >> ekf_opt_mex.mki
"/opt/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f ekf_opt_mex.mk
