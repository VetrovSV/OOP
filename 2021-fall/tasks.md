# Занятие 1
C++, структура программы, компиляция в командной строке, переменная среды окружения PATH.

1. Запустите PowerShell. Изучите переменную окружения Path: выполните команду для отображения переменной среды окружения:
  ```$env:path```\
  Есть ли там путь к компилятору MinGW (GCC)? Если нет, то добавьте.
2. Определите версию С++ компилятора из GCC:\
  ```g++ --version```
3. Создайте в Sublime Text файл с расширением cpp и исходным кодом простой    программы на C++:
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
  - нахождение суммы массива по формуле из задачи: [ivtipm.github.io/Programming/Glava06/index06.htm#z136](https://ivtipm.github.io/Programming/Glava06/index06.htm#z136)

  Во время компиляции указывайте все cpp файлы.

#### Вопросы
  1. Для чего нужна переменная среды окружения Path? Как её изменить? Как посмотреть содержимое?
  1. Какие комманды (программы) командной строки вы знаете? Как просмотреть содержимое текущей папки? Как сменить текущую папку?
  1. Как называется программа из MinGW (GCC) компилирующая С++ код? Какие параметры есть у этой программы?
  1. Почему компилятору не нужно указывать имена заголовочных (.h) файлов?
  1. Что такое кодовая таблица символов?

#### Дополнительно
Windows не использует кодировку Юникод в конмандной строке по умолчанию, поэтому вывод символов не из кодовой таблицы ASCII будет сломан. Включить кодирование Юникода UTF-8:
```$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding```


## Домашнее задание
1. Установите на домашнем копьютере
  - текстовый редактор Sublime text 3: [sublimetext.com/3](https://www.sublimetext.com/3)
  - компилятор MinGW (GCC) версии 8 или выше: [mingw-w64.org/doku.php/download](http://mingw-w64.org/doku.php/download)
  - систему управления версиями git: [git-scm.com](https://git-scm.com/)

2. Изучите переменную окружения Path.
  В PowerShell выполните команду для отображения переменной среды окружения:\
  ```$env:path```\
  Переменная может выглядеть так:
  ```
  C:\Program Files\Microsoft MPI\Bin\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files\CMake\bin;C:\Program Files\dotnet\;C:\Program Files (x86)\IncrediBuild;C:\Program Files\Git\cmd;C:\Users\S\AppData\Local\Programs\Python\Python39\Scripts\;C:\Users\S\AppData\Local\Programs\Python\Python39\;C:\Users\S\AppData\Local\Microsoft\WindowsApps;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\lib\x64;C:\Users\S\.dotnet\tools;C:\Users\S\.jdks\openjdk-16.0.1\bin;;C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin
  ```
 Если там нет пути к компилятору MinGW то добавьте его. Путь к компилятору MinGW может выглядеть так, если вы не изменили его во время установки: `C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin`.

3. Проверте доступен ли C++ компилятор GCC (MinGW).
  В PowerShell выполните команду
  ```cmd
  g++ --version
  ```


# Занятие 4
## Домашнее задание
- **Конспект**. Создание консольных приложений на языке C++ в Visual Studio 2019
- Установите на домашнем копьютере
  - Visaul Studio 2019 или более новую версию
  - Qt 6, для компилятора MinGW (GCC). если во время установки всё выбрали правильно, то размер устанавливаемых файлов должет быть более 6 Гб
