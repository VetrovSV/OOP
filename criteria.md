# Требования к коду и критерии оценки

### Следуйте парадигме процедурно-модульного программирования или ООП
Используйте **принцип единственной ответственности**, **DRY** (don't repeat yourself).
Разделяйте логику программы на отдельные функции, классы или модули с чёткими задачами.

Примеры.
<details>

```cpp
// 1. Нарушение принципа единственной ответственности: функция делает и ввод, и обработку, и вывод
// 2. Функция получает данные не через аргументы, а через стандартный ввод cin. Её невозможно использовать, если данные в программе предполагается получать иным способом.
void calculateAndPrintBMI() {
    float weight, height;
    
    std::cout << "Введите вес (в кг): ";
    std::cin >> weight;
    
    std::cout << "Введите рост (в метрах): ";
    std::cin >> height;
    
    if (height <= 0) {
        std::cerr << "Рост должен быть больше 0." << std::endl;
        return;
    }

    float bmi = weight / (height * height);
    std::cout << "Индекс массы тела: " << bmi << std::endl;
}
```

Исправление:
```cpp
float calculateBMI(float weight, float height) {
    if (height <= 0) {
        throw std::invalid_argument("Рост должен быть больше 0.");
    }
    return weight / (height * height);
}
```
</details>

**Повторное использование кода.** Помните, что функции, классы или модуль могут (хотя бы гипотетически) быть использованы для решения другой задачи. Поэтому при возможности не делайте их узкоспециализированными, нацеленными на использование исключительно для текущей задачи.
[[OOP_StudBook_upd.pdf#subsection.1.4.6](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#subsection.1.4.6)]

Помните про свойство **массовости алгоритма**: алгоритм должен быть пригоден для решения всех задач данного типа.

<br>

### Именование и стиль
Выберите удобный для вас стиль кодирования и придерживайтесь его на протяжении всей работы.

Не используйте идентификаторы, имена файлов с транслитерацией или на любом языке, кроме английского.

Используйте осмысленные имена переменных, функций и классов, которые отражают их назначение.

<br>

### Комментарии и документация
Документируйте код, используя принятый (широко распространённый) в выбранном языке стандарт документирования (например, Doxygen для C++, Javadoc для Java).
Пишите документирующие комментарии для:
- модуля: кратко описывайте его назначение;
- функций и методов: назначение, параметры и возвращаемые значения, особенности работы (ограничения для данных, бросаемые исключения);
- констант, переменных и полей класса;
- типов данных.

См. примеры документирования функций в разделе [1.4.6 Выводы и рекомендации](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#subsection.1.4.6) по работе с функциями:

<details>

```cpp
// хороший пример: машинно-читаемый комментарий для
// системы документирования Doxygen:

/// вычисляет индекс массы тела по массе (m) в кг. и росту (h) в метрах
/// бросает исключение ivalid_argument если h==0
float bmi(float m, float h);



// отличный пример (машинно-читаемый комментарий для
// системы документирования Doxygen с полным описанием функции):

/// вычисляет индекс массы тела;
/// бросает исключение ivalid_argument если h==0
/// \param m масса тела в кг.
/// \param h рост в метрах
/// \return индекс массы тела
float bmi(float m, float h);
```

</details>




Указывайте автора в каждом модуле.

Пишите комментарии, поясняющие алгоритмы, структуру данных и неочевидные моменты.
Избегайте избыточных комментариев, объясняющих очевидное (например, "переменная для счётчика цикла").

Во время защиты работ оправдание "давно писал код, не помню, как это работает" не принимается.

Допускается в конце модуля приводить короткую справку, ссылки на документацию и т.п.

Создавайте UML диаграммы классов. Допускается описывать классы опуская непринципиальные для понимания программы поля и методы.  




<br>

### Исключительные ситуации и контроль данных

Обрабатывайте возможные ошибки и исключения. Ваша программа не должна завершаться с необработанной ошибкой. 

Проверяйте исключительные ситуации (не удалось открыть файл, нет доступа к сети и т.д.), бросайте исключение если необходимо.

Проверяйте корректность аргументов функций, пользовательских данных, а также предельные случаи (например, пустые массивы).

См. Черновик учебного пособия, раздел "2.1 Обработка исключительных ситуаций".

[ [OOP_StudBook_upd.pdf#subsection.2.1](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#subsection.2.1) ]

<br>

### Автоматическое тестирование
Предоставляйте тесты, проверяющие основные и крайние случаи работы функций и методов.

Используйте встроенные или сторонние инструменты для автоматического тестирования (например, Google Test для C++, JUnit для Java).

Тесты должны покрывать ключевые функции и методы программы.

[ [OOP_StudBook_upd.pdf#subsection.2.2.5](https://raw.githubusercontent.com/VetrovSV/OOP/master/OOP_StudBook_upd.pdf#subsection.2.2.5) ]

<br>

### Эффективность алгоритмов
Оценивайте эффективность алгоритмов по потребляемой памяти и по количеству операций.

По возможности используйте структуры данных и алгоритмы с оптимальной асимптотической сложностью.

Избегайте неоправданного дублирования данных и операций.


<br>

### Защита работ и плагиат
Изучайте теоретический материал по теме работы перед ей защитой. Создавайте конспекты, их можно использовать во время защиты.

Преподаватель оставляет за собой право попросить повторить реализацию отдельных небольших частей кода программы во время защиты работы. 

Если обнаружен плагиат (в том числе использование нейросетевых ассистентов) тема работы или задание могут быть изменены.  


<br>


### Система контроля версий
Приветствуется использование git. За это могут быть начислены дополнительные баллы (если git использован с самого начала разработки).
Создавайте ветки для протестированной версии программы и для текущей разработки. Загружайте код в удалённый репозиторий.
Желательно создавать один репозиторий для одного предмета.



### Ссылки
Изучите приведённые здесь темы и понятия в книге Совершенный код (Code Complite) Стива Макконнелла.