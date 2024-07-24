#ifndef MEM_H
#define MEM_H

// Define the size of a memory block
typedef struct MemoryBlock {
    unsigned int size;
    void* data;
    struct MemoryBlock* next; // Add the 'next' member
} MemoryBlock;

// Function declarations
void* allocate_memory(unsigned int size);
void deallocate_memory(void* ptr);

#endif