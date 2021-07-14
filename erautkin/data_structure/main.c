#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    char h = 0;
    printf("ptr head: %d",forward_list_create());
    return 0;
}

forward_list_t *forward_list_create(){
    // выделяем память под создание списка
    forward_list_t *new_item=(forward_list_t *)malloc(sizeof(forward_list_t));
    if(new_item == NULL) {
            return NULL;
        }
    // обращаемся к члену структуры  - указателю на след эл списка для
    // присвоения значения NULL
    new_item->next=NULL;
    new_item->data;
    return new_item;
}

// Получить размер списка
unsigned long forward_list_size(forward_list_t *head) {
    //forward_list_t *item = (forward_list_t *)malloc(sizeof(forward_list_t));
    //объявляем переменную типа списка
    forward_list_t *item;
    // присваиваем переменной значение первого элемента списка
    item = head;
    int i = 0;
    // проходим по циклу до тех пор пока не достигнем
    // посл элемента, знаем, что его указатель на след эл будет указывать на NULL
    do { ++i;
        item = item->next;
    } while (item != NULL);
    unsigned long f_list_size = i * sizeof(forward_list_t);
    return f_list_size;
}

void forward_list_resize(forward_list_t *head, unsigned long size){
    unsigned long list_size = forward_list_size(head) / sizeof(forward_list_t);
    forward_list_t *last;
    forward_list_t *new = (forward_list_t *)malloc(sizeof(forward_list_t));
    if (list_size < size){
        int n = size - list_size;
        last = head;
        for (int i=0; i < n; ++i ){
            int i = 0;
            do { ++i;
            last = head->next;
            } while (last != NULL);
            last->next=new;
            new->next=NULL;
            new->data;

         }

    }


}

void forward_list_destroy(forward_list_t *head);


forward_list_t *forward_list_append(forward_list_t *head){
    forward_list_t *item = (forward_list_t *)malloc(sizeof(forward_list_t));
    item = head;
    while (item->next != NULL) // просматриваем список начиная с корня
      {
        item = item->next;
      }
    forward_list_t *new_item = forward_list_create();
    item->next = new_item;
    return new_item;
}

forward_list_t *forward_list_insert(forward_list_t *item){
    forward_list_t *new_item = (forward_list_t *)malloc(sizeof(forward_list_t));
    forward_list_t *ptr_after;
    ptr_after = item->next; // сохранение указателя на after
    item->next=new_item; // перестановка указателя before на добавляемый
    new_item->next = ptr_after; // и добавляемый на after ранее сохранённый
    return new_item;
}

