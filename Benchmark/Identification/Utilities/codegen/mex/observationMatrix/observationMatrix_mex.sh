MATLAB="/opt/MATLAB/R2018a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/quentin/.matlab/R2018a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for observationMatrix" > observationMatrix_mex.mki
echo "CC=$CC" >> observationMatrix_mex.mki
echo "CFLAGS=$CFLAGS" >> observationMatrix_mex.mki
echo "CLIBS=$CLIBS" >> observationMatrix_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> observationMatrix_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> observationMatrix_mex.mki
echo "CXX=$CXX" >> observationMatrix_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> observationMatrix_mex.mki
echo "CXXLIBS=$CXXLIBS" >> observationMatrix_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> observationMatrix_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> observationMatrix_mex.mki
echo "LDFLAGS=$LDFLAGS" >> observationMatrix_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> observationMatrix_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> observationMatrix_mex.mki
echo "Arch=$Arch" >> observationMatrix_mex.mki
echo "LD=$LD" >> observationMatrix_mex.mki
echo OMPFLAGS= >> observationMatrix_mex.mki
echo OMPLINKFLAGS= >> observationMatrix_mex.mki
echo "EMC_COMPILER=gcc" >> observationMatrix_mex.mki
echo "EMC_CONFIG=optim" >> observationMatrix_mex.mki
"/opt/MATLAB/R2018a/bin/glnxa64/gmake" -j 1 -B -f observationMatrix_mex.mk
