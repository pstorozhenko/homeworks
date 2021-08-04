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

// init list
forward_list_t *list_init(forward_list_t *last, void *data);

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
void forward_list_remove(forward_list_t *item, forward_list_t *head);

// Получить указатель на следующий элемент списка
forward_list_t *forward_list_next(forward_list_t *item);

// заполнить данными элемент списка
int *forward_list_set_int_data(forward_list_t *item, int value);

// создать список с рандомными значениями в данных
forward_list_t *forward_list_create_with_rand_int(unsigned long size);

int main()
{
    //forward_list_t head = { NULL, NULL };
    //forward_list_t *last = &head;
    //for (int i = 1; i < 10000000; i++) {
     // last = list_init(last, i);
    // }
    //printf("ptr head: %d",forward_list_create());
    printf("%d\n", rand());
      printf("%d\n", rand());
      printf("%d\n", rand());
      printf("%d\n", rand());
      printf("%d\n", rand());
      forward_list_create_with_rand_int(1000);
    return 0;
}

// init list

forward_list_t *forward_list_create(){
    // выделяем память под создание списка
    forward_list_t *new_item=(forward_list_t *)malloc(sizeof(forward_list_t));
    if(new_item == NULL) {
            return NULL;
        }
    // обращаемся к члену структуры  - указателю на след эл списка для
    // присвоения значения NULL
    new_item->next=NULL;
    new_item->data=NULL;
    return new_item;
    }

// создать список с рандомными значениями в данных
forward_list_t *forward_list_create_with_rand_int(unsigned long size) {
    forward_list_t *head=forward_list_create();
    if (head == NULL) {
        return NULL;
        }
    /* Initial random number generator. */
    srand(1);
    int value = rand();
    int *ptr_value = forward_list_set_int_data(head,value);
    if (ptr_value == NULL) {
       return NULL;
        }
    forward_list_t *new_item = forward_list_append(head);
    for (unsigned long i = 1; i < size; ++i){
            // get next elem
            new_item = forward_list_append(new_item);
            int value = rand();
            int val_in_data = *(forward_list_set_int_data(new_item,value));
            printf("%d ", val_in_data);
        }
    return new_item;
    }

// заполнить данными элемент списка
int *forward_list_set_int_data(forward_list_t *item, int value) {
    item->data = (int *)malloc(sizeof(int));
    if (item->data == NULL) {
        return NULL;
        }
    *((int *)(item->data)) = value;
    return (int *)(item->data);
    }

// Получить размер списка
unsigned long forward_list_size(forward_list_t *head) {
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
    unsigned long f_list_size = i;
    return f_list_size;
}
// ! Здесь получить количество элементов а не размер

void forward_list_resize(forward_list_t *head, unsigned long size){
    unsigned long f_list_size = forward_list_size(head);
    unsigned long diffrence = 0;
    if (f_list_size < size){
        // add item
        diffrence = size - f_list_size;
        for ( unsigned long i = 0; i == diffrence; ++i){
            forward_list_append(head);
            }
        }
    else if(f_list_size > size){
        //remove item
        diffrence = f_list_size - size;
        for ( unsigned long i = 0; i == diffrence; ++i){
            forward_list_t *last;
            last = head;
            while (last->next != NULL) {
                last = last->next;
                }
            forward_list_remove(last,head);
            }
        }
    else    {
        //return f_list_size;

        }
    }

forward_list_t *forward_list_append(forward_list_t *head){
    forward_list_t *item ;//= (forward_list_t *)malloc(sizeof(forward_list_t));
    item = head;
    while (item->next != NULL){ // просматриваем список начиная с корня
        item = item->next;
      }
    forward_list_t *new_item = forward_list_create();
    item->next = new_item;
    return new_item;
}

// Вставить новый элемент после указанного (создаёт новый элемент списка и помещает его после item)
forward_list_t *forward_list_insert(forward_list_t *item){
    forward_list_t *new_item = forward_list_create();
    forward_list_t *temp;
    temp = item->next; // сохранение указателя на after
    item->next=new_item; // перестановка указателя before на добавляемый
    new_item->next = temp; // и добавляемый на after ранее сохранённый
    return new_item;
}

// Удалить элемент из списка
void forward_list_remove(forward_list_t *item, forward_list_t *head){
    forward_list_t *temp;
    temp = head;
    while (temp->next != item){ // просматриваем список начиная с корня
      // пока не найдем узел, предшествующий
        temp = temp->next;
      }
      temp->next = item->next; // переставляем указатель
      free(item); // освобождаем память удаляемого узла
      return; // должна возвращать указатель  на элемент пред item элемент
      // либо NULL если удалили head //

}

// Получить указатель на следующий элемент списка
forward_list_t *forward_list_next(forward_list_t *item){
    forward_list_t *next_item=(forward_list_t *)malloc(sizeof(forward_list_t));
    if(next_item == NULL) {
            return NULL;
        }
    next_item = item->next;
    return next_item;
  }

// Удалить список (удаляет все элементы списка)
void forward_list_destroy(forward_list_t *head){
  forward_list_t *temp;
  temp = head; // новый корень списка
  free(head); // освобождение памяти текущего корня
  while (head ->next !=NULL) {
      temp = forward_list_next(head);
      free(head);
      head = temp;
    }
  free(head);
}
