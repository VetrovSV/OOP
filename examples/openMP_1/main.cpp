#include <iostream>
// см. также pro файл

using namespace std;

int main()
{
    // запуск кода в фигурных скобках в 4 потока
    // на экран надпись будет выведена 4 раза
    #pragma omp parallel num_threads(4)
    {
    cout << "Hello, || World!" << endl;
    }

    printf("Done");
    return 0;
}


// Документация OpenMP с примерами:
// https://www.openmp.org/wp-content/uploads/openmp-examples-4.0.2.pdf
