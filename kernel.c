#include "./include/print.h"
#include "./include/mem.h"

#include <stddef.h>

void kernel_main() {
    // Simple usage of print_msg() to print a string to the screen
    clear_screen();
     // Test allocate_memory()
    void* ptr1 = allocate_memory(100);
    if (ptr1 != NULL) {
        print_msg("Memory block 1 allocated successfully.\n");
    } else {
        print_msg("Failed to allocate memory block 1.\n");
    }

    // Test allocate_memory() again
    void* ptr2 = allocate_memory(200);
    if (ptr2 != NULL) {
        print_msg("Memory block 2 allocated successfully.\n");
    } else {
        print_msg("Failed to allocate memory block 2.\n");
    }

    // Test deallocate_memory()
    deallocate_memory(ptr1);
    print_msg("Memory block 1 deallocated.\n");

    // Test allocate_memory() again after deallocation
    void* ptr3 = allocate_memory(100);
    if (ptr3 != NULL) {
        print_msg("Memory block 3 allocated successfully.\n");
    } else {
        print_msg("Failed to allocate memory block 3.\n");
    }

    // Test deallocate_memory() again
    deallocate_memory(ptr2);
    print_msg("Memory block 2 deallocated.\n");
    deallocate_memory(ptr3);
    print_msg("Memory block 3 deallocated.\n");
}
