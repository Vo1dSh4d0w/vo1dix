#!/usr/bin/env sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
mkdir -p out

cp grub/grub.cfg isodir/boot/grub
cp kernel/vo1dix.kernel isodir/boot

grub-mkrescue -o out/vo1dix.iso isodir