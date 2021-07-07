#include <stdio.h>

// Vector
typedef void * vector_t;


// Forward List
typedef struct forward_list_t forward_list_t;

struct forward_list_t {
    forward_list_t *next;
    void *data;
};

forward_list_t *forward_list_create();
void forward_list_destroy(forward_list_t *head);
void forward_list_add(forward_list_t *item);
void forward_list_insert(forward_list_t *item);
void forward_list_remove(forward_list_t *item);
forward_list_t *forward_list_next(forward_list_t *item);


// List
typedef struct list_t list_t;

struct list_t {
    list_t *prev;
    list_t *next;
    void *data;
};

list_t *list_create();
void list_destroy(list_t *head);
void list_add(list_t *item);
void list_insert(list_t *item);
void list_remove(list_t *item);
list_t *list_next(list_t *item);
list_t *list_prev(list_t *item);



int main()
{


    return 0;
}
