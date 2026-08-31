#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDEX_OUT_OF_BOUNDS -1
#define ARRAY_POINTER_NULL -1
#define SUCCESS 0

int array_hello();
int array_init(int** array_pointer, int array_size);
int array_clear(int **array_pointer, int array_size);
int array_resize(int **array_pointer, int new_size);
int array_set_at(int **array_pointer, int index, int value, int array_size);
int array_get_at(int** array_pointer, int index, int array_size);

#endif // ARRAY_H