TOPDIR=$(pwd)
export target=arm-elf
export prefix=/usr/local/$target
export PATH=$prefix/bin:$PATH
export C_INCLUDE_PATH=$TOPDIR/arminix/include:$C_INCLUDE_PATH