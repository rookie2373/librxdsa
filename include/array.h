/**
 * @file array.h
 * @brief Dynamic integer array subsystem with boundary validation checks.
 * @details Provides core memory allocation routines, boundary-checked index manipulation,
 *          and vector resizing tools for safe data handling.
 * @author rookie2373
 * @version 0.0.1
 * @example array.demo.c
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Return Code Enums / Status Macros --- */
#define SUCCESS              0   /**< Operations completed successfully without error. */
#define ARRAY_POINTER_NULL -1   /**< The provided double-pointer reference was unallocated or NULL. */
#define INDEX_OUT_OF_BOUNDS -2  /**< Requested index exceeds target capacity constraints. */

/**
 * @brief Prints an identification check banner for the array subsystem.
 * @return int Returns SUCCESS upon routine completion.
 */
int array_hello(void);

/**
 * @brief Dynamically allocates a zero-initialized contiguous integer storage buffer.
 * 
 * @param[out] array_pointer Address of the target pointer to capture the allocated memory address.
 * @param[in]  array_size    Total number of integer element slots to instantiate.
 * @return int               Returns SUCCESS on successful validation, or ARRAY_POINTER_NULL.
 * 
 * @note Utilizes calloc() internally to guarantee safe zero-initialization of memory blocks.
 */
int array_init(int** array_pointer, int array_size);

/**
 * @brief Mutates a specific element value at a validated index offset.
 * 
 * @param[in,out] array_pointer Double pointer to the underlying buffer.
 * @param[in]     index         Zero-based offset position inside the allocated array block.
 * @param[in]     value         The integer value payload to set at the destination index.
 * @param[in]     array_size    Current dimensional capacity limit of the target array buffer.
 * @return int                  Returns SUCCESS, ARRAY_POINTER_NULL, or INDEX_OUT_OF_BOUNDS.
 */
int array_set_at(int** array_pointer, int index, int value, int array_size);

/**
 * @brief Retrieves the integer payload value located at a validated index offset.
 * 
 * @param[in] array_pointer Double pointer to the underlying buffer.
 * @param[in] index         Zero-based offset position to extract from inside the target boundary.
 * @param[in] array_size    Current dimensional capacity limit of the target array buffer.
 * @return int              Returns the integer payload value if index is valid, or 
 *                          INDEX_OUT_OF_BOUNDS / ARRAY_POINTER_NULL on error.
 */
int array_get_at(int** array_pointer, int index, int array_size);

/**
 * @brief Resets all array elements to zero without unallocating memory blocks.
 * 
 * @param[in,out] array_pointer Double pointer to the target storage buffer.
 * @param[in]     array_size    Total memory footprint size dimension to clear out.
 * @return int                  Returns SUCCESS or ARRAY_POINTER_NULL.
 */
int array_clear(int** array_pointer, int array_size);

/**
 * @brief Instantiates a brand new zero-initialized buffer at a modern capacity scale.
 * 
 * @param[in,out] array_pointer Double pointer tracking the source buffer to update.
 * @param[in]     new_size      The fresh target capacity dimensions requested.
 * @return int                  Returns SUCCESS or ARRAY_POINTER_NULL.
 * 
 * @warning Current layout overwrites the existing handle without freeing structural 
 *          origins, leading to an immediate memory leak. 
 *          Fix proposed in the future scope update.
 */
int array_resize(int** array_pointer, int new_size);

#endif // ARRAY_H
