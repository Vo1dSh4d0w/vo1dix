#!/usr/bin/env sh

./build.sh
./mkiso.sh

qemu-system-i386 -cdrom out/vo1dix.iso