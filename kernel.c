#include "./include/print.h"
#include "./include/mem.h"
#include "./include/gdt.h"

#include <stddef.h>

void kernel_main() {

    // Disable interrupts to set up the GDT
    asm volatile ("cli");

     // Set up the GDT
    gdt_init();

    // Enable interrupts
    asm volatile ("sti");

    // Simple usage of print_msg() to print a string to the screen
    clear_screen();

    print_msg("Hello, World!\n");

    // Test the GDT by printing some memory addresses
    unsigned long* ptr = (unsigned long*)0x1000;
    print_msg("Memory address:\n");

    unsigned long* ptr2 = (unsigned long*)0x2000;
    print_msg("Memory address:\n");

    unsigned long* ptr3 = (unsigned long*)0x3000;
    print_msg("Memory address:\n");
}

void print_address(void* address) {
    print_msg("0x");
    print_dec((unsigned long)address);
    print_msg("\n");
}

void print_dec(unsigned long value) {
    char* ptr = (char*)&value;
    for (int i = 0; i < 4; i++) {
        print_msg(ptr[i]);
    }
}
