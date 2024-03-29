#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SIZE 100

// Vector
typedef void * vector_t;

// Forward List
typedef struct forward_list_t forward_list_t;

struct forward_list_t {
    forward_list_t *next;
    void *data;
};

// init list
forward_list_t *forward_list_init(forward_list_t *last, void *data);
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
// out to print
void list_print(forward_list_t*, const char*);
// сортировать список слиянием
forward_list_t *list_merge_sort(forward_list_t*, int);
// пропускает n первых элементов списка
forward_list_t *list_skip(forward_list_t *head, int n);
// список с пандомными значениями
forward_list_t *list_randomize(int size);
// добавление элемента после с заполнением значения
forward_list_t *list_insert_after_with_value(forward_list_t*, int);

int main()
{

    forward_list_t *head;
    head = list_randomize(LIST_SIZE);
    list_print(head, "До сортировки\n");
    head = list_merge_sort(head, LIST_SIZE);
    list_print(head, "После сортировки\n");
    // здесь будет функция освоб памяти
    return 0;
}

// init list
forward_list_t *forward_list_create(){
    // выделяем память под создание списка
    forward_list_t *new_item = (forward_list_t *)malloc(sizeof(forward_list_t));
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
forward_list_t *list_insert_after_with_value(forward_list_t *head, int value) {
    forward_list_t *tmp;
    tmp = malloc(sizeof(forward_list_t));
    tmp->next = head->next;
    tmp->data = malloc(sizeof(int));
    *(int*)tmp->data = value;
    head->next = tmp;
    return tmp;
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
    forward_list_t *tail;//= (forward_list_t *)malloc(sizeof(forward_list_t));
    tail = head;
    while (tail->next != NULL){ // просматриваем список начиная с корня
        tail = tail->next;
    }
    forward_list_t *new_item = forward_list_create();
    if (new_item == NULL) {
        return NULL;
    }
    tail->next = new_item;
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

    return item->next;
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

// вывод на печать
void list_print(forward_list_t *head, const char* header) {
    printf("%s", header);
    for (int i = 1; head; i++, head = head->next) {
        printf("%d: %d\n", i, *(int*)head->data);
    }
}

// пропускает n первых элементов списка
forward_list_t *list_skip(forward_list_t *head, int n) {
    for (int i = 0; i < n; i++, head = head->next) {
        if (!head)
            return NULL;
    }
    return head;
}

// сортировка
forward_list_t *list_merge_sort(forward_list_t* head, int size) {
    if (size <= 1) {
        if (size == 0)
            return 0;
        // Список длиной 1, удостоверимся, что отцепим всё, что правее
        // Это облегчит слияние
        head->next = NULL;
        return head;
    }
    int mid, posleft = 0, posright = 0;
        forward_list_t tmphead = { NULL, NULL };
        forward_list_t *left, *right, *last = &tmphead; // конец нового списка

        mid = size / 2;
        // отсортируем сначала правую часть, т.к. далее её отцепят от левой, и мы до неё не сможем дойти
        right = list_merge_sort(list_skip(head, mid), size - mid);
        left = list_merge_sort(head, mid);
        // после операций выше у нас получится два отсортированных списка, не связанных друг с другом
        // делаем слияние
        while (posleft < mid && posright < size - mid) { // пока не дойдем до конца одного из списков
                if (*(int*)left->data < *(int*)right->data) {
                    last->next = left; // слева меньше, цепляем к концу
                    left = left->next; // смещаем левый список
                    posleft++;
                } else {
                    last->next = right; // справа меньше, цепляем к концу
                    right = right->next; // смещаем правый список
                    posright++;
                }
                last = last->next; // смещаем конец нового списка
                  }
                  last->next = left ? left : right; // прицепляем тот список, в котором что-то осталось

                  return tmphead.next;
              }
// Вставить новый элемент после указанного (создаёт новый элемент списка и помещает его после item)
forward_list_t *list_randomize(int size) {
    time_t t;
    forward_list_t head = { NULL, NULL };
    forward_list_t *last = &head;

    srand(time(&t));
    for (int i = 0; i < size; i++) {
        last = list_insert_after_with_value(last, rand() % 100);
    }
    return head.next;
}
