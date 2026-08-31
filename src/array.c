#include "array.h"

int array_hello() {
    printf("Array says Hi!\n");
    return SUCCESS;
}

int array_init(int** array_pointer, int array_size) {
    if (array_pointer == NULL) return ARRAY_POINTER_NULL; 
    *array_pointer = (int*) calloc(array_size, sizeof(int));
    return SUCCESS;
}

int array_set_at(int **array_pointer, int index, int value, int array_size) {
    if (array_pointer == NULL) return ARRAY_POINTER_NULL;
    if (index >= array_size) {
        printf("Index %d out of bounds for array of size %d\n", index, array_size);
        return INDEX_OUT_OF_BOUNDS;
    }
    *(*array_pointer + index) = value;
    return SUCCESS; 
}

int array_get_at(int** array_pointer, int index, int array_size) {
    if (array_pointer == NULL) return ARRAY_POINTER_NULL;
    if (index >= array_size) {
        printf("Index %d out of bounds for array of size %d\n", index, array_size);
        return INDEX_OUT_OF_BOUNDS;        
    }
    return *(*array_pointer + index);
}


int array_clear(int **array_pointer, int array_size) {
    if (array_pointer == NULL) return ARRAY_POINTER_NULL;
    memset(array_pointer, 0, array_size);
    return SUCCESS;
}

int array_resize(int **array_pointer, int new_size) {
    if (array_pointer == NULL) return ARRAY_POINTER_NULL;
    *array_pointer = (int*) calloc(new_size, sizeof(int));
    return SUCCESS;
}

// FUTURE SCOPE

// array_free
// array_print
// array_push (uses array_resize if array_full)
// array_pop
// array_insert
// array_remove
// array_find (linear / binary search)
// array_reverse
// array_sort (all sorting algorithms)