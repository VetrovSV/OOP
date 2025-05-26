# Бинарные файлы

Пример

```C++

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    const string filename = "data";
    ofstream f(filename, ios::binary);

    srand(42);
    unsigned n = rand()%10 + 5;         // в файл будет записано случайное число данных
    cout << "n = " << n << endl;
    int x;
    for (unsigned i =0; i<n; i++){
        x = rand()%16;
        cout << x << " ";

         // для записи в бинарный файл используется метод write
         // первый параметр -- массив из char; фактически это массив байт, т.к. sizof(char) = 1
         // (char*)&x -- чтение значения по адресу x как массива из 4 (в данном случае) байт
         // второй параметр -- число байт, которые нужно записать в файл
        f.write( (char*)&x, sizeof(x));  
    }

    f.close();

    union file_rec{
        char bytes[4];
        int i;
    };

    ifstream f_read(filename, ios::binary);
    f_read.seekg(0, ios::end);                                  // переход в конец файла (нулевая позиция, считая с конца файла)
    unsigned file_size = f_read.tellg();                        // tellg вернёт размер файла в байтах

    int *arr = new int[ file_size / sizeof(int) ];              // подготовим массив для записи

    cout << endl;
    f_read.seekg(0);                                            // переход обратно в начало файла

    for (unsigned i =0; i<file_size / sizeof(int); i++ ){       // можно использовать цикл while (!f_read.eof())
        f_read.read((char *)&x, sizeof(int));                   // read как и write принимает в первом параметре char*, поэтому преобразуем
        cout << x << " ";
        arr[i] = x;
    }
    f_read.close();
    delete[] arr;
}
```

После запуска программы:
```
n = 11
6 17 9 10 10 1 6 11 5 6 17  
6 17 9 10 10 1 6 11 5 6 17
```

Файл data (в шестнадцатеричной кодировке)
```
0600 0000 1100 0000 0900 0000 0a00 0000
0a00 0000 0100 0000 0600 0000 0b00 0000
0500 0000 0600 0000 1100 0000
```
Один байт в файле здесь обозначен двумя шестнадцатеричными цифрами. Блок из 4 байт -- одно значение типа int. Порядок байтов в файле [[wiki](https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D1%80%D1%8F%D0%B4%D0%BE%D0%BA_%D0%B1%D0%B0%D0%B9%D1%82%D0%BE%D0%B2)] — от младших к старшим (little-endian — с малого конца): `1100 0000` (hex, little-endian) = `0000 0011` (hex, big-endian) = `17` (десятичная система счисления)
