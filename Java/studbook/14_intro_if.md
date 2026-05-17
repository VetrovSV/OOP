# Логический тип и условные операторы

## 1. Логический тип `boolean`
- **Значения:** `true` и `false`.
- **Объявление переменной:**
  ```java
  boolean isReady = true;
  final boolean IS_FINAL = false; // константа
  ```
- Сравнение `boolean`‑переменных только оператором `==` и `!=`.
- При работе с другими типами логическое значение получают через сравнение (`a > b`, `str.isEmpty()` и т.п.).

## 2. Операторы сравнения и логические операторы
- **Сравнение:** `==`, `!=`, `<`, `>`, `<=`, `>=` (для чисел, `char`).
- **Логическое И:** `&&` (короткое замыкание, вычисляется слева‑направо).
- **Логическое ИЛИ:** `||` (короткое замыкание).
- **Отрицание:** `!`.
- Приоритет операторов: `!` > `&&` > `||` (см. таблицу в разделе «Операторы»).

### Примеры логических выражений
```Java
int a = 5, b = 10;
boolean simple = a < b;                     // true
boolean combined = a < b && b > 0;         // true, && оценивает оба условия
boolean withOr = a > b || b > 0;           // true, второй операнд проверяется только если первый false
boolean notExpr = !(a == b);               // true
```

#### Сравнение чисел с плавающей точкой
```Java
double x = 0.1 + 0.2;        // 0.30000000000000004
boolean direct = x == 0.3; // false – неточное представление
final double EPS = 1e-9;
boolean approx = Math.abs(x - 0.3) < EPS; // true – сравнение с допуском

// альтернативный способ: Double.compare
int cmp = Double.compare(x, 0.3); // 0 если «точно» равны, иначе >0 или <0
```

#### Сочетание нескольких условий
```Java
int year = 2024;
boolean leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // високосный год?

int score = 75;
boolean pass = score >= 60 && score <= 100; // true
```

#### Приоритет и скобки
```Java
boolean expr1 = true || false && false;      // true (&& имеет больший приоритет)
boolean expr2 = (true || false) && false;    // false
```

#### Преобразование типов
**Неявные приведения.** В Java нет автоматического преобразования между `boolean` и другими примитивными типами. Попытка присвоить `int` переменной `boolean` или наоборот приводит к ошибке компиляции.

**Из `boolean` к числам:** Чаще всего используют тернарный оператор.
  ```java
  boolean flag = true;
  int oneZero = flag ? 1 : 0; // 1 если flag == true, иначе 0
  ```
- **Из `String` к `boolean`:** `Boolean.parseBoolean(String)` (возвращает `true` только при точном совпадении «true», без учёта регистра).
  ```java
  String txt = "TrUe";
  boolean parsed = Boolean.parseBoolean(txt); // true
  ```
- **Из `boolean` к `String`:** `String.valueOf(boolean)` или конкатенация.
  ```java
  boolean ok = false;
  String s = String.valueOf(ok); // "false"
  String s2 = ok + ""; // "false"
  ```
- **Объект‑обёртка `Boolean`:** Автопакование и автораспаковка работают без потери данных.
  ```java
  Boolean obj = flag;      // автоупаковка
  boolean prim = obj;      // автораспаковка
  ```



## 3. Условный оператор `if`
```java
if (condition) {
    // тело, выполнится только если condition == true
}
```
- Однострочный вариант без фигурных скобок допускается, но **не рекомендуется**.

## 4. `if‑else` и цепочка `else if`
```java
if (cond1) {
    // блок 1
} else if (cond2) {
    // блок 2
} else {
    // блок по умолчанию
}
```
- Позволяет построить «лестницу» условий.

## 5. Тернарный оператор `?:`
```java
int max = (a > b) ? a : b;
```
- Выражение, а не оператор — может использоваться только внутри другого выражения.
- Удобен для простых присваиваний.

## 6. Оператор `switch`
### Классический синтаксис
```java
switch (value) {
    case 1:
        // …
        break;
    case 2:
        // …
        break;
    default:
        // …
}
```
- Требует `break` для предотвращения «проваливания».
### Современный «arrow‑syntax» (Java 14+)
```java
switch (day) {
    case MONDAY, TUESDAY -> System.out.println("Рабочий день");
    case SATURDAY, SUNDAY -> System.out.println("Выходной");
    default -> System.out.println("Неизвестный день");
}
```
- `yield` может вернуть значение из `switch`.
- Поддерживаемые типы: `int`, `char`, `String`, `enum`, `sealed`‑классы.

## 7. Практические примеры
1. **Чётность числа**
   ```java
   boolean even = (n % 2 == 0);
   if (even) System.out.println("Чётное"); else System.out.println("Нечётное");
   ```
2. **Меню с `switch`**
   ```java
   System.out.print("Выберите пункт (1‑3): ");
   int choice = scanner.nextInt();
   switch (choice) {
       case 1 -> System.out.println("Опция 1 выбранa");
       case 2 -> System.out.println("Опция 2 выбранa");
       case 3 -> System.out.println("Опция 3 выбранa");
       default -> System.out.println("Неверный выбор");
   }
   ```
3. **Тернарный оператор для выбора строки**
   ```java
   String result = (score >= 60) ? "Сдал" : "Не сдал";
   ```

## 8. Вопросы
- Чем отличается оператор `&&` от `&`?
- Какой результат у выражения `true ? false : true`?
- Что произойдёт, если в `switch` забыть `break` в классическом варианте?
- Какие типы поддерживает `switch` в Java 17?
- Как записать условие «число в диапазоне от 10 до 20 включительно»?
