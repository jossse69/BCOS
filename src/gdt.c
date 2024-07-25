#include "../include/gdt.h"
#include <stdint.h>

gdt_entry_t gdt[3];
gdt_ptr_t gdt_ptr;

void gdt_init() {
    // Set up the GDT
    gdt_ptr.limit = (sizeof(gdt_entry_t) * 3) - 1;
    gdt_ptr.base = (uint32_t)&gdt;

    // Code segment
    gdt[0].base_low = 0;
    gdt[0].base_middle = 0;
    gdt[0].base_high = 0;
    gdt[0].granularity = 0;
    gdt[0].granularity |= 0xA0; // 1010
    gdt[0].access = 0x9A; // 1001
    gdt[0].limit_low = 0xFFFF;

    // Data segment
    gdt[1].base_low = 0;
    gdt[1].base_middle = 0;
    gdt[1].base_high = 0;
    gdt[1].granularity = 0;
    gdt[1].granularity |= 0xC0; // 1100
    gdt[1].access = 0x92; // 10010
    gdt[1].limit_low = 0xFFFF;

    // Null segment
    gdt[2].base_low = 0;
    gdt[2].base_middle = 0;
    gdt[2].base_high = 0;
    gdt[2].granularity = 0;
    gdt[2].access = 0;
    gdt[2].limit_low = 0;

    // Load the GDT
    asm volatile ("lgdt %0" : : "m" (gdt_ptr));

    // Load the code segment
    asm volatile ("movw $0x10, %ax\n\t"
                  "movw %ax, %ds\n\t"
                  "movw %ax, %es\n\t"
                  "movw %ax, %fs\n\t"
                  "movw %ax, %gs\n\t"
                  "lidt %0" : : "m" (gdt_ptr));

    // Load the data segment
    asm volatile ("movw $0x10, %ax\n\t"
                  "movw %ax, %ds\n\t"
                  "movw %ax, %es\n\t"
                  "movw %ax, %fs\n\t"
                  "movw %ax, %gs\n\t"
                  "lidt %0" : : "m" (gdt_ptr));

    // Load the code segment
    asm volatile ("ljmp $0x08, $next\n\t"
                  "next:\n\t");
}