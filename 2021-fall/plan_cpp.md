# Занятие 5
- Защита работ?

# Лекция 4
- общий принцип построения приложений с ГИП, класс, обработчики событий. QT.
- git
- слайды: https://github.com/VetrovSV/Programming/blob/master/git_lec.pdf


### Домашнее задание
- Отчёт по git: https://github.com/VetrovSV/OOP/blob/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20I.pdf
- Конспект:
  - *не обязательно:* Битовые операции


# Занятие 4
- общий принцип построения приложений с ГИП, класс, обработчики событий
- Программы с ГИП в Qt
- Защита работ?


**Программа с графическим пользовательским интерфейсом на Qt**
1. Создание проекта в Qt Creator (Application Qt > Qt Widgets Application) \
  *Выберете путь для сохранения содержащий только латиницу* \
  Предпочтительный компилятор (в составе комплекта Qt) - MinGW (GCC)
1. Файлы проекта:
    - `main.cpp` -- главный файл программы; здесь создаётся окно программы и запускается *цикл обработки сообщений* программы
    - `mainwindow.cpp`, `mainwindow.h` -- содержит класс представляющий логику работы окна программы; содержат обработчики событий (методы), переменные (поля) для хранения данных программы
    - `mainwindow.ui` -- описывает внешний вид окна программы;

1. Откройте файл `mainwindow.ui`. \
 Добавьте в окно вашей программы поля ввода (QLineEdit), кнопку (QPushButton) и надписи (QLabel), которые понадобятся для решения вашей первой задачи из задачника. \
 Задайте свои мена для элементов интерфейса (свойство ObjectName). Например для кнопки: pushbutton_calc -- кнопка для запуска вычислений. \
 Отредактируйте текст элементов интерфейса (свойство Text) \
![](QtDesigner.png)

Если нужно, добавьте картинку на форму. Файл картинки скопируйте файл в папку сборки. Далее, добавить Label, свойство pixmap, нажать треугольник рядом, Выбрать файл.
Поставьте галочку в свойстве scaledContents чтобы масштабировать картинку.

1. Выясните в какой папке создаётся исполняемый файл программы: вкладка Проекты (Project) - Каталог сборки

1. Скомпилируйте и запустите проект, проверьте исполняемый файл \
  *см. как запустить скомпилированный файл программы вне Qt Creator: http://blog.harrix.org/article/1015*

1. `mainwindow.ui`. Создайте обработчик события: ПКМ на вашей кнопке > Перейти к слоту > Clicked - ОК. Будет создано объявление функции (мтода) в файле `mainwindow.h` и определение в файле `mainwindow.cpp`

1. Подключите файлы с кодом, который решает вашу задачу: ПКМ на имени проекта (в дереве проекта) > Добавить существующие файлы ...
  Скопируйте эти файлы в папку проекта перед добавлением в проект.\
  Подключите заголовочный файл с вашим кодом в файл с обработчиком события `mainwindow.cpp`.\
  Напишите обработчик события.\
  Обращение к содержимому поля ввода:
  `ui->lineEdit_a->text()` \
  Оператор `->` - это одновременное разыменование и оператор доступа к члену класса\структуры (`.`) \
  Преобразование строкового типа (QString) в числовой:
  `ui->lineEdit_a->text().toFloat()`
  Изменение текста на элементе интерфейса: `ui->label_result->setText( "some text" )`\
  Преобразование числа в строку (QString): `QString::number( 3.14159 )`

1. Храните все входные и выходные данные программы не в элементах интерфейса, а в классе отвечающим за обработку событий главного окна, в разделе private (см. пример).

1. Задайте заголовок главного окна (свойство windowTitle). \
Добавьте надпись и изображение, при необходимости, с условием задачи.
Добавьте пункт меню Справка, подпункт Об авторе. Показывайте сообщение с информацией о себе: ``` QMessageBox::about(this, "Заголовок диалогового окна", "Текст в окне"); ```

1. Задайте ограничения для размеров элементов интерфейса (ПКМ > задать максимальный размер)
Используйте компоновку элементов интерфейса для аккуратного их расположения и  создания интерфейса, отзывчивого на изменение размеров окна.

Пример: https://github.com/VetrovSV/OOP/tree/master/examples/lec_5_qt-project

Во всех файлах исходного кода укажите автора программы.

### Дополнительно
**Форматирование надписей в HTML**\
Текст на элементах интерфейса можно форматировать в HTML: ПКМ на элементе > Изменить форматированный текст

**Настройка стиля элемента интерфейса**\
Настроить внешний вид элемента интерфейса с помощью таблицы стилей (как в CSS): ПКМ на элементе > StyleSheet;
Разные элементы интерфейса имеют разный набор свойств https://doc.qt.io/qt-5/stylesheet-reference.html.
Для большинства можно настроить:
- поля (margin), ширину границы (border) и отступы (padding) [https://doc.qt.io/qt-5/stylesheet-customizing.html#box-model].
- цвет текста ``` color: rgb(92, 53, 102); ```
- цвет фона: ```background-color: rgb(255, 255, 128); ```
- фоновое изображение, например для фона окна:
```CSS
/* укажем имя конкретного элемента интерфейса - centralwidget,
ибо этот стиль не должен дальше распространится на все дочерние элементы интерфейса*/
#centralwidget{         
  background-image:url("my_image.jpg");
  background-position: center;
}
 ```

Само изображение должно находится в папке с исполняемым файлом программы. Во время настройки стиля оно не отобразится на фоне, но появится после компиляции и запуска.

Список свойств: https://doc.qt.io/qt-5/stylesheet-reference.html#list-of-property-types

**Как добавить изображение в исполняемый файл** и включить отображение изображения в дизайнере форм.
1. Добавьте файл с описанием включаемых в исполняемый файл зависимостей -- файл ресурсов: ПКМ на корне проекта > Шаблон QT | QT Resource File > задайте имя файла, например images
2. Укажите имя файла с изображением в файле ресурсов: ПКМ на файле ресурсов > Добавить существующий > Выберете файл
3. Чтобы использовать изображение на форме, например в label: выберете label > свойство pixmap > ... > Resource root | выберете изображение из списка

**Как запустить скомпилированную программу?**
1. Скомпилируйте программу в режиме выпуска (release). Исполняемый файл будет меньше и потребуются библиотеки меньшего размера
2. Скопируйте нужные, динамически подключаемые библиотеки (dll в Windows) в папку с исполняемым файлом. Узнать какие нужны библиотеки можно либо запуская exe файл либо, с помощью программы dependecywalker. Для автоматического копирования нужных библиотек используйте программу windeployqt [https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2_7_lib_and_deploy.pdf]

Нужные библиотеки можно найти в папке Qt/6.0.1/gcc_64/lib.


### Домашнее задание
- Создайте программу на QT с графическим интерфейсом пользователя рещающую задачи с массивами (создание и поиск суммы массива). Используйте ранее написанный код. Выводите данные в QPlainTextEdit

# Лекция 3
- Слайды: https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%202).pdf
- файловые потоки
- git?

### Домашнее задание
- Конспект: этапы компиляции программы на C++
- Конспект: отладка в Visual Studio: точки останова, просмотр переменных, выполнение кода. Составьте конспект из скриншотов одной из ваших программ. Дайте общие пояснения, для кнопок и окон.
- Установить git: https://git-scm.com/
- Доделайте программу с массивами. Они должна содержать:
  - заполнение, вывод и вычисление суммы классического массива (например float*)
  - заполнение, вывод и вычисление суммы для типа данных vector
  - запись классического массива и vector в файл, чтение из файла; учитывайте, что перед чтением из файла нужно подсчитать число цифр в нём
  - поместите все функции в модуль и пространство имён
  - бросайте и обрабатывайте исключения
  - напишите документацию (в комментариях) и проверьте стиль кодирования
  - см. таблицу в заданиями

# Занятие 3
- Константные ссылки.
- Защита работ?

Передавайте параметры по ссылке в функцию в двух случаях
- Если нужно изменять параметр внутри функции
- Если копирование параметра при передаче по значению несёт много накладных расходов: больше чем копирование ссылки.

Для того чтобы узнать размер переменной (в байтах) используйте оператор [sizeof](https://en.cppreference.com/w/cpp/language/sizeof)
```C++
    int *arr3;
    vector<int> arr4;

    cout << sizeof (arr3) << endl;  // 8 байт
    cout << sizeof (arr4) << endl;  // 24 байта
```

```C++
    // arr передаётся по ссылке, но переменную запрещено менять внутри функции
    void print_array(const vector<int> &arr);
```

**Дополнительно**
- используйте синонимы для типов
- создайте функции для матрицы (vector) аналогичные массивам
- задавайте ширину столбца при выводе матрицы
- создайте функцию, применяющую переданную в аргументе лямбда-функцию к массиву.
	Пример: функции возведения во вторую степень и замены отрицательных чисел на нули
	```
	int *arr = new int[n];
	apply( arr, n, [](int x){return x*x;} );
	apply( arr, n, [](int x){return 0:x?(x<0);} );
	```
	Функция apply записывает в каждый элемент массива результат работы переданной в неё функции. Переданная функция вычисляется для аргумента -- элемент массива.

### Домашнее задание
- реализуйте функции работы с массивом, но используйте vector вместо классических массивов
- добавьте функции чтения и записи в файл для vector???; учитывайте, что перед чтением из файла нужно подсчитать число цифр в нём.
- *не обязательно: создайте статическую библиотеку из вашего модуля; подключите её к основному проекту*


### Сcылки
- http://ci-plus-plus-snachala.ru/?p=11 -- лямбда-функции в C++
- https://ravesli.com/urok-60-psevdonimy-tipov-typedef-i-type-alias/ -- typedef


# Лекция 2
- Слайды: https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%201).pdf
- Исключительные ситуации
- auto (кратко)
- Слайды: https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%202).pdf
- vector
- двумерные массивы



### Дополнительно.
Пример обработки исключений при консольном вводе

```C++
// включить исключения для ввода данных
cin.exceptions(istream::failbit);

float x;
try {
    cin >> x;           // исключение будет брошено, если будет введена строка
                        // которую нельзя преобразовать в вещественное число
    cout << "x = " << x;
}  catch (const std::ios_base::failure& fail) {
    cout << fail.what();
}
```


### Домашнее задание
Конспект:
- static
- лямбда-функции (не обязательно)
- синонимы (не обязательно)
- string


### Ссылки
- https://en.cppreference.com/w/cpp/container/vector
- https://habr.com/ru/post/182920/
- https://en.cppreference.com/w/cpp/error/exception -- типы данных стандартной библиотеки для исключений
- http://mycpp.ru/cpp/book/c11.html -- подробнее об исключениях
- https://github.com/VetrovSV/OOP/tree/master/examples/lec_2_1
- https://en.cppreference.com/w/cpp/language/range-for -- пример перебора элементов динамического массива vector с помощью совместного цикла и auto
- https://ravesli.com/urok-94-vvedenie-v-std-array/ -- о типе std::array

# Занятие 2. Assert. Компиляция в командной строке

### Автоматическое тестирование функций
Разбейте программу с предыдущего занятия на функции. Создайте тестовую функцию с помощью оператора assert.
пример
``` C++
#include <iostream>

// раскомментировать строку ниже, чтобы отключить assert()
// #define NDEBUG
#include <cassert>                  // для assert
                                    // все assert отключатся если скомпилировать программу в режиме выпуска (release)

#define _USE_MATH_DEFINES           // вкл. математические константы
#include <math.h>                   // модуль с математическими константами и функциями


// функция вычисления гипотенузы
float calc_c(float a, float b) {
    return sqrt(a*a + b*b);
}

int main(){   

    // проверка работы функции
    // если внутри оператора assert будет ЛОЖЬ, то программа аварийно завершит работу
    // такие проверки позволяют легко заметить  ошибки в коде, особенно когда
    // проверяемые функция во время разработки часто модифицируются, оптимизируются
    assert(fabs(calc_c(3, 4) - 5.0) < FLT_EPSILON);
    // в C++ невозможно корректное сравнение вещественных чисел на равенство без округления
    // например sin(M_PI) = 1.224647e-16, хотя в идеале должен быть 0
    // FLT_EPSILON (1.192092896e-07) -- наименьшее значение числа, которое можно сохранить во float

    assert(fabs(calc_c(1.5, 1) - 1.8027756) < FLT_EPSILON);

    assert(fabs(calc_c(500.0, 501.0) - 707.8142412) < FLT_EPSILON*1000);        // возьмём точность порядка 10^-4


    // далее основная работа программы
    // ...
}

```

### Компиляция в командной строке
1. Запустите PowerShell. Изучите переменную окружения Path: выполните команду для отображения переменной среды окружения:
  ```$env:path```\
  Есть ли там путь к компилятору MinGW (GCC)? Если нет, то добавьте через программу настройки "Изменение переменных среды окружения текущего пользователя".
  Компилятор MinGW можно найти по адресу: C:\Qt\Tools\mingw810_64\bin
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
5. Добавьте модуль с функциями
  - создание случайного массива
  - вывод массива на экран
  - нахождение суммы массива по формуле из задачи: [ivtipm.github.io/Programming/Glava06/index06.htm#z136](https://ivtipm.github.io/Programming/Glava06/index06.htm#z136)\
  Во время компиляции указывайте все cpp файлы.
6. Создайте отчёт о компиляции в командной строке.
7. Закончите работу дома, если не успели на занятии.


**Дополнительно**
- Создайте статическую библиотеку из модуля с функциями и подключите её к вашей программе (см слайды C++ part1)
- Выполните те же операции с компилятором MSVC

### Подсказки
- Задать число знаков после запятой при выводе в консоль:
  ```
  #include <iomanip>

  // вызвать в программе один раз, перед выводом чисел
  cout << 3000000.14159265 << ";";			// вывод:3e+06;
  cout << setw(12) << fixed << setprecision(2);		// 12 позиций на всё число; человекочитаемый формат (без e); два знака после запятой
  cout << 3000000.14159265 << ";";			// вывод:  3000000.14; (2 пробела в начале)
  ```

https://www.cplusplus.com/reference/iomanip/setprecision/

#### Вопросы
  1. Для чего нужна переменная среды окружения Path? Как её изменить? Как посмотреть содержимое?
  1. Какие команды (программы) командной строки вы знаете? Как просмотреть содержимое текущей папки? Как сменить текущую папку?
  1. Как называется программа из MinGW (GCC) компилирующая С++ код? Какие параметры есть у этой программы?
  1. Почему компилятору не нужно указывать имена заголовочных (.h) файлов?
  1. Что такое кодовая таблица символов?
  1. Как сгенерировать случайное целое число от 0 до Х? А как в интервале от А до B?
  1. Как инициализировать генератор случайных чисел?



#### Дополнительно
**Кодировка**

Windows не использует кодировку Юникод в командной строке по умолчанию, поэтому вывод символов не из кодовой таблицы ASCII будет сломан. Включить кодирование Юникода UTF-8:
```$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding```

**Оптимизация и размер файла**

Размер исполняемого файла после компиляции может показаться избыточным. Это происходит из-за включения в файл всех подключаемых библиотек -- статическая линковка (см. этапы компиляции программы на C++).



## Домашнее задание
  - Выполните пункты 1-5 на домашнем компьютере
  - Разберите всё, что не понятно. Напишите комментарии.
  - Напишите документацию к программе в комментариях. В том числе укажите назначение всех подключаемых файлов и укажите автора.
  - Конспект: структура консольного приложения на C++ в VS 2019. Основные файлы проекта. Обозреватель решений. Решение и проект. Добавление новых и существующих файлов. Удаление файлов из проекта и удаление с диска. Компиляция и сборка. Виды сборки.


### Ссылки
- https://en.cppreference.com/w/cpp/error/assert -- страница документации
- https://ravesli.com/urok-109-assert-i-static_assert/
- [Полный список опций компилятора](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
- [GCC x86, как уменьшить размер кода](https://habr.com/ru/company/intel/blog/167417/)
- https://docs.microsoft.com/ru-ru/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-160 -- компиляция в командной строке компилятором


# Занятие 1
C++, структура программы, ввод и вывод, пространства имён.

1. Решите первую задачу на языке C++ из задачника по программированию. Используйте среду разработки Visual Studio.
2. Дополнительно: создайте динамический массив, заполните его случайными целыми числами, выведете на экран. Разбейте работу на функции. Поместите их в отдельные h и cpp файлы. Объявите своё пространство имён в этих файлах.

### Домашнее задание
Установите на домашний компьютер:
- Qt Creator  вместе с компилятором MinGW (GCC)
- Visual Studio 2019


### Дополнительные материалы
- https://docs.microsoft.com/ru-ru/visualstudio/ide/whats-new-visual-studio-2019?view=vs-2019


**Вопросы**
1. В чём разница между IDE и компилятором?
2. Какие режимы запуска программы есть в VisualStudio? Чем они отличаются?
3. Как выглядит структура программы на C++?
4. Как подключить библиотеку? Что такое пространство имён?
5. Как работает директива компилятора ```include```?
6. Как объявляются переменные в C++?
7. Как выводить данные в консоль? Как запрашивать ввод с клавиатуры?


# Лекция 1. C++
- Краткие сведения о синтаксисе C++
- Слайды: https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%201).pdf
- Слайды: 1-75


### Домашнее задание
Конспект на тему:
- include guard в GCC и MSVC
- перечисляемый тип в C++
- ссылки на функции в C++ с использованием using
- элипсис в C++ (не обязательно)

Конспекты можно делать в Ворде, но рекомендуется использовать markdown и загружать на github.