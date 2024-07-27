#include "../include/gdt.h"
#include <stdint.h>

void encode_gdt_entry(uint64_t *target, uint64_t source)
{
    *target = source
}

uint64_t create_gdt_entry(uint16_t limit, uint64_t base, uint8_t access, uint8_t flags)
{
    
    // Get the limit address (first 16 bits)
    // Base address (next 24 bits)
    // Access byte (next 8 bits)
    // Flags (next 4 bits)
    // Old limit address (next 4 bits)
    // Old base address (next 8 bits)
    // We can set the old milit to all 1s and old base to all 0s
    uint64_t source = (limit & 0x000F) | ((base & 0x00FFFFFF) << 16) | ((access & 0xFF) << 40) | ((flags & 0x0F) << 44) | ((0xFFFF) << 32) | ((0x00) << 48);
    return source
}