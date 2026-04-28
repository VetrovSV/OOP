// Условный оператор.
// Определить в какой четверти координатной плоскости находится точка (x,y)

#include <stdio.h>

int main(){

    float x, y;     // координаты точки

    printf("x = ");
    scanf("%f", &x);

    printf("y = ");
    scanf("%f", &y);


    if  ( y >= 0 ) {         // положительные Y: I или II
        if  ( x >= 0 ) printf("I четверть");
        else           printf("II четверть");
    } else {                // отрицательные Y: III или IV
        if  ( x >= 0 ) printf("IV четверть");
        else           printf("III четверть");
    }



    puts("");

}
