#include "librxdsa.h"

int main() {
    int retcode;
    retcode = array_hello();
    printf("array_hello %d\n", retcode);
    
    int* arr;
    retcode = array_init(&arr, 11);
    printf("array_init %d\n", retcode);

    retcode = array_set_at(&arr, 5, 456, 11);
    printf("array_set_at %d\n", retcode);

    retcode = array_get_at(&arr, 5, 11);
    printf("array_get_at %d\n", retcode);




    return 0;
}