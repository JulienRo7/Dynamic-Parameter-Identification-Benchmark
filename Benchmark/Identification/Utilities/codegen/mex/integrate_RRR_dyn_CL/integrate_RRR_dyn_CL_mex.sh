MATLAB="/opt/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/quentin/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for integrate_RRR_dyn_CL" > integrate_RRR_dyn_CL_mex.mki
echo "CC=$CC" >> integrate_RRR_dyn_CL_mex.mki
echo "CFLAGS=$CFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "CLIBS=$CLIBS" >> integrate_RRR_dyn_CL_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "CXX=$CXX" >> integrate_RRR_dyn_CL_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "CXXLIBS=$CXXLIBS" >> integrate_RRR_dyn_CL_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "LDFLAGS=$LDFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> integrate_RRR_dyn_CL_mex.mki
echo "Arch=$Arch" >> integrate_RRR_dyn_CL_mex.mki
echo "LD=$LD" >> integrate_RRR_dyn_CL_mex.mki
echo OMPFLAGS= >> integrate_RRR_dyn_CL_mex.mki
echo OMPLINKFLAGS= >> integrate_RRR_dyn_CL_mex.mki
echo "EMC_COMPILER=gcc" >> integrate_RRR_dyn_CL_mex.mki
echo "EMC_CONFIG=optim" >> integrate_RRR_dyn_CL_mex.mki
"/opt/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f integrate_RRR_dyn_CL_mex.mk
