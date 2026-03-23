#!/usr/bin/env sh

. ./config.sh

for PROJECT in $PROJECTS; do
    (cd $PROJECT && DESTDIR="$SYSROOT" make install-headers)
done