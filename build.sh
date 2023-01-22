#!/bin/sh
nasm -f elf32 kernel.asm -o obj/kasm.o
gcc -m32 -c -w include/idt.c -o obj/idt.o -ffreestanding
gcc -m32 -c -w include/isr.c -o obj/isr.o -ffreestanding
gcc -m32 -c -w include/kb.c -o obj/kb.o -ffreestanding
gcc -m32 -c -w include/screen.c -o obj/screen.o -ffreestanding
gcc -m32 -c -w include/string.c -o obj/string.o -ffreestanding
gcc -m32 -c -w include/system.c -o obj/system.o -ffreestanding
gcc -m32 -c -w include/util.c -o obj/util.o -ffreestanding
gcc -m32 -c -w kernel.c -o obj/kc.o -ffreestanding
ld -m elf_i386 -T link.ld -o ./simple/boot/kernel.bin obj/kasm.o obj/kc.o obj/idt.o obj/isr.o obj/kb.o obj/screen.o obj/string.o obj/system.o obj/util.o
# grub-mkrescue -o ./release/simple.iso simple
