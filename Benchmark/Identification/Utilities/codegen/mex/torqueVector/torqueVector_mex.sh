MATLAB="/opt/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/quentin/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for torqueVector" > torqueVector_mex.mki
echo "CC=$CC" >> torqueVector_mex.mki
echo "CFLAGS=$CFLAGS" >> torqueVector_mex.mki
echo "CLIBS=$CLIBS" >> torqueVector_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> torqueVector_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> torqueVector_mex.mki
echo "CXX=$CXX" >> torqueVector_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> torqueVector_mex.mki
echo "CXXLIBS=$CXXLIBS" >> torqueVector_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> torqueVector_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> torqueVector_mex.mki
echo "LDFLAGS=$LDFLAGS" >> torqueVector_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> torqueVector_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> torqueVector_mex.mki
echo "Arch=$Arch" >> torqueVector_mex.mki
echo "LD=$LD" >> torqueVector_mex.mki
echo OMPFLAGS= >> torqueVector_mex.mki
echo OMPLINKFLAGS= >> torqueVector_mex.mki
echo "EMC_COMPILER=gcc" >> torqueVector_mex.mki
echo "EMC_CONFIG=optim" >> torqueVector_mex.mki
"/opt/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f torqueVector_mex.mk
