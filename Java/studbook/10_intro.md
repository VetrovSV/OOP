# Введение в язык Java

## 1. Создание и запуск первой программы

<img src="img/10_intro/IDEA_new_project.png" alt="Создание проекта в IDEA">

Обязательно укажите
- Name -- осмысленное имя для проекта (будет создана одноимённая папка, будет использоваться как имя пакета для приложения)
- Location -- куда сохранить проект
- Система сборки -- Maven или Gradle; система IntelliJ  менее универсальна и распространена.
- ☑ Add Sample Code -- создать не пустой проект, а добавить пример кода.

&nbsp;

<img src="img/10_intro/IDEA_hello_world.png" alt="Запуск программы в IDEA">

&nbsp;

**Запуск**. нажать **Run** (зелёный треугольник) или клавиши **Shift + F10**. В консоли появится `Hello, World!`.
- В IDEA проект состоит из **src** (исходный код) и **out/target** (скомпилированные `.class`).

## 2. Примитивные типы и переменные
- Примитивы Java: `byte`, `short`, `int`, `long`, `float`, `double`, `char`, `boolean`.
- Каждый тип имеет фиксированный диапазон (см. таблицу в учебнике). При переполнении происходит «обёртывание».
- Приведение типов: безопасное (`int` → `long`) и явное (`long` → `int`).
- Объект‑обёртки (`Byte`, `Short`, `Integer`, `Long`, `Float`, `Double`, `Character`, `Boolean`). Автоупаковка/автораспаковка происходит автоматически, но следует помнить о стоимости создания объектов.
- Константы объявляются `final`:
```Java/studbook/10_intro.md#L13-16
final double PI = 3.1415926535;
// PI нельзя изменить позже
```

## 3. Операторы и выражения
- Арифметические: `+ – * / %`.
- Унарные: `+`, `-`, `++`, `--` (пост‑ и префиксные варианты).
- Логические: `&&`, `||`, `!`.
- Приоритет операторов соответствует обычным правилам C/Python; скобки позволяют явно задать порядок.

## 4. Консольный ввод‑вывод
- Вывод:
  - `System.out.println("text");` – печатает с переводом строки.
  - `System.out.print("text");` – без перевода строки.
  - `System.out.printf("%d %f %s\n", i, d, s);` – форматированный вывод (подобно `printf` в C).
- Ввод через `java.util.Scanner`:
```Java/studbook/10_intro.md#L17-23
import java.util.Scanner;

Scanner sc = new Scanner(System.in);
System.out.print("Введите целое число: ");
int a = sc.nextInt();
System.out.print("Введите число с плавающей точкой: ");
double b = sc.nextDouble();
sc.nextLine(); // очистка буфера
System.out.print("Введите строку: ");
String line = sc.nextLine();
```
- Проверка корректного ввода:
```Java/studbook/10_intro.md#L24-28
if (!sc.hasNextInt()) {
    System.out.println("Ожидалось целое число!");
    return;
}
```

## 5. Базовые практические задачи
1. **Площадь прямоугольника**
   ```Java/studbook/10_intro.md#L29-38
   Scanner sc = new Scanner(System.in);
   System.out.print("Ширина: ");
   double w = sc.nextDouble();
   System.out.print("Высота: ");
   double h = sc.nextDouble();
   double area = w * h;
   System.out.printf("Площадь = %.2f\n", area);
   ```
2. **Перевод температуры** °C ↔ °F
   ```Java/studbook/10_intro.md#L39-48
   System.out.print("Температура в градусах Цельсия: ");
   double c = sc.nextDouble();
   double f = c * 9 / 5 + 32;
   System.out.printf("%f °C = %f °F\n", c, f);
   ```
3. **Квадратное уравнение** `ax² + bx + c = 0`
   ```Java/studbook/10_intro.md#L49-61
   System.out.print("a: ");
   double a = sc.nextDouble();
   System.out.print("b: ");
   double b = sc.nextDouble();
   System.out.print("c: ");
   double c = sc.nextDouble();
   double d = b * b - 4 * a * c; // дискриминант
   if (d < 0) {
       System.out.println("Корней нет (дискриминант < 0).");
   } else {
       double sqrtD = Math.sqrt(d);
       double x1 = (-b + sqrtD) / (2 * a);
       double x2 = (-b - sqrtD) / (2 * a);
       System.out.printf("Корни: %f и %f\n", x1, x2);
   }
   ```

## 6. Математическая библиотека Java
- Официальная справка (англ.): <https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Math.html>
- Русскоязычное руководство: <https://javaer.ru/learn/java-docs/java-lang-math/>

## 7. Итоги и контрольные вопросы
- Перечислите все примитивные типы и их диапазоны.
- Как объявить константу и почему её используют?
- Какие методы `Scanner` нужны для чтения `int`, `double` и `String`?
- Как вывести значение с двумя знаками после запятой?
- Приведите формулу площади прямоугольника и пример её реализации в Java.

---
*Этот раздел даёт минимальный набор теории и сразу переводит студента к написанию работающих программ.*
