#ifndef LIST_H
#define LIST_H

typedef struct list_node {
    void* data;
    struct list_node* next;
} list_node;

typedef struct list_head {
    int size;
    struct list_node* next;
} list_head;

/*
int size(list_head* head);
int is_empty(list_head* head);
int contains(list_head* head, void* data);
*/
void add_node(list_head* head, void* data, size_t size);
/*
void remove_item(list_head* head, void* data);
void remove_at_index(list_head* head, int index);
int contains_all(list_head* head, void *data[]);
void add_all(list_head* head, void* data[]);
int index_of(list_head* head, void* data);
int last_index_of(list_head* head, void* data);
*/
void display_list(list_head* head, void (*fptr)(void *));
void print_int(void *n);
void print_float(void *f);

#endif