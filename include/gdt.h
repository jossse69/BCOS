#ifndef _GTD_H
#define _GTD_H

#include <stdint.h>

void encode_gdt_entry(uint8_t *target, uint64_t source)
uint64_t create_gdt_entry(uint16_t limit, uint64_t base, uint8_t access, uint8_t flags)

#endif