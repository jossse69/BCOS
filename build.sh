nasm -f elf32 boot.asm -o ./boot.o
i686-elf-gcc -m32 -c ./kernel.c -o ./kernel.o
find ./src -name "*.c" -exec i686-elf-gcc -m32 -c {} -o {}.o \;
ld -m elf_i386 -nostdlib -T ./link.ld -o ./bin/kernel.bin boot.o kernel.o ./src/*.o