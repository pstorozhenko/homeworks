#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Типы фигур
typedef enum {
    line,
    square,
    right_z,
    left_z,
    right_r,
    left_r,
    like_t,
} figure_types_e;

// Угол поворота фигуры
typedef enum {
    ra_0,
    ra_90,
    ra_180,
    ra_270
} rotation_angle_e;

#pragma pack(1)

// Фигура
typedef struct {
    // Тип фигуры
    figure_types_e type;
    // Позиция фигуры в игровом пространстве
    unsigned char x_pos, y_pos;
    // Угол поворота
    rotation_angle_e rotation_angle;
    // Цвет фигуры
    unsigned int color;
} figure_t;

#pragma pack()

// Создать экземпляр фигуры
figure_t *create_figure(figure_types_e type, unsigned char x_pos, unsigned char y_pos, rotation_angle_e rotation_angle, unsigned int color);
// Удалить экземпляр фигуры
void destroy_figure(figure_t *figure);


#pragma pack(1)

// Игровое пространство
typedef struct {
    // Высота пространства
    unsigned char height;
    // Ширина пространства
    unsigned char width;
    // Осадок
    // bool sediment[10][15];
    bool **sediment; // где sediment указатель на массив указателей
    //динамический массив
} game_space_t;

#pragma pack()

// Создать экземпляр игрового пространства
game_space_t *create_game_space(unsigned char height, unsigned char width);
// Удалить игровое пространство
void destroy_game_space(game_space_t *game_space);



// Запустить игровой цикл
void start_game() {
    game_space_t *game_space = create_game_space(15, 10);
    if(game_space == NULL) { abort(); }

    while(1) {
        //figure_t figure = create_figure(
    }
}

// вспомогательные функции: получение рандома для определения типа фигуры,поворота угла
// и для определения цвета по типу

figure_types_e get_random_value_ft(int max_value_enum);

rotation_angle_e get_random_value_ra(int max_value_enum);

int get_color_by_f_type (figure_types_e type);

// main

int main() {
    //start_game();
     // printf("%d\n", get_random_value(7,"figure_types_e"));//
    printf("%d\n",get_random_value_ft(7));
    printf("%d\n",get_color_by_f_type(line));
     printf("%d\n",rand());
    return 0;
}

// all

figure_t *create_figure(figure_types_e type, unsigned char x_pos, unsigned char y_pos, rotation_angle_e rotation_angle, unsigned int color) {
    figure_t *figure = (figure_t *)malloc(sizeof(figure_t));
    if(figure == NULL) {
        return NULL;
    }

    figure->type = type;
    figure->x_pos = x_pos;
    figure->y_pos = y_pos;
    figure->rotation_angle = rotation_angle;
    figure->color = color;

    return figure;
}

void destroy_figure(figure_t *figure) {
   free(figure);
}


game_space_t *create_game_space(unsigned char height, unsigned char width) {
    game_space_t *game_space = (game_space_t *)malloc(sizeof(game_space_t));
    if(game_space == NULL) {
        return NULL;
    }

    game_space->height = height;
    game_space->width = width;

    memset((void *)game_space, 0, sizeof(bool) * 150);

    return game_space;
}

void destroy_game_space(game_space_t *game_space) {
    free(game_space);
}


figure_types_e get_random_value_ft(int max_value_enum) {
    int random_enum;
    random_enum=rand()%max_value_enum;
    switch(random_enum) {
        case 0: return line;
        case 1: return square;
        case 2: return right_z;
        case 3: return left_z;
        case 4: return right_r;
        case 5: return left_r;
        case 6: return like_t;
     }
 }

rotation_angle_e get_random_value_ra(int max_value_enum) {
    int random_enum;
    random_enum=rand()%max_value_enum;
    switch(random_enum) {
        case 0: return ra_0;
        case 1: return ra_90;
        case 2: return ra_180;
        case 3: return ra_270;
    }
}

int get_color_by_f_type (figure_types_e type) {
    int color;
    if (type == line){ color = 125;}
    else if (type == square){ color = 126;}
    else if (type == right_z){ color = 127;}
    else if (type == left_z){ color = 128;}
    else if (type == left_r){ color = 129;}
    else if (type == like_t){ color = 130;}
    else if (type == right_r){ color = 131;}
    else color = 333;
    return color;
}


