# Сопоставление с образцом (pattern mathcing)

Сопоставление с образом (pattern matching) - это мощная возможность языков программирования, которая позволяет проверять структуру данных на соответсвие некоторому значению или шаблону, извлекать из нее информацию полностью и частично.

Такая возможность часто есть в языках поддерживающих парадигму функционального программированиия. Например Haskell и Erlang.

Сопоставление с образцом может включать в себя проверку по регулярному выражению.

Обычно языковая конструкция сопоставления с образцом синтаксически похожа на оператор switch сase.

## Сопоставление с образцом в Java
В дополнение к си-подобному оператору swicth case в Java 17 добавлен следующий синтаксис, использующий выражение на основе switch (swithc expression):
```java
private static void printGreetingBasedOnInput(String input){
    switch (input){
        case "hello"     -> System.out.println("Hi There");
        case "goodbye"   -> System.out.println("See you Later!");
        case "thank you" -> System.out.println("You are welcome");
        default          -> System.out.println("I don't understand");
    }
    }
 ```
Классическая форма switch является оператором (statement), новая - выражением (expression). Выражение, в отличии от оператора, выдаёт значение.

Поэтому можно записать switch в составе любого допустимого выражения, присвоить переменной или, например, после оператора return:
```java
    private static String printGreetingBasedOnInput(String input){
        return switch (input){
            case "hello"     -> "Hi There";
            case "goodbye"   -> "See you Later!";
            case "thank you" -> "You are welcome";
            default          -> "I don't understand";
        };
    }
```

В новом варианте swicth в конце каждого блока case не требуется записывать оператор break. 

Типичная возможность сопоставления с образцом - проверка типа:
```java
private static void printType(Object input){
    switch (input) {
        case Integer i  -> System.out.println("Integer");
        case String s   -> System.out.println("String!");
        default         -> System.out.println("I don't understand");
    }
    }
```

`String` и `Integer` здесь - это образцы типа ( type patterns ).

Эти типы можно использовать для проверки переменной input (типа Object), так как все ссылочные типы - это наследники от Object. Следовательно в Object можно записать ссылку на любой производный тип. 

Оператор switch проверит input на соответствие типам Integer и String. Если будет совпадение с типом, то будет создана соответствующая переменная (`i` или `s`) - binding variable.

См. также оператор `instanceof`.


**Проверка условия в case - when**
```java
    private static String foo(Object input){
        return switch (input){
            // не компилируется, т.к. образец в case не может быть логическим выражением
            case String s && s.length()>5  -> "Long string";    // Error!
            // но к образцу можно добавить проверку условия после слова when
            case String s when s.length()>5  -> "Long string";
            // для строк удобно проверять их содержимое
            case String s when s.contains("wtf")  -> "WTF found!";
            case String s  -> "Other string";
            case Integer i -> "This is Integer";
            default        -> "wat?";
        };
    }

    public static void main(String[] args) {
        System.out.println( foo("Greetings!") );
        System.out.println( foo("Hi") );
        System.out.println( foo(42) );
    }
```

## См. также 
- проверку записей (record)
record - особый вид неизменяемых классов. Он может быть использован как образец, при успешной проверке на соответствие образцу можно из проверяемого значениия извлекать отдельные поля [2].
- Обработку подклассов (Ordering Subclasses)
- Проверку на null
- Обработку массивов
- ключевое слово yield



В других языках
- Сопоставление с образцом в Python (match case)
- Сопоставление с образцом в С++23 https://dev.to/sbalasa/top-c23-features-4ibj

# Ссылки
1. Документация: https://docs.oracle.com/en/java/javase/17/language/switch-expressions.html 
2. https://dev.java/learn/pattern-matching/
- Сопоставление с образцом в Scala: https://ivtipm.github.io/BigDataLanguages/Scala/slides/Scala_introdution.html#/10