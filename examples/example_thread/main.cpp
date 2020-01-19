#include <math.h>
#include <iostream>

#include <thread>
#include <future>


#include <chrono>

// для использования std::thread нужно дополнительно указать
// что к проекту должна быть присоединена библиотека pthread
// в файле пректа: LIBS += -lpthread


using namespace std;


// функции, которые будут выполнятся в отдельных потоках
void foo(unsigned long n, char c){
    // с - символ обозначающий 10% прогресса
    unsigned long d = n/10;
    double sum = 0;
    for (unsigned i = 0; i<n; i++){
        sum += sin(i);
        if (i%d==0) {cout << c;
                     cout << flush;}}
}


void bar(unsigned long n, double &sum){
    unsigned long d = n/10;
    for (unsigned i = 0; i<n; i++){
        sum += sin(i);
        if (i%d==0) {cout << '*';
                     cout << flush;}}
}





 const unsigned long N = 300000000; // число слагаемых

// Простой пример запуска функции в отдельном потоке
void example1(){
        auto t0 = chrono::system_clock::now(); // пзаомним текущее время, для вычисления времени работы

        // поток - это тоже класс std::thread
        // первый параметр - фказатель на функцию
        // остальные - параметры функции

        // потоки запускаются сразу после создания объекта (если в конструктор был передан указатель на функцию)
        // два вызова функции foo будут выполнены параллельно
        std::thread th1(foo, N, '|');
        std::thread th2(foo, N, '.');

        // ожидание завершения первого, _затем_ второго потока
        th1.join();
        th2.join();
        // см. также detach

        // если не ожидать завершения потоков,
        // то они могут быть завершены раньше времени автоматически
        // в момент, когда завершится основной поток программы

        auto t1 = chrono::system_clock::now();
        cout << endl << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()
                << "ms" <<endl;

        cout << endl;
}



// Пример 2: передача данных в поток по ссылке
void example2(){
    auto t0 = chrono::system_clock::now();
    double sum=0;
    // Передача переменных в функцию потока _всегда_ происходит по значению
    // даже если передаётся ссылка.
    // Поэтому большие данные или данные, которые нужно изменить внутри функции
    // нужно передавать с помощью специальных типов cref или ref.
    std::thread th3(bar, N, std::ref(sum));

    th3.join();
    cout << endl << "sum = " << sum << endl;
    auto t1 = chrono::system_clock::now();
    cout << endl << "dt = " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()
         << "ms" <<endl;
}



float baz(unsigned long n){
    unsigned long d = n/10;
    float sum = 0;
    for (unsigned i = 0; i<n; i++){
        sum += sin(i);
        if (i%d==0) {cout << '.';
                     cout << flush;}}
    return sum;
}

// пример: получение данных из потока
void example3(){

    std::future< float > result;  // объект для хранения будущих данных

    result = std::async( baz, N );  // запуск функции в отдельном потоке

    result.wait();  // ожидание завершения потока

    cout << "\nsum = " << result.get() << endl; // получение и вывод результата

}





int main(){


//    example1();
//    example2();
    example3();

    return 0;
}


// https://habr.com/post/182610/

// https://en.cppreference.com/w/cpp/thread
// см. также функции
// yield
// get_id
// sleep_for
