# 1. C++. Простая программа, компиляция в консоли, отчёт

1. Решите любую задачу из первого раздала [задачника](https://ivtipm.github.io/Programming/Files/spisocall.htm) согласно своему варианту или предложите свою задачу (нужно согласовать с преподавателем).
1. Создайте *отчёт* о компилировании программ в консоли (PowerShell). 
    - Начните с этапа добавления пути к компилятору в переменную среды окружения Path.
   - Коротко опишите самые самое важное для работы в консоли: программы cd, ls, как работает автодополнение, обращение к предыдущим командам.
1. Создайте отдельную функцию для вычислений. Вынесите её в отдельный модуль (h и cpp файлы).
1. Сделайте автоматическое тестирование программы с помощью макроса `assert`. Для функций, вычисляющий значений сделайте минимум три проверки. Рассмотрите крайние случаи. Напишите поясняющие комментарии.
1. *Бонус: Выясните как уменьшить размер исполняемого файла, создаваемого компилятором MinGW (GCC).* Дополните отчёт.
8. *Бонус: скомпилируйте cpp файл модуля в статическую библиотеку. Дополните отчёт.*
[Пример: simple_lib](https://github.com/VetrovSV/OOP/tree/master/examples/example_libs/simple_lib)
9. *Бонус: Добавьте в программу интерфейс командной строки (используйте параметр `argv`).*
    - *Выдавайте подсказку если пользователь передал аргумент `help` или `--help`. Если аргументы не переданы, то запрашивайте данные как обычно, через `cin`. Если программа запущена с необходимыми аргументами, используйте их вместо отдельного запроса данных через `cin`*.
    - Обязательный пункт: сделайте отчёт\конспект о работе с аргументами командной строки в программах на языке C++
1. Конспект: Этапы компиляции программы на C++.
1. Конспект. Выберете рекомендации по стилю кодирования (styles guidelines) на C++, которые нравятся вам. Приведите в конспекте наиболее важные и часто используемые рекомендации.
1. Раздобудьте 2+ книги по C++ не старше 5 лет.  

**Критерии оценки**
- корректные идентификаторы, 
- понятный пользовательский интерфейс, 
- указан автор программы, есть комментарии и документация (см. примеры документации функции: [StudBook.pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#subsection.1.4.6))

### Настройка компилятора и компиляция
1. Запустите PowerShell. Изучите переменную окружения Path: выполните команду для отображения переменной среды окружения:
```$env:path```\
Есть ли там путь к компилятору MinGW (GCC)? Если нет, то добавьте через программу настройки "Изменение переменных среды окружения текущего пользователя".
Если установлен фреимвок Qt, то компилятор MinGW (GCC) можно найти по адресу: `C:\Qt\Tools\mingw810_64\bin`. Если нет, то компилятор MinGW64 можно скачать здесь: https://www.mingw-w64.org/downloads/: MingW-W64-builds > Installation: GitHub >
x86_64-XX.X.X-release-posix-xxxxxx.7z ( https://github.com/niXman/mingw-builds-binaries/releases )

2. Определите версию С++ компилятора из GCC:\
```g++ --version```
3. Создайте в Sublime Text файл с расширением cpp и исходным кодом простой программы на C++:
```C++
#include <iostream>

using namespace std;

int main(){
    cout << "Hello, World!" << endl;
    return 0;
}
```
4. Скомпилируйте и запустите программу:\
```g++ имя-файла-с-иходным-кодом -o имя-exe-файла```\
```./имя-exe-файла```

Подробнее: https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#section.1.10

### Дополнительно

**Математические константы в С++20**
В стандарте С++20 введена библиотека математических констант `numbers`: https://en.cppreference.com/w/cpp/numeric/constants.
```C++
#include <numbers>
using std::numbers::pi;

float pizza_area = pi * 35*35;
```

**Компиляция с указанием версии языка**
```bash
g++ main.cpp -o main.exe -std=c++20
```

**Оптимизация и размер файла**

Размер исполняемого файла после компиляции может показаться избыточным. Это происходит из-за включения в файл всех подключаемых библиотек -- статическая линковка (см. этапы компиляции программы на C++).

**Настройка вывода**
Задать число знаков после запятой при выводе в консоль:
```C++
#include <iomanip>

// вызвать в программе один раз, перед выводом чисел
cout << 3000000.14159265 << ";"; // вывод:3e+06;
cout << setw(12) << fixed << setprecision(2); // 12 позиций на всё число; человекочитаемый формат (без e); два знака после запятой
cout << 3000000.14159265 << ";"; // вывод: 3000000.14; (2 пробела в начале)
https://www.cplusplus.com/reference/iomanip/setprecision/

# include <string>
// преобразование числа в строку с помощью функции форматирования строки
string s = format("{:.3f}", 3000000.14159265); // {:.3f} - формат вывода вещественного (f) числа с 3 знаками после запятой
// https://en.cppreference.com/w/cpp/utility/format/format
```

### Автоматическое тестирование функций
Разбейте программу с предыдущего занятия на функции. Создайте тестовую функцию с помощью оператора assert.

Для проверки вещественных значений проверяйте модуль ошибки вычислений вашей функции, а не точное значение. 

Пример
``` C++
#include <iostream>

// раскомментировать строку ниже, чтобы отключить assert()
// #define NDEBUG
#include <cassert> // для assert
// все assert отключатся если скомпилировать программу в режиме выпуска (release)

#define _USE_MATH_DEFINES // вкл. математические константы
#include <math.h> // модуль с математическими константами и функциями

// функция вычисления гипотенузы треугольника с катетами a и b
float calc_c(float a, float b) {
    // todo: вынести в отдельный модуль
    return sqrt(a*a + b*b);
}

int main(){ 

    // проверка работы функции
    // если внутри оператора assert будет ЛОЖЬ, то программа аварийно завершит работу
    // такие проверки позволяют легко заметить ошибки в коде, особенно когда
    // проверяемые функция во время разработки часто модифицируются, оптимизируются
    assert(fabs(calc_c(3, 4) - 5.0) < FLT_EPSILON);
    // в C++ невозможно корректное сравнение вещественных чисел на равенство без округления
    // например sin(M_PI) = 1.224647e-16, хотя в идеале должен быть 0
    // Поэтому в assert проверяется не точное значение, а проверяется модуль ошибки вычислений вашей функции. Он должен быть меньше некоторого допустимого порога, например FLT_EPSILON (1.192092896e-07) -- наименьшее значение числа, которое можно сохранить во float.

    assert(fabs(calc_c(1.5, 1) - 1.8027756) < FLT_EPSILON);

    assert(fabs(calc_c(500.0, 501.0) - 707.8142412) < FLT_EPSILON*1000); // возьмём точность порядка 10^-4

    // далее основная работа программы
    // ...
    }

```

Подробнее: https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#subsection.2.2.6


# 2. Работа с массивами, файлами, исключительными ситуациями
1. Сделайте задачу из 15 строки задачника:
    - https://ivtipm.github.io/Programming/Files/spisocall.htm
    - можно предложить свою задачу с массивами (согласуйте с преподавателем)
    - используйте динамические массивы
1. Создайте пространство имён для модуля.
1. Создайте функции для записи массива в файл, для заполнения массива из файла с произвольным количеством данных. 
    - Используйте текстовые файлы
    - Бонус: *используйте бинарные файлы*
1. Добавьте обработку исключительных ситуаций.
1. Дополните программу функциями, которые делают то же самое, но используют vector вместо классических массивов [https://github.com/VetrovSV/OOP/blob/master/2022/vector.cpp].
1. *Бонус: используйте умные указатели для работы с массивами*.
1. *Бонус: скомпилируйте cpp файл модуля [https://github.com/VetrovSV/OOP/tree/master/examples/example_libs/simple_lib].*
1. *Бонус: добавьте в программу возможность получать данные через аргументы командной строки (см. предыдущее задание)*
1. *Бонусный отчёт: Сделайте отчёт о компиляции с использованием системы сборки CMake*
1. *Бонус: Сделайте отчёт о компиляции с использованием компилятора MSVC* [https://github.com/VetrovSV/OOP/blob/master/examples/CMake/readme.md]
1. *Бонус: сделайте отдельный модуль\пространство имён с шаблонными функциями из п. 1 и 3.*

Конспект: Обработка исключительных ситуаций. Несколько catch, catch(...), указание типов бросаемых исключений в функции.

Конспект: Класс vector. Эффективность операций.

Конспект: Умные указатели. 

Конспект: тернарный оператор. Общий синтаксис. Использование в составе выражений и без них. 


**Критерии оценки**
- Корректные идентификаторы, оформление кода, перегрузка функций (если необходимо)
- Следование процедурное-модульному подходу, принципу единственной ответственности.
- Документация (документирующие комментарии) и поясняющие комментарии, указан автора кода в каждом файле.

### Ссылки
1. https://en.cppreference.com/w/cpp/container/vector
2. https://en.cppreference.com/w/cpp/language/range-for -- пример перебора элементов динамического массива vector с помощью совместного цикла и auto
1. Модульное тестирование (Google Test + VS) [ [StudBook](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#section.4.5] ]