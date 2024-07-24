#include "../include/mem.h"

#include <stddef.h>
// Static variables to keep track of allocated memory
static MemoryBlock* allocated_blocks = NULL;
static unsigned int num_allocated_blocks = 0;

// Define a static memory pool
static char memory_pool[1024 * 1024]; // 1MB memory pool
static char* memory_pool_ptr = memory_pool;


void* malloc(size_t size) {
    void* ptr = memory_pool_ptr;
    memory_pool_ptr += size;
    return ptr;
}

void free(void* ptr) {
    // No need to implement free() as there is no need to free memory in a static memory pool
    // You can ignore this function if you don't need to free memory
}


// Function implementations
void* allocate_memory(unsigned int size) {
    // Allocate memory dynamically
    void* ptr = malloc(size);
    
    // Check if allocation was successful
    if (ptr != NULL) {
        // Create a new MemoryBlock
        MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock));
        
        // Check if MemoryBlock allocation was successful
        if (block != NULL) {
            block->size = size;
            block->data = ptr;
            
            // Add the MemoryBlock to the list
            block->next = allocated_blocks;
            allocated_blocks = block;
            num_allocated_blocks++;
        }
    }
    
    return ptr;
}

void deallocate_memory(void* ptr) {
    // Check if the pointer is valid
    if (ptr != NULL) {
        // Find the MemoryBlock associated with the pointer
        MemoryBlock* block = allocated_blocks;
        MemoryBlock* prev_block = NULL;
        
        while (block != NULL && block->data != ptr) {
            prev_block = block;
            block = block->next;
        }
        
        // Check if the MemoryBlock was found
        if (block != NULL) {
            // Remove the MemoryBlock from the list
            if (prev_block == NULL) {
                allocated_blocks = block->next;
            } else {
                prev_block->next = block->next;
            }
            
            num_allocated_blocks--;
            
            // Free the MemoryBlock and the allocated memory
            free(block);
            free(ptr);
        }
    }
}