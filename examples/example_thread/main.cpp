#include <iostream>
#include <thread>
#include <math.h>

#include <time.h>

// для использования std::thread нужно дополнительно указать
// что к проекту должна быть присоединена библиотека pthread
// в файле пректа: LIBS += -lpthread


using namespace std;

void foo(unsigned long n, char c){
    // с - символ обозначающий 10% прогресса
    unsigned d = n/10;
    float sum = 0;
    for (unsigned i = 0; i<n; i++){
        sum += sin(i);
        if (i%d==0) {cout << c;
                     cout << flush;}}
}


void bar(unsigned long n, float &sum){
    unsigned d = n/10;
    for (unsigned i = 0; i<n; i++){
        sum += sin(i);
        if (i%d==0) {cout << '*';
                     cout << flush;}}
}


int main(){

    unsigned t0 = time(NULL); // для вычисления времени работы


    unsigned long N = 300000000;

    // поток - это тоже класс
    // первый параметр - функция
    // остальные - параметры функции

    // потоки запускаются немедленно
    // два вызова функции foo будут выполнены параллельно
    std::thread th1(foo, N, '|');
    std::thread th2(foo, N, '.');

    // ожидание завершения первого, _затем_ второго потока
    th1.join();
    th2.join();

    cout << endl << "dt = " << time(NULL) - t0 << endl;

    // если не ожидать завершения потоков,
    // то они могут быть завершены раньше времени автоматически
    // в момент, когда завершится основной поток программы

    cout << endl;

    t0 = time(NULL);

    float sum=0;
    std::thread th3(bar, N, std::ref(sum));

    th3.join();
    cout << endl << "sum = " << sum << endl;
    cout << endl << "dt = " << time(NULL) - t0 << endl;

    return 0;
}


// https://habr.com/post/182610/

// Для измерения времени работы использовать более точную функцию clock() не стоит,
// т.к. она измеряет время потраченное процессоров на выполнение процесса.
// Два потока пропорционально его увеличат.
// https://stackoverflow.com/questions/2962785/c-using-clock-to-measure-time-in-multi-threaded-programs
