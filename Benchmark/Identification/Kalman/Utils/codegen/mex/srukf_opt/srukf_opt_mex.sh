MATLAB="/opt/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/quentin/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for srukf_opt" > srukf_opt_mex.mki
echo "CC=$CC" >> srukf_opt_mex.mki
echo "CFLAGS=$CFLAGS" >> srukf_opt_mex.mki
echo "CLIBS=$CLIBS" >> srukf_opt_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> srukf_opt_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> srukf_opt_mex.mki
echo "CXX=$CXX" >> srukf_opt_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> srukf_opt_mex.mki
echo "CXXLIBS=$CXXLIBS" >> srukf_opt_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> srukf_opt_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> srukf_opt_mex.mki
echo "LDFLAGS=$LDFLAGS" >> srukf_opt_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> srukf_opt_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> srukf_opt_mex.mki
echo "Arch=$Arch" >> srukf_opt_mex.mki
echo "LD=$LD" >> srukf_opt_mex.mki
echo OMPFLAGS=-fopenmp -DOMPLIBNAME='"\"/opt/MATLAB/R2018a/sys/os/glnxa64/libiomp5.so\""' >> srukf_opt_mex.mki
echo OMPLINKFLAGS=-fPIC -L/opt/MATLAB/R2018a/sys/os/glnxa64 -liomp5 >> srukf_opt_mex.mki
echo "EMC_COMPILER=gcc" >> srukf_opt_mex.mki
echo "EMC_CONFIG=optim" >> srukf_opt_mex.mki
"/opt/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f srukf_opt_mex.mk
