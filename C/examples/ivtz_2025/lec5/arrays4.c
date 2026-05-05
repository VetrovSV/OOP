// Вложенные циклы.
// Заполнить массив уникальными значениями (сделать массив без повторов)
// Для поиска повторов использовать алгоритм поиска элемента в массиве.


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <time.h>



int main(){

    srand( time(0) );       // инициализация генератора случайных чисел текущем временем (в сек.)

    // time(0)  -> текущее время в секундах
    const int N = 1024;

    int arr[N];

    int n = 10;

    // for (int i = 0; i<n; i++){
    //     arr[i] = rand() % 20;
    // }

    // for (int i = 0; i<n; i++){
    //     printf("%d  ", arr[i]);}
    // puts("");

    int target = 5; // что ищем
    int target_i = -1;       // индекс найденного элемента


    arr[0] = rand() % 20;
    int m = 1;                  // количество заполненных элементов

    printf("arr[0] = %d\n", arr[0]);

    puts("Начало цикла генерации случайного массива из уникальных чисел");
    while ( m != n ){        // пока массив не заполнен до конца (пока там меньше n элементов)
        // while ( m != n ) -- внешний цикл
        int x = rand() % 20;
        printf("rand: x = %d ", x);

        // Алгоритм последовательного поиска числа в массиве
        target_i = -1;
        // for (int i = 0; i<m; i++) -- внутр. цикл
        for (int i = 0; i<m; i++){
            if ( x == arr[i] ) {
                target_i = i;
                break;
            }
        }

        // если число x не нашлось в массиве
        if (target_i == -1){
            arr[m] = x;
            printf("\nДобавим %d в массив на позицию %d\n", x, m);
            m = m + 1;
        }
    }

    if ( target_i != -1)
        printf("Элемент %d найден по индексу %d",target, target_i);
    else
        printf("Элемент %d не найден",target);

    puts("");puts("");


    for (int i = 0; i<n; i++){
        printf("%d  ", arr[i]);}
    puts("");



}
