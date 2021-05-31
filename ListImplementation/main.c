#include <stdlib.h>

#include "list.h"

int main(int argc, char** argv) {
    list_head* list = malloc(sizeof(list_head));
    
    unsigned int_size = sizeof(int);
    int arr[] = {10, 20, 30, 40, 50}, i;

    for (i=4; i>=0; i--) {
       add_node(list, &arr[i], int_size);
    }

    display_list(list, print_int);

    list->next = NULL;

    unsigned float_size = sizeof(float);
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
    for (i=4; i>=0; i--) {
       add_node(list, &arr2[i], float_size);
    }

    display_list(list, print_float);

    return 0;
}
