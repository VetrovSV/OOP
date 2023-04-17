# Лекция 7. Языки описания интерфейса пользователя.
Повторение
- О git, ветках и github.
- О статических членах класса и многооконных приложениях с общими данными. 

- https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2_8_UI_markup_language.pdf

До 10 мая выполните задание по языкам описания UI: https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf#page=9

Опишите принципы построения программы c таким UI в конспекте. Опишите основные элементы UI и их свойства. Опишите, как код на языке программирования общего назначения взаимодействует с UI.


# Лекция 6. Классы модели и представления. Таймер. QFile, QDir, ...
До 10 мая полностью выполните задание База данных.


Пример работы с таймером в C#
```c#
        //using System.Timers;
        Timer t = new Timer(2000);      // таймер с интервалом 2000 мс.

        public MainWindow()
        {
            InitializeComponent();

            t.Enabled = true;      
            t.AutoReset = true;     // таймер будет срабатывать многократно
            t.Start();

            // адрес метода, который будет вызван при срабатывании таймера
            // метод должен принимать параметры Object source, ElapsedEventArgs e
            t.Elapsed += do_something;
        }

        public void do_something(Object source, ElapsedEventArgs e)
        {
            MessageBox.Show("Hello!");
        }
```
# Лекция 4. SOLID. Сигналы и слоты


# Лекция 3. Многооконные приложения и др.
Разбор примеров:
- Меню и горячие клавиши, панель инструментов, стили текста в QTextEdit, диалоговые окна (домашняя папка, фильтры)
  - https://github.com/VetrovSV/OOP/tree/master/examples/Qt/example_qt_menu
- Многооконные приложения с общими данными: https://github.com/VetrovSV/OOP/tree/master/examples/Qt/multy-window
- Обзор элементов интерфейса, их свойств и методов
  - https://raw.githubusercontent.com/VetrovSV/OOP/master/Qt_lec2.pdf
  
# Лекция 2
февраль 21. Словарь. Регулярные выражения.
- Повторение. Вопросы.
  - github и git
  - markdown и изображения
  - Абстрактные классы. 
  - экранирование символов
- Тип данных Словарь, Стек, регулярные выражения.
  - https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2.pdf

### Домашнее задание
1. Начните выполнять работу 2. Можно выбрать язык программирования C++, С#, Java или другой (по предварительному) согласованию.
  -  https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf
  - Закончите за 4 недели
1. Сделайте шпаргалку о типе данных Словарь (ассоциативный массив) для выбранного языка программирования (C++, C#, Java)
1. Сделайте шпаргалку о регулярных выражениях
   - описание синтаксиса с примерами
   - выражения для решения популярных задач
   - использование в вашем любимом текстовом редакторе
   - использование в вашем любимом языке программирования

### Источники
1. https://regex101.com/ -- для экспериментов с регулярными выражениями
1. https://www.rexegg.com/regex-quickstart.html -- шпаргалка по регулярным выражениям
1. [https://regexper.com/](https://regexper.com/#%5B%D0%90-%D0%AF%5D%5B%D0%B0-%D1%8F%5D%7B1%2C10%7D%5Cs%3F%5B%D0%90-%D0%AF%5D%5C.%5B%D0%90-%D0%AF%5D%5C.) -- визуализация регулярных выражений
1. Фридл Дж. Регулярные выражения, 3-е издание. – Пер. с англ. – СПб.: СимволПлюс, 2008. – 608 с., ил.
1. Заготовка для ЧатБота на С++: https://github.com/VetrovSV/OOP/tree/master/2021-fall/chat_bot
1. Пример словаря с адресами функций: https://github.com/VetrovSV/OOP/blob/master/examples/cpp_map/main.cpp
****


# Лекция 1. Java. C#
февраль 07
- Повторение
- Обзор (заданий)[https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf]
- Java и C#

Слайды: 
- C# https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2.pdf
- Java - https://docs.google.com/presentation/d/14Y8LWzVeChUyjaKhb6rgELdWJR58B2YGUIukeZ-e3PU/edit?usp=sharing




## Задания
- Задание 1: https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf
- Конспект по языку общего назначения (который выбрали для первого задания): Java, С#, свой вариант после согласования с преподавателем.
  - Общая характеристика языка, последняя версия стандарта
  - Источники: Литература, документация, онлайн-курсы (?) и т.п.
  - Шаблон консольного приложения, шаблон приложения c GUI
  - Среда разработки. Создание проектов. 
  - Основные типы, особенности типизации, контейнеры
  - Классы
  - Модульное тестирование
- Скачайте литературу по выбранному в первом задании языку программирования
- Создайте отчёт о компиляции и запуске программы в консоли
- Опишите особенности языка, источники, популярные библиотеки и идеи из языка в виде Mind Map


## Источники
- C#7  и  .NET  Core.  Кросс-платформенная  разработка  для  профессионалов. Прайс Марк Дж, 3-е изд., 2018 (и более поздние издания)
- Java. Библиотека профессионала, том 1. Основы.  Кей Хорстманн, 11-е изд, 2019, 864 стр
- Java. Библиотека профессионала, том 2.  Расширенные средства программирования.  Кей Хорстманн, 11-е изд, 2020, 864 стр.
- Примеры: https://github.com/VetrovSV/OOP/tree/master/examples
- https://stepik.org/course/187/ - Java. Базовый курс
- https://www.jetbrains.com/ru-ru/idea/ - InteliJ IDEA
- https://soundcloud.com/podlodka/podlodka-172-java
- https://java-online.ru/java-javadoc.xhtml – документирование в Java
- jUnit – библиотека для модульного тестирования
