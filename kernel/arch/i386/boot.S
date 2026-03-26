.code32

.set MAGIC,     0x1BADB002
.set FALIGN,    1 << 0
.set FMEMINFO,  1 << 1
.set FLAGS,     FALIGN | FMEMINFO
.set CHECKSUM,  -(MAGIC + FLAGS)

.section .multiboot
.align 4
.int MAGIC
.int FLAGS
.int CHECKSUM

.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
.type _start, @function
_start:
    movl $stack_top, %esp
    push %ebx

    call kernel_main

    pop %ebx

1:  hlt
    jmp 1b

.size _start, . - _start
