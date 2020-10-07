#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// возвращает кол-во строк в файле
// возвращает -1 если к файлу нет доступа
long count_lines(const string &filename){
    string line;
    ifstream f(filename);
    if (f.is_open()){
        unsigned n = 0;
        while (std::getline(f, line))
            n++;
        return n;}
    else return -1;
}


// возвращает кол-во строк в файле
// бросает исключение 1 если нет доступа к файлу
unsigned count_lines2(const string &filename){
    string line;
    ifstream f(filename);
    if (f.is_open()){
        unsigned n = 0;
        while (std::getline(f, line))
            n++;
        return n;}
    else throw 1;
}



void zero_vector(vector<int> &v){
    for (unsigned i = 0; i<v.size(); i++){
        v[i] = 0;
    }
}

// a - мин значение сл.числа
// b - мин значение сл.числа
void rnd_vector(vector<int> &v, int a=0, int b=0){
    for (unsigned i = 0; i<v.size(); i++){
        v[i] = rand() % (b-a) + a;
    }
}


void print_vector(const vector<int> &v){
    for (unsigned i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}


int main()
{
    string filename = "../lec55555555555555555555555555555555555555555_4/main.cpp";
    long n;

    // Обработка искл. ситуаций. Способ 1.
    n = count_lines(filename);
    if (n == -1)
        cout << "Ошибка чтения файла "<< filename;
    else
        cout << "Число строк в файле " << filename << ": " << n;

    // Обработка искл. ситуаций. Способ 2. Рекомендуемый
    try {
        n = count_lines(filename);
        cout << "Число строк в файле " << filename << ": " << n;
    } catch (int e) {
        cout << "Ошибка чтения файла "<< filename;
    }


//    vector<int> arr(100000);
//    arr[4] = 42;

//    zero_vector(arr);

//    rnd_vector(arr, 6);

//    print_vector(arr);

    return 0;
}
