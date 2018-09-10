MATLAB="/opt/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/quentin/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for ukf_opt" > ukf_opt_mex.mki
echo "CC=$CC" >> ukf_opt_mex.mki
echo "CFLAGS=$CFLAGS" >> ukf_opt_mex.mki
echo "CLIBS=$CLIBS" >> ukf_opt_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> ukf_opt_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> ukf_opt_mex.mki
echo "CXX=$CXX" >> ukf_opt_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> ukf_opt_mex.mki
echo "CXXLIBS=$CXXLIBS" >> ukf_opt_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> ukf_opt_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> ukf_opt_mex.mki
echo "LDFLAGS=$LDFLAGS" >> ukf_opt_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> ukf_opt_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> ukf_opt_mex.mki
echo "Arch=$Arch" >> ukf_opt_mex.mki
echo "LD=$LD" >> ukf_opt_mex.mki
echo OMPFLAGS=-fopenmp -DOMPLIBNAME='"\"/opt/MATLAB/R2018a/sys/os/glnxa64/libiomp5.so\""' >> ukf_opt_mex.mki
echo OMPLINKFLAGS=-fPIC -L/opt/MATLAB/R2018a/sys/os/glnxa64 -liomp5 >> ukf_opt_mex.mki
echo "EMC_COMPILER=gcc" >> ukf_opt_mex.mki
echo "EMC_CONFIG=optim" >> ukf_opt_mex.mki
"/opt/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f ukf_opt_mex.mk
