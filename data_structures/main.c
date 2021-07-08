#include <stdio.h>

// Vector
typedef void * vector_t;


// Forward List
typedef struct forward_list_t forward_list_t;

struct forward_list_t {
    forward_list_t *next;
    void *data;
};

// Создать новый список (создаёт один элемент списка)
forward_list_t *forward_list_create();
// Удалить список (удаляет все элементы списка)
void forward_list_destroy(forward_list_t *head);
// Получить размер списка
unsigned long forward_list_size(forward_list_t *head);
// Изменить размер списока (лишние элементы удаляются, нехватающие создаются)
void forward_list_resize(forward_list_t *head, unsigned long size);
// Добавить новый элемент в конец списка (создаёт новый элемент списка и помещает его в конец)
forward_list_t *forward_list_append(forward_list_t *head);
// Вставить новый элемент после указанного (создаёт новый элемент списка и помещает его после item)
forward_list_t *forward_list_insert(forward_list_t *item);
// Удалить элемент из списка
void forward_list_remove(forward_list_t *item);
// Получить указатель на следующий элемент списка
forward_list_t *forward_list_next(forward_list_t *item);


// List
typedef struct list_t list_t;

struct list_t {
    list_t *prev;
    list_t *next;
    void *data;
};

// Создать новый список (создаёт один элемент списка)
list_t *list_create();
// Удалить список (удаляет все элементы списка)
void list_destroy(list_t *head);
// Получить размер списка
unsigned long list_size(list_t *head);
// Изменить размер списока (лишние элементы удаляются, нехватающие создаются)
void list_resize(list_t *head, unsigned long size);
// Добавить новый элемент в конец списка (создаёт новый элемент списка и помещает его в конец)
list_t *list_append(list_t *head);
// Вставить новый элемент после указанного (создаёт новый элемент списка и помещает его после item)
list_t *list_insert(list_t *item);
// Удалить элемент из списка
void list_remove(list_t *item);
// Получить указатель на следующий элемент списка
list_t *list_next(list_t *item);
// Получить указатель на предыдущий элемент списка
list_t *list_prev(list_t *item);


int main()
{

    return 0;
}
