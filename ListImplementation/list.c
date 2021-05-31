#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int size(list_head* head) {
    return head->size;
}

/*
int is_empty(list_head* head) {
    if (head->size == 0) return 1;

    return 0;
}

int contains(list_head* head, void* data) {
    if (head->size == 0) return 0;
    
    list_node* cur_node = head->next;
    while (cur_node != NULL) {
        if (cur_node->(*data) == (*data)) {

        }
        cur_node = cur_node->next;
    }

    return 0;
}
*/

void add_node(list_head* head, void* data, size_t size) {
    list_node* to_add = malloc(sizeof(list_node));
    to_add->data = malloc(size);
    to_add->next = NULL;

    for (int i = 0; i < size; i++) {
        *(char *)(to_add->data + i) = *(char *)(to_add + i);
    }


    if (head->next == NULL) {

        head->next = to_add;
        head->size++;
        return;
    }

    list_node* cur_node = head->next;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }

    cur_node->next = to_add;

    return;
}

/*
void remove_item(list_head* head, void* data) {
    if (head->size == 0) return;

    list_node* cur_node = head->next;

    while (cur_node != NULL) {
        if (cur_node->data == data) {
            // TODO
        }
    }
}

void remove_at_index(list_head* head, int index) {
    if (head->size < index - 1) return;
}

int contains_all(list_head* head, void *data[]) {
    int i = 0;
    while (data[i] != '\0') {
        if (contains(head, data[i]) == 0) return 0;
    }

    return 1;
}

void add_all(list_head* head, void *data[]) {
    int i = 0;
    while (data[i] != '\0') {
        add_node(head, data[i]);
    }
}

int index_of(list_head* head, void* data) {
    if (head->size == 0) return -1;

    list_node* cur_node = head->next;
    int index = 0;

    while (cur_node != NULL) {
        if (cur_node->data == data) {
            return index;
        }

        cur_node = cur_node->next;
        index++;
    }

    return -1;
}

int last_index_of(list_head* head, void* data) {
    if (head->next == NULL) return -1;

    list_node* cur_node = head->next;

    int index = -1;
    int i = 0;

    while (cur_node != NULL) {
        if (cur_node->data == data) index = i;

        i++;
        cur_node = cur_node->next;
    }

    return index;
}
*/

void display_list(list_head* head, void (*fptr)(void *)) {
    if (head->next == NULL) return;

    list_node* cur_node = head->next;

    while (cur_node != NULL)
    {
        (*fptr)(cur_node->data);
        cur_node = cur_node->next;
    }
}

void print_int(void *n)
{
   printf(" %d", *(int *)n);
}
  
void print_float(void *f)
{
   printf(" %f", *(float *)f);
}