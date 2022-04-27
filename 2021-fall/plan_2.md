# Лекция 6.
апрель 28
- Таймер
- Развёртывание приложений
  - статическая линковка
  - ресурсы в Qt
  - необходимые библиотеки, dependency walker
  - сжатие исполняемых файлов
  - программы для создания установочных файлов


### Домашнее задание
- Конспект: Создание установочных файлов приложений (ваш любимый способ)
- Конспекты (бонус): 
  - DevOps
  - CI/CD на github

<br>

# Лекция 5. Модель и представление в БД
апрель 14
- Повторение. SOLID. Паттерны проектирования. MVC.
- Классы модели и представления
  - https://raw.githubusercontent.com/VetrovSV/OOP/master/Qt_lec2.pdf
  - Пример на Qt: https://github.com/VetrovSV/OOP/tree/master/examples/Qt/database 
  - DataGrid и BindingList в C#: https://github.com/VetrovSV/OOP/tree/master/examples/WpfApp_DataGrid
  - в Java см. TableView и ObservableList
- Qt StyleSheet
  - https://doc.qt.io/qt-5/stylesheet-examples.html
  - https://doc.qt.io/qt-5/stylesheet-reference.html
  - Пример: https://github.com/VetrovSV/OOP/blob/master/examples/Qt/database/style.qss
 

### Дополнительно
- https://ru.wikipedia.org/wiki/CSS

### Домашнее задание
- Здание 3 БД из файла https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf


<br>

# Лекция 4. Ссылки на функции, SOLID, паттерны
март 31
- Повторение
- Дополнение примера для чат-бота:
- Сылки на функции
  - https://github.com/VetrovSV/OOP/tree/master/2021-fall/chat_bot (пример с занятия)
  - https://github.com/VetrovSV/OOP/blob/master/examples/cpp_map/main.cpp (пример для самостоятельного изучения)
  - Java: https://github.com/VetrovSV/OOP/blob/master/examples/java/function-reference.md 
  - C#: см. делегаты или тип Func
- SOLID
  - https://github.com/etrovSV/OOP/blob/master/OOP_SOLID.pdf
- ООП-паттерны
  - Фасад, Фабрика, Декоратор
  - https://github.com/VetrovSV/OOP/blob/master/OOP_patterns.pdf

HTTP запросы в QT
```C++
    // Объект для выполнения сетевых запросов
    // для работы с сетевыми запросами нужно подключить модуль network в pro файле: QT += network
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    // QNetworkRequest(QUrl("https://icanhazip.com/")) -- конструктор HTTP запроса
    // netReply -- указатель на объект, который: умеет ждать ответа на запрос, умеет хранить запрос
    QNetworkReply *netReply = manager->get(QNetworkRequest(QUrl("https://icanhazip.com/")));
    // Ответ на запрос может занимать заметное количество времени
    // Реализуем простой вариант -- ожидание ответа
    QEventLoop loop;    // Объект, который умеет ждать (содержит в себе бесконечный цикл)
    // Соединим сигнал о получении ответа с заверением бесконечного цикла ожидания
    QObject::connect(netReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    // Запуск бесконечного цикла, пока не будет получен сигнал от netReply
    loop.exec();
    // readAll() возвращает QString с содержимым

    delete netReply;
    string ip = netReply->readAll().toStdString();
    
    // https://icanhazip.com -- сайт который показывает IP посетителя и больше ничего
```

# Лекция 3. Разбор задания Чат-Бот, абстрактные классы, Dependency Inversion, многооконные приложения, горячие клавиши
март 17
- Разбор задания Чат-Бот
  - см. пример в дискорде
  - многооконные приложения (Qt)
     - https://github.com/VetrovSV/OOP/blob/master/Qt_lec4.pdf
     - https://github.com/VetrovSV/OOP/tree/master/examples/Qt/multy-window
  - горячие клавиши (Qt)
  - ~ссылки на методы (C++)~
     - https://github.com/VetrovSV/OOP/blob/master/examples/cpp_map/main.cpp
  - интерфейсы
     - SOLID: dependency inversion
        - https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_SOLID.pdf

### Дополнительно

```cpp
// В QTextEdit можно использовать HTML для оформления текста
ui->textEdit->append("<p style=\" color:#ff0000;\"> some text </p>");

// задать выравнивание последнего абзаца
ui->textEdit_history->setAlignment(Qt::AlignRight);
```

- [Расстояние Дамерау — Левенштейна](https://ru.wikipedia.org/wiki/%D0%A0%D0%B0%D1%81%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%B8%D0%B5_%D0%94%D0%B0%D0%BC%D0%B5%D1%80%D0%B0%D1%83_%E2%80%94_%D0%9B%D0%B5%D0%B2%D0%B5%D0%BD%D1%88%D1%82%D0%B5%D0%B9%D0%BD%D0%B0)
- https://github.com/public-apis/public-apis -- список сайтов с открытым програмным интерфейсом
- https://reqbin.com/ -- сайт для проверки API запросов
- https://github.com/VetrovSV/OOP/blob/master/examples/java/HTTP_request.md -- HTTP запрос на Java
- https://github.com/VetrovSV/OOP/tree/master/examples/java/MultyWindow -- многооконное приложение на JavaFX

# Практика 3
####  Домашнее задание
- Конспект: Стандарт документирования для вашего любимого языка программирования
  - Опишите формат документирующих комментариве для файлов исходного кода, классов, функций (параметров, возвращаемых значений) и т.д.
  - Приведите примеры
  - Документирующие комментарии учитываются вашей любимой IDE?
  - Как сгенерировать документацию на основе исходного кода
- Конспект + отчёт: компиляция программы для языка программирования, выбранного в работе 1

# Лекция 2. C#. Сигналы и слоты в Qt
март 3
 - Повторение. Подходы к созданию приложений с GUI. Компиляция программы с Qt
 - C#
   - Слайды https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2.pdf
   - Пример програмы на C# c XAML: https://github.com/VetrovSV/OOP/tree/master/examples/Csharp/XamlCsharpExample
   - https://docs.microsoft.com/ru-ru/dotnet/desktop/wpf/get-started/create-app-visual-studio?view=netdesktop-6.0 - Создание нового приложения WPF с помощью .NET
 - Сигналы и слоты
   - https://github.com/VetrovSV/OOP/blob/master/Qt_lec3.pdf


####  Домашнее задание
1. *Задание 4. Сигналы и слоты: https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf*



# Лекция 1
 февраль 17
 - доклады?
 - DRY,  KISS, единственная отвественность,
 - повторение: принципы ООП
 - тип данных словарь
    - пример: https://github.com/VetrovSV/OOP/blob/master/examples/cpp_map/main.cpp
 - слайды: https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2.pdf


####  Домашнее задание
1. Сделайте шпаргалку о регулярных выражений
    - описание ситаксиса с примерами
    - выражения для решения популярных задач
    - использование в вашем любимом текстовом редакторе
    - использование в вашем любимом языке программирования



#### Источники
- C# 7 и .NET Core. Кросс-платформенная разработка для профессионалов. 3-е изд. — СПб.: Питер, 2018. — 640 с.
- Фридл Дж. Регулярные выражения, 3-е издание. – Пер. с англ. – СПб.: СимволПлюс, 2008. – 608 с., ил.
- https://regex101.com/



# Практика 1
- Введение в Java https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_2.pdf
  - Пример: https://github.com/VetrovSV/OOP/tree/master/examples/java/simple-class (InteliJ IDEA)
- Создание приложений с GUI в Java с помощью JavaFX
  - Пример: https://github.com/VetrovSV/OOP/tree/master/examples/java/JavaFX

##### Подсказки
InteliJ IDEA
- `Alt + Enter` - контекстное меню с действиями
- `Alt + Enter` с курсором на подключении библиотеки > Add имя_библиотеки to classpath -- искать и скачать бибилиотеку

#### Домашнее задание
1. Класс в программе с GUI:
   - https://raw.githubusercontent.com/VetrovSV/OOP/master/%D0%9E%D0%9E%D0%9F.%20%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D1%8F%20II.pdf
1. Сделайте шпаргалку по выбранному в задании 1 языку программирования:
   - характеристика и особенности языка; номер последней версии
   - типы данных
   - создание проекта консольного приложения и приложения с GUI в вашей любимой среде разработки
   - подключение сторонних модулей
   - использование (установка) библиотеки для модульного тестирования
1. Скачайте одну или несколько книг по выбранному языку программирования
1. Создайте интеллект-карту или систематизируйте в виде другой диаграммы темы и понятия из выьранного языка программирования
   - сайты для создания диаграмм: (miro.com, draw.io)


#### Дополнительно
- https://stepik.org/course/187/ - Java. Базовый курс
- https://www.jetbrains.com/ru-ru/idea/ - InteliJ IDEA
- Г. Шилдт, Java Руководство для начинающих 7-е изд (2018)
- https://soundcloud.com/podlodka/podlodka-172-java
- https://java-online.ru/java-javadoc.xhtml – документирование в Java
- jUnit – библиотека для модульного тестирования


[Осень 2021: ООП](https://github.com/VetrovSV/OOP/blob/master/2021-fall/plan_oop.md)

[Осень 2021: С++](https://github.com/VetrovSV/OOP/blob/master/2021-fall/plan_cpp.md)
