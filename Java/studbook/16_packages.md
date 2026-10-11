## 6. Подключение пакетов и стандартная библиотека Java

В Java пакеты используются для организации функций (статических методов), классов и интерфейсов. Они помогают избежать конфликтов имен и упрощают поиск и использование классов.

Для подключения пакета в Java используется ключевое слово `import`. Например, чтобы подключить класс `Scanner` из пакета `java.util`, нужно написать:

```java
import java.util.Scanner;
```

Также можно подключить все классы из пакета с помощью звездочки:

```java
import java.util.*;
```

Однако лучше подключать только те классы, которые действительно нужны, чтобы избежать излишней загрузки.

В Java есть стандартные пакеты, такие как `java.lang`, который подключается автоматически, и не нужно писать `import java.lang.*;`.


Статический импорт позволяет использовать статические методы или константы без указания имени класса.

```java
import java.lang.Math;
// Использование:
float y = sin(Math.Pi);


import static java.lang.Math.*;         // подключение всех идентификаторов модуля
import static java.lang.Math.PI;     // подключение конкретного идентификатора
// Использование:
float y = sin(PI);
```

### Стандартная библиотека Java (Java Class Library)

Стандартная библиотека Java (Java Class Library, JCL) — это набор пакетов с классами и интерфейсами, которые доступны в любой реализации Java. Имена пакетов составные (например, `java.util.regex`), потому что пакеты могут быть вложенными: пакет `java.util.regex` является подпакетом пакета `java.util`. 

Пакет — это пространство имён, которое соответствует иерархии каталогов на диске. В Java 9+ появилась система модулей (JPMS), где модуль — это группа связанных пакетов, описываемая в файле `module-info.java`. Отдельные файлы `.java` модулями не являются — они содержат классы, которые входят в состав пакетов, а пакеты, в свою очередь, могут быть объединены в модули.

```
module (модуль, в терминологии Java = набор пакетов)
 └── package  (пакет)
      └── compilation unit (.java файл, модуль (unit) в привычном для программирования смысле) 
           └── class/interface/enum/record  (содержимое модуля)
```

Ниже перечислены основные пакеты стандартной библиотеки:

- **java.lang**. Содержит классы, которые подключаются автоматически (без `import`): `String`, `Math`, `System`, `Integer`, `Double`, `Thread`, `Throwable` и др.
- **java.util**. Содержит коллекции (`List`, `Set`, `Map`, `Queue`), и различные классы, необходимые почти в любом коде `Scanner`, `Random`, `Date`, `Optional` и др.
- **java.util.regex**. Регулярные выражения: `Pattern`, `Matcher`.
- **java.util.function**. Функциональные интерфейсы для лямбда-выражений и Stream API: `Function`, `Predicate`, `Consumer`, `Supplier`.
- **java.io**. Потоки ввода-вывода (байтовые и символьные): `InputStream`, `OutputStream`, `Reader`, `Writer`, `File`.
- **java.util.stream**. Stream API для функциональной обработки коллекций: `Stream`, `IntStream`, `Collectors`.
- **java.nio**. Неблокирующий ввод-вывод (New I/O): `Buffer`, `Channel`, `Path`, `Files`.
- **java.net**. Сетевые возможности: `URL`, `Socket`, `ServerSocket`, `HttpURLConnection`.
- **java.math**. Математические операции произвольной точности: `BigInteger`, `BigDecimal`.
- **java.time**. Дата и время (Java 8+): `LocalDate`, `LocalTime`, `LocalDateTime`, `Duration`, `Period`.
- **java.sql**. Работа с базами данных через JDBC: `Connection`, `Statement`, `ResultSet`.
- **java.awt**. Базовые элементы графического интерфейса (минимальный набор возможностей для создания GUI): `Component`, `Container`, `Graphics`, `Color`.
- **javax.swing**. Расширенный набор GUI-компонентов (Swing, менее предпочтителен чем JavaFX): `JFrame`, `JButton`, `JTextField`.
- **java.text**. Форматирование чисел, дат и текста: `NumberFormat`, `DateFormat`, `SimpleDateFormat`.
- **java.lang.reflect**. Рефлексия — возможность исследовать классы во время выполнения: `Class`, `Method`, `Field`, `Constructor`.
- **java.lang.annotation**. Работа с аннотациями: `Annotation`, `Retention`, `Target`.
- **java.security**. Криптография и управление доступом: `MessageDigest`, `KeyStore`, `Permission`.

#### Математическая библиотека Java
- Официальная справка (англ.): <https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Math.html>
- Русскоязычное руководство: <https://javaer.ru/learn/java-docs/java-lang-math/>


### Топ пакетов для начала изучения

Не пытайся выучить всю стандартную библиотеку сразу. На первых порах достаточно уверенно ориентироваться в этих шести пакетах:

| Пакет | Зачем нужен | Ключевые классы | Подключается сам? |
|-------|------------|----------------|-------------------|
| `java.lang` | Базовые классы языка | `String`, `Math`, `System`, `Integer`, `Double`, `StringBuilder` | Да, `import` не нужен |
| `java.util` | Коллекции, утилиты, ввод | `Scanner`, `Random`, `ArrayList`, `HashMap`, `List`, `Arrays`, `Collections` | Нет |
| `java.io` / `java.nio` | Работа с файлами | `File`, `BufferedReader`, `FileWriter`, `Path`, `Files` | Нет |
| `java.time` | Дата и время (Java 8+) | `LocalDate`, `LocalTime`, `LocalDateTime`, `Duration` | Нет |
| `java.math` | Точные вычисления | `BigInteger`, `BigDecimal` | Нет |
| `java.util.regex` | Регулярные выражения | `Pattern`, `Matcher` | Нет |

> **Совет.** Если не уверен, откуда класс -- наведи курсор в IDEA и нажми Ctrl+Q (Quick Documentation).


### Шпаргалка: самые полезные классы и методы

#### `java.lang` -- подключается автоматически

| Класс | Метод / Конструктор | Что делает |
|-------|-------------------|-----------|
| `String` | `length()` | Длина строки |
| `String` | `charAt(i)` | Символ на позиции i |
| `String` | `substring(i, j)` | Подстрока с i по j-1 |
| `String` | `indexOf(s)` / `lastIndexOf(s)` | Позиция вхождения |
| `String` | `contains(s)` | Содержит ли подстроку |
| `String` | `split(regex)` | Разбить по разделителю |
| `String` | `toLowerCase()` / `toUpperCase()` | Изменить регистр |
| `String` | `trim()` / `strip()` | Удалить пробелы по краям |
| `String` | `format(fmt, args...)` | Форматирование |
| `String` | `valueOf(x)` | Преобразовать в строку |
| `StringBuilder` | `append(x)` / `insert(i, x)` / `reverse()` / `toString()` | Работа со строкой |
| `Math` | `abs(x)` / `max(a,b)` / `min(a,b)` | Математические функции |
| `Math` | `pow(a,b)` / `sqrt(x)` / `random()` | Ст��пень / корень / случайное |
| `Math` | `floor(x)` / `ceil(x)` / `round(x)` | Округление |
| `System` | `out.println(x)` / `out.printf(fmt, args...)` | Вывод |
| `System` | `arraycopy(src, srcPos, dest, destPos, len)` | Копирование массивов |
| `Integer` / `Double` / ... | `parseInt(s)` / `parseDouble(s)` | Парсинг строки в число |

#### `java.util` -- требуется `import java.util.*`

| Класс | Метод / Конструктор | Что делает |
|-------|-------------------|-----------|
| `Scanner` | `new Scanner(System.in)` / `nextInt()` / `nextLine()` / `hasNextInt()` | Ввод с консоли |
| `Random` | `new Random()` / `nextInt(bound)` / `nextDouble()` | Случайные числа |
| `ArrayList<E>` | `add(x)` / `remove(i)` / `get(i)` / `size()` / `sort(comp)` | Динамический массив |
| `HashMap<K,V>` | `put(k,v)` / `get(k)` / `remove(k)` / `containsKey(k)` / `keySet()` | Словарь |
| `Arrays` | `sort(arr)` / `toString(arr)` / `copyOf(arr, len)` | Работа с массивами |
| `Collections` | `sort(list)` / `reverse(list)` / `shuffle(list)` | Работа с коллекциями |

#### `java.time` -- требуется `import java.time.*`

| Класс | Метод | Что делает |
|-------|------|-----------|
| `LocalDate` | `now()` / `of(y,m,d)` / `plusDays(n)` | Дата |
| `LocalTime` | `now()` / `of(h,m,s)` | Время |
| `LocalDateTime` | `now()` / `of(...)` | Дата и время |
| `DateTimeFormatter` | `ofPattern("dd.MM.yyyy")` / `format(formatter)` | Форматирование |

#### `java.io` / `java.nio` -- требуется `import`

| Класс | Метод / Конструктор | Что делает |
|-------|-------------------|-----------|
| `File` | `new File(path)` / `exists()` / `isFile()` / `listFiles()` | Работа с файлами |
| `PrintWriter` | `new PrintWriter(file)` / `println(x)` | Запись в файл |
| `BufferedReader` | `new BufferedReader(new FileReader(file))` / `readLine()` | Чтение из файла |
| `Files` | `readString(path)` / `writeString(path, text)` / `copy(src,dest)` / `createDirectories(path)` | NIO (с 11+) |

#### `java.util.regex` -- требуется `import java.util.regex.*`

| Класс | Метод | Что делает |
|-------|------|-----------|
| `Pattern` | `compile(regex)` / `matches(regex, text)` | Регулярные выражения |
| `Matcher` | `matcher(text)` / `find()` / `group()` / `replaceAll(replacement)` | Поиск и замена |
