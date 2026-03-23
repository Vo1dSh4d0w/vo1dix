#!/usr/bin/env sh

. ./headers.sh

for PROJECT in $PROJECTS; do
    (cd $PROJECT && DESTDIR="$SYSROOT" make install)
done
