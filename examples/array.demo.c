/**
 * @file
 * @brief Standalone verification demonstration for the librxdsa array subsystem.
 * @details This source file serves as a minimal functional blueprint for 
 *          developers to initialize, write to, and read from dynamic array 
 *          buffers safely using the core library runtime.
 * @author rookie2373
 * @version 0.0.1
 */

#include <stdio.h>
#include "librxdsa.h"

/**
 * @brief Application entry point for the array demo interface.
 * @details Performs a sanity verification pass, triggers engine telemetry via 
 *          array_hello(), dynamically allocates a pointer buffer, sets an element 
 *          offset, and evaluates standard return diagnostics.
 * 
 * @return int Returns 0 upon successful validation routine completion.
 * 
 * @see array_hello()
 * @see array_init()
 * @see array_set_at()
 * @see array_get_at()
 */
int main() {
    int retcode;

    /* Verify subsystem availability and connectivity */
    retcode = array_hello();
    printf("array_hello %d\n", retcode);
    
    /* Dynamically instantiate an integer array buffer with an initial boundary of 11 elements */
    int* arr = NULL;
    retcode = array_init(&arr, 11);
    printf("array_init %d\n", retcode);

    /* Safely assign the value 456 to index offset 5, supplying the explicit array dimension limits */
    retcode = array_set_at(&arr, 5, 456, 11);
    printf("array_set_at %d\n", retcode);

    /* Retrieve and evaluate the element located at index offset 5 within bounds */
    retcode = array_get_at(&arr, 5, 11);
    printf("array_get_at %d\n", retcode);

    return 0;
}