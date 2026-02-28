#!/usr/bin/env sh

. ./config.sh

cd kernel
make clean

rm -rf $SYSROOT
rm -rf isodir
rm -rf out 
