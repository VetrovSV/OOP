# OOP
![Badge](https://hitscounter.dev/api/hit?url=https%3A%2F%2Fgithub.com%2FVetrovSV%2FOOP&label=Visits&icon=github&color=%23198754)

## Планы курсов

### [C](C/readme.md)



### Планы текущих и старых курсов по С++ \ ООП \ Java
**[Требования к заданиям](https://github.com/VetrovSV/OOP/blob/master/criteria.md)**


**Курс 24-25**: 2. Весна 2025: [ООП](plans/2025_oop2.md), [Задания](Задания-II.md)\
**Курс 24-25**: 1. Осень 2024:  [C++](plans/2024_cpp.md) ([практические задания](https://github.com/VetrovSV/OOP/blob/master/plans/tasks_cpp.md)) , [ООП](plans/2024_oop_1.md)


**[Заочное, часть 2, курс для группы 22](plans/2024_fall_distance.md)**\
**Заочное, часть 1, курс для группы 22**: [С++ и ООП](plans/2024_spring_distance.md)



**Курс 23-24**: 1. Осень 2023:  [C++](plans/2023_cpp.md) ([практические задания](https://github.com/VetrovSV/OOP/blob/master/plans/tasks_cpp.md)) , [ООП](plans/2023_fall_oop.md),\
2. [Весна 2024](/plans/2024-spring.md)



Курс 22-23: Осень 2022:  [C++](https://github.com/VetrovSV/OOP/blob/master/2022/plan_cpp.md), [ООП](https://github.com/VetrovSV/OOP/blob/master/2022/plan_oop.md);\
[Весна](https://github.com/VetrovSV/OOP/blob/master/2022/plan_oop2.md)


[Заочное 2023: Лето](https://github.com/VetrovSV/OOP/blob/master/plans/2023-spring.md);\
[Заочное 2024: Зима](https://github.com/VetrovSV/OOP/blob/master/plans/dist2024-fall.md)

[Заочное 2022. Семестр 1.](plans/2022-spring_distance.md), [Заочное 2023. Семестр 2.](plans/2023-fall_distance.md)


Курс 21-22:
Осень:  [C++](https://github.com/VetrovSV/OOP/blob/master/2021-fall/plan_cpp.md),  [ООП](https://github.com/VetrovSV/OOP/blob/master/2021-fall/plan_oop.md), [Весна](2021-fall/plan_2.md)


Курс 20-21: [Осень](https://github.com/VetrovSV/OOP/blob/master/2020-fall/tasks.md), [Весна](https://github.com/VetrovSV/OOP/blob/master/2021-spring/tasks.md)



## Примерная структура курса по С++ \ ООП \ Java
1. Введение в С++ [ [C++ (part 1).pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%201).pdf),
[C++ (part 2).pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%202).pdf), [дорожная карта изучения C++](https://salmer.github.io/CppDeveloperRoadmap/Russian/) ]
   * отличия от C [wiki](https://ru.wikibooks.org/wiki/%D0%A1%D0%B8%2B%2B/%D0%9E%D1%81%D0%BD%D0%BE%D0%B2%D0%BD%D1%8B%D0%B5_%D0%BE%D1%82%D0%BB%D0%B8%D1%87%D0%B8%D1%8F_%D0%A1%D0%B8%2B%2B_%D0%BE%D1%82_%D0%A1%D0%B8)
   * hello world [pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%201).pdf#Navigation15)
   * типы данных, auto, пространства имён, операторы
   * ссылки, указатели, rvalue reference, управление памятью
   * компиляция ([g++](https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%201).pdf#Navigation92), [MSVC](https://docs.microsoft.com/ru-ru/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=msvc-170), [VisualStudio](https://docs.microsoft.com/ru-ru/cpp/build/vscpp-step-1-create?view=msvc-170)), заголовочные файлы и файлы исходного кода [pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/C%2B%2B%20(part%201).pdf#Navigation78)
   * ссылки на функции, лямбда-выражения, функции высшего порядка
   * обработка исключительных ситуаций
   * стандартная библиотека, STL
   * документирование кода Doxygen [ [habr](https://habr.com/ru/post/252101/) ]
   * [assert](https://github.com/VetrovSV/OOP/blob/master/2021-fall/plan_cpp.md#%D0%B7%D0%B0%D0%BD%D1%8F%D1%82%D0%B8%D0%B5-2-assert-%D0%BA%D0%BE%D0%BC%D0%BF%D0%B8%D0%BB%D1%8F%D1%86%D0%B8%D1%8F-%D0%B2-%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%BD%D0%BE%D0%B9-%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B5)
   * [CMake](https://github.com/VetrovSV/OOP/tree/master/examples/CMake)
   * [Другие примеры](examples/):
      - [Создание библиотек](examples/example_libs/)
      - [Потоки выполнения (threads)](examples/example_thread/)
1. Git
2. Введение в ООП. \
[OOP_1.0.pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_1.0.pdf) -- введение в ООП \
[OOP_1.1.pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_1.1.pdf) -- подробнее об ООП и с примерами на C++
    1. Основные понятия. Отношения между классами и объектами.
    1. Абстрактный тип данных
    1. Классы в C++ [[пример](https://github.com/VetrovSV/OOP/tree/master/examples/simple_class)]
    1. Инкапсуляция. Сокрытие. Конструкторы. Методы и поля
        * модификаторы доступа, проверка предусловий
        * оператор присваивания
        * правило большой пятёрки
        * перегрузка методов и операторов
3. Наследование [OOP_1.2.pdf]([OOP_1.2.pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_1.2.pdf))
   * переопределение методов
   * преобразование типов
   * множественное наследование
4. Полиморфизм
   * шаблоны
   * динамический полиморфизм, виртуальные и абстрактные классы
   * динамическое определение типа, RTTI
5. SOLID
6. Java
   * [Коротко о Java](https://github.com/VetrovSV/OOP/tree/master/examples/java)
     * [Указатели на методы](https://github.com/VetrovSV/OOP/blob/master/examples/java/function-reference.md)
     * [Таймер](https://github.com/VetrovSV/OOP/blob/master/examples/java/timer.md)
     * [HTTP запросы](https://github.com/VetrovSV/OOP/blob/master/examples/java/HTTP_request.md)
     * [JavaFX](https://github.com/VetrovSV/OOP/tree/master/examples/java/JavaFX)
   * [Примеры и шпаргалки](examples/java/)  
      * [HTTP запросы](examples/java/HTTP_request.md)
      * [Тестирование с помощью JUnit](examples/java/junit.md)
      * [pattern matching](examples/java/pattern_matching.md)
      * Регулярные выражения
      * ...
7. Приложения с графическим интерфейсом (JavaFX)
   * фреимворк для GUI, основы 
   * MVC
   * FXML ([google slides](https://docs.google.com/presentation/d/1BJOtQ5QKtVrGhgpWPkrYao29krP4iNMsJj93BD_Gmu0/edit?usp=sharing))
   * многооконные приложения, горячие клавиши
   * модель и представление (табличные данные и списки)
   * примеры:
      * [Простое приложение на JavaFX](examples/java/JavaFX/)
      * [2D графика на Canvas](examples/java/javafx_canvas/)
      * [FXML и CSS](examples/java/JavaFX_FXML_CSS/)
      * [examples/java/database_sqlite/](examples/java/database_sqlite/)
      * [examples/java/database_tableview_observablelist/](examples/java/database_tableview_observablelist/)
      * [examples/java/example_java_threads/](examples/java/example_java_threads/)
      * [examples/java/MultyWindow](examples/java/MultyWindow)
      * ...
8. ~~Приложения с GUI на С++ с использованием фреимворка Qt~~
   * [Примеры](examples/Qt) (простые приложения, sqlite, qml, графика, таблицы и model-view)
6. Некоторые паттерны проектирования
   [google slides](https://docs.google.com/presentation/d/1SJ7-9TTjaU_EJdmh2LL1til82Kl-Ie7i6kQzzBwquCs/edit?usp=sharing)


# Ссылки и материалы
0. Черновик учебного пособия по ООП и C++ [OOP_StudBook.pdf](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook.pdf)
1. Язык программирования C++ (с описанием C++11 и c++14). Страуструп Бьёрн. 2016 г. 1100+ стр. 2-е или более новые издания (4-е издание самое новое на момент 2021 года)
2. https://en.cppreference.com/w -- документация по C++ и примеры
3. Руководство по использованию С++: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
3. Эффективный и современный С++: C++11 и С++14. 42 рекомендации по использованию С++. 2016. г - 304. Скотт Мейерс
4. Язык UML. Руководство пользователя. 2-е изд.: Пер. с англ. Мухин Н. – М.: ДМК Пресс, 2006. – 496 с.: ил.

**UML** и диаграммы
- https://plantuml.com/ru/ -- plantUML -- создание диярам в plain text
- https://app.diagrams.net/ (draw.io)
