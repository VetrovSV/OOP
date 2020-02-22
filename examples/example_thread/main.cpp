#include <math.h>
#include <iostream>

#include <thread>
#include <future>

// для предачи функции как параметра
#include <functional>


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

    // ...

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

// пример 3: получение данных из потока
void example3(){

    std::future< float > result;  // объект для хранения будущих данных

    result = std::async( baz, N );  // запуск функции в отдельном потоке

    // ...

    result.wait();  // ожидание завершения потока

    cout << "\nsum = " << result.get() << endl; // получение и вывод результата

}

void bar2(unsigned n, void(*callback)(float s)  ){
    // указатель на функцию можено передавать и через класс-обёртку std::function
    float sum = 0;
    for (unsigned i = 0; i<n; i++)
        sum += sin(i);

    callback(sum);
}


void bar2_done(float sum){
    cout << "sum = " << sum << endl;
}


// Пример 4: Вызов callback функции из потока
void example4(){
    // Если по завершении потока нужно выполнить определённое действие,
    // при этом не дожидаясь завершения этого нового потока в основном (не использую join)
    // то в цункцию можно передать адрес другой функции, которая и выполнит необхоимые действия
    unsigned n = 1000;
    std::thread th(bar2, n, bar2_done);

    // здесь вызывается join только для того,
    // чтобы основной поток не завершился раньше вновь созданного
    th.join();
}




int main(){


//    example1();  // Пример 1: запуск функции в отдельном потоке
//    example2();  // Пример 2: передача данных в поток по ссылке
//    example3();  // Пример 3: получение данных из потока
    example4();  // Пример 4: Вызов callback функции

    return 0;
}


// https://habr.com/post/182610/

// https://en.cppreference.com/w/cpp/thread
// см. также функции
// yield
// get_id
// sleep_for
