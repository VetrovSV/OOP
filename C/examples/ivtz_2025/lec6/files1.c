#include <stdio.h>
#include <stdlib.h>
// Дан файл f, компоненты которого являются действительными числами. Найти:
// сумму компонент файла f;


// заполнение файла n случайными числами
void create_random_file(int n){
    FILE* f = fopen("input.txt", "w");
    // f -- файловая переменная, (переменная, через которую работаем с файлом)
    // FILE* -- тип данных: указатель на FILE

    for (int i = 0; i<n; i++){
        float x = 1.0 * rand() / RAND_MAX;
        fprintf(f, "%f ", x );
    }

    fclose(f);      // закрытие файла, гарантирует что все данные в файл будут записаны

}


int main(){

    create_random_file(10'000'000);


    // открыть файл в режиме чтения
    FILE * f = fopen("input.txt", "r");
    double x;
    double S = 0.0;

    while ( ! feof(f) ){
           fscanf(f, "%lf ", &x);
           S = S + x;
    }
    fclose(f);

    printf("Sum = %.3lf", S);


}
