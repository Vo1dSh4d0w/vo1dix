#!/usr/bin/env sh

. ./config.sh

for PROJECT in $PROJECTS; do
    (cd $PROJECT && make clean)
done

rm -rf $SYSROOT
rm -rf isodir
rm -rf out 
