# Основы Java

Модуль предназначен для студентов, знакомых с языком C и Pascal\Python.

# Результаты освоения модуля

- Понимание JVM, роли JRE/JDK и кроссплатформенных возможностей.
- Структурное программирование на Java: владение типовой системой и примитивными типами, Умение использовать управляющие конструкции, условные операторы и циклы, работа с массивами, строками и их API.
- Процедурно модельное программирование: создание функций (методов) организация кода в пакеты и модули.
- Основы ввода‑вывода, файлового API и NIO.
- Обработка исключений с `try‑with‑resources`.
- Использование коллекций и generics.
- Навыки работы с IDE, компиляцией, Maven/Gradle и юнит‑тестированием.

Эти результаты позволяют студенту уверенно переходить к более продвинутым темам.

## 1. Введение в Java
- История языка, эволюция (от Java 1 до Java 21) и место в индустрии
- Платформа JVM: роль JRE vs JDK, байт‑код, кроссплатформенность
- Сравнение с C (компиляция, управление памятью) и Python (динамичность, синтаксис)
- Основные инструменты разработки (IDE, консоль, сборщики)
- **Ресурсы:** официальная документация JDK, курс Oracle Java Foundations, курс WGU Java Fundamentals

## 2. Примитивные типы данных и переменные
- Примитивные типы: `byte`, `short`, `int`, `long`, `float`, `double`, `char`, `boolean`
- Диапазоны, переполнение, приведение типов, автоматическое расширение
- Объектные обёртки (`Byte`, `Short`, `Integer`, `Long`, `Float`, `Double`, `Character`, `Boolean`)
- Автоупаковка/автораспаковка, сравнение `==` vs `.equals()`
- Ключевое слово `var` (type inference, Java 10+)
- Константы `final`, иммутабельность
- Инициализация переменных, локальные vs полевые
- **Пример:** "Примитивы и обёртки в действии"
- **Пример:** "Тип var: вывод типа компилятором"

## 6. Консольный ввод‑вывод
- Стандартный ввод/вывод: `System.out.println`, `System.err`, `Scanner`
- Форматированный вывод: `System.out.printf`, `format`
- Чтение из консоли с `Scanner`, типы методов (`nextInt`, `nextLine` и т.д.)
- Работа с файлами (класс `File` как представление пути, атрибуты)

## 3. Управляющие конструкции
- Условные операторы `if`, `else if`, `else`
- Тернарный оператор `condition ? expr1 : expr2`
- Оператор `switch` (классический, расширенный с `String`, «arrow»‑синтаксис, `yield` в Java 13)
- Циклы `for` (традиционный, улучшенный `for‑each`), `while`, `do‑while`
- Метки и `break`/`continue` с метками, вложенные циклы
- Поток управления `return` внутри блоков
- **Пример:** "Перебор массивов с for‑each"
- **Пример:** "Switch с arrow‑syntax"

## 4. Массивы и строки
- Объявление, инициализация, размеры, индексация, границы массива
- Одномерные и многомерные массивы, «рэгги‑массивы»
- Копирование массивов: `System.arraycopy`, `Arrays.copyOf`, `clone()`
- Класс `String`: иммутабельность, пул строк, интернирование
- Основные методы `length()`, `charAt()`, `substring()`, `indexOf()`, `contains()`, `startsWith()`, `endsWith()`
- `StringBuilder` и `StringBuffer`:mutable строки, методы `append`, `insert`, `delete`, `reverse`
- Форматированный вывод `String.format` и `printf`
- **Пример:** "Создание и копирование двумерного массива"
- **Пример:** "StringBuilder для построения запросов"

## 5. Методы (функции) и параметры
- Синтаксис объявления, сигнатура, тип возвращаемого значения
- Параметры по значению (примитивы) и передачa ссылок (объекты)
- Параметры переменной длины (`varargs`), их использование и ограничения
- `static` методы, `final` методы, `abstract` методы (знакомство)
- `static import` для упрощения вызова утилит (`import static java.lang.Math.*;`)
- Перегрузка методов, различие по типу и количеству параметров
- Принцип единственной ответственности (SRP) при проектировании методов
- **Пример:** "Перегрузка метода calculateArea"
- **Пример:** "Varargs: summation of arbitrary numbers"
- **Ресурсы:** раздел «Methods» в официальном учебнике, курс Coursera "Fundamentals of Java Programming" (модуль «Methods & Parameters»)

## 10. Пакетирование и модульность
- Организация кода в пакеты, соглашения по именованию (`com.company.project`) 
- Директива `package` в начале файла, правило «один публичный класс на файл»
- Импорт классов: `import`, `import static`
- Пример конфликтов имен и использования полного квалификатора
- Кратко о системе модулей Java 9 (`module-info.java`), имена модулей, `requires`, `exports`
- При необходимости: как собрать проект без модулей (classpath) и с модулями (modulepath)
- **Пример:** "Пакет com.example.utils с классом StringUtils"
- **Пример:** "module-info.java с requires java.base; exports com.example.app;"

## 6. Файловый Ввод‑вывод
- Стандартный ввод/вывод: `System.out.println`, `System.err`, `Scanner`
- Форматированный вывод: `System.out.printf`, `format`
- Чтение из консоли с `Scanner`, типы методов (`nextInt`, `nextLine` и т.д.)
- Работа с файлами (класс `File` как представление пути, атрибуты)
- Символьный ввод/вывод: `FileReader`/`FileWriter`
- Байтовый ввод/вывод: `FileInputStream`/`FileOutputStream`
- Буферизованный ввод/вывод: `BufferedReader`, `BufferedWriter`, `PrintWriter`
- Современный API NIO: `Path`, `Files.readAllLines`, `Files.write`, `Files.copy`
- Работа с директориями, проверка существования, создание, удаление
- **Примеры:** запись массива в файл, чтение файла до конца.

## 7. Обработка исключений
- Иерархия `Throwable` → `Error` vs `Exception`
- Проверяемые (`checked`) исключения (`IOException`, `SQLException`), непроверяемые (`unchecked`) (`NullPointerException`, `IllegalArgumentException`)
- Блоки `try`, `catch`, `finally`
- Множественные `catch`, `catch (IOException | SQLException e)`
- Перехват и повторный бросок (`throw e`), вложенные исключения (`throw new MyException("msg", e)`) 
- Пользовательские исключения: наследование от `Exception` (checked) или `RuntimeException` (unchecked)
- Ресурсный менеджер `try‑with‑resources` (автоматическое закрытие `AutoCloseable`)
- Принципы: не скрывать исключения, логировать, использовать информативные сообщения
- **Пример:** "Обработчик файлов с try‑with‑resources"
- **Пример:** "Пользовательское CheckedException для валидации"
- **Ресурсы:** глава «Exceptions» в книге "Effective Java", курс Coursera "Fundamentals of Java Programming" (секция «Exception Handling»)

## 8. Коллекции и обобщения (Generics)
- Интерфейсы коллекций: `Collection`, `List`, `Set`, `Map`
- Реализации: `ArrayList`, `LinkedList`, `Vector`, `HashSet`, `LinkedHashSet`, `TreeSet`, `HashMap`, `LinkedHashMap`, `TreeMap`
- Итерация: `Iterator`, `for‑each`, `ListIterator`
- Сортировка: `Collections.sort`, `Comparator`, `Comparable`
- Обобщения: объявление параметризированных типов (`List<String>`), ограничения (`<T extends Number>`), wildcard (`? extends`, `? super`)
- Ограничения типовых erasure, опасные приведения, `@SuppressWarnings("unchecked")`
- Практика: использование `EnumSet` и `EnumMap`
- **Пример:** "ArrayList для динамического списка студентов"
- **Пример:** "HashMap для словаря слов и определений"
- **Пример:** "Generic метод swapElements(T[] array, int i, int j)"
- **Ресурсы:** официальное руководство Oracle "Collections Framework", курс Udemy "Java Collections: Mastering the Core API"

## 11. Инструменты разработки и сборки
- Компиляция: `javac MyClass.java` (опции `-d`, `-classpath`)
- Запуск: `java com.example.Main`
- IDE: IntelliJ IDEA (основные функции: рефакторинг, автодополнение), Eclipse, VS Code с расширением Java
- Системы сборки: Maven (`pom.xml` структуры, зависимости, плагины), Gradle (`build.gradle`, Groovy/Kotlin DSL)
- Управление зависимостями, репозитории Maven Central, локальный репозиторий
- Тестирование: JUnit 5 (аннотации `@Test`, `@BeforeEach`, `@ParameterizedTest`)
- Статический анализ: Checkstyle, SpotBugs, PMD
- **Пример:** "Создание простого Maven‑проекта с archetype:generate"
- **Пример:** "Gradle wrapper для быстрой настройки проекта"
- **Ресурсы:** официальные руководства Maven/Gradle, курс Udemy "Java Build Tools: Maven & Gradle"
