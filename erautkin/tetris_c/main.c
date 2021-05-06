#include <stdio.h>
#include <stdbool.h>

#pragma pack(1)

/* число вариантов расположения фигуры в прстранстве */
enum num_pos_in_space {
        line = 2,
        square = 1,
        left_z = 2,
        right_z = 2,
        left_corner = 4,
        right_corner = 4,
        t = 4
};

/* цвет клетки */
struct _color{
    int count;
    char *color;
} keytab [] = {
    {0, "not_filled"},
    {1, "yellow"},
    {2, "red"},
    {3, "blue"},
    {4, "orange"},
    {5, "purple"},
    {6, "gray"},
    {7, "green"}
};

/* фигура */
typedef struct {
   bool form[4][4]; /* базовый двумерный массив, 4*4, клетки которого могут быть заполнены или нет */
   unsigned char x, y;
   char figure_name;
} figure_v1_t;

/* игровое поле */
typedef struct {
unsigned char fields_table [10][15]; /* размер поля */
bool color_or_not; /* клеточка может быть заполнена или нет */
} game_zone_t;

/* определение клетки игр поля, размер в пикселях, точки
 вершин и координаты этих точек */
typedef struct {
short int size;
struct base_field {
unsigned char x,y;
} a,b;
} field_of_game_zone;

int main()
{
    printf("size of figure_v1_t: %d\n", sizeof(figure_v1_t));

    return 0;
}
