nasm -f elf32 boot.asm -o ./boot.o
i686-elf-gcc -m32 -c ./kernel.c -o ./kernel.o  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
OBJECTS=$(find ./src -name "*.c" -exec i686-elf-gcc -m32 -c {} -o {}.o -ffreestanding \; )

# store the  object files we just created into a variable
# so we can pass them to the linker
i686-elf-gcc -T linker.ld -o bin/BCOS.bin -O2 -nostdlib boot.o $OBJECTS -lgcc