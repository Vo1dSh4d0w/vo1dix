#!/usr/bin/env sh

PROJECTS="libc kernel"

export TARGET_HOST=${TARGET_HOST:-i686}
export TARGET_ARCH=$(./host-to-arch.sh $TARGET_HOST)

export CC=$TARGET_HOST-elf-gcc
export AR=$TARGET_HOST-elf-ar

export SYSROOT=$(pwd)/sysroot
export PREFIX=/usr
export BOOTDIR=/boot
export LIBDIR=$PREFIX/lib
export INCLUDEDIR=$PREFIX/include
export CC="$CC --sysroot=$SYSROOT -isystem=$INCLUDEDIR -L$SYSROOT$LIBDIR"
