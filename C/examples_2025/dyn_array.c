#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Для массива a1 ... an вычислить сумму элементов
*/

// ...
void print_array(float* array, unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
}

void fill_array_random(float* array, unsigned size) {
    // заполнение массива
    for (unsigned i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}


float* create_array_zero(unsigned size) {
    // динамический массив из элементов типа float
    // malloc - функция для динамического выделения памяти
    // n * sizeof(float) - размер пармяти в байтах
    // sizeof(float) - размер значения типа float в байтах
    float* arr = malloc(size * sizeof(float));
    arr = NULL;

    // Проверка: если NULL не удалось выделять память
    if (arr == NULL) {
        puts("не дулось выделить память\n");
        return NULL;
    }

    memset(arr, 0, size * sizeof(float));           // ???
    return arr;

}


int main() {

    unsigned n = 0;
    puts("введите размер массива");
    scanf_s("%u", &n);
    
    
    float* arr = create_array_zero(n);

    printf("Memory allocated: %llu\n", n * sizeof( float  ));

    print_array(arr, n);
    puts("");

    // заполнение массива
    fill_array_random(arr, n);

    puts("");
    print_array(arr, n);

    // освобождения памяти
    free(arr);
    arr = NULL;

    // почему код возврата не ноль?

    return 0;

}

