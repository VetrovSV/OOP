Для ссылок на ~функции~ методы принимающие объект и возвращающие объект в Java есть интерфейс Function

```java
@FunctionalInterface
public interface Function<T, R> {
      R apply(T t);                 // метод, вызывающий функцию
}
```

<br>

Ссылка на лямбда-функцию
```java
/** Применяет функцию к элементам массива  */
public static void apply(Double[] arr, Function<Double, Double> func){
   for (int i = 0; i<arr.length; i++)
       arr[i] = func.apply( arr[i] );
   }

public static void main(String[] args){

     // создание объекта Function - обёртки для лямбда-функции
     Function<Double, Double> getCircleArea = r -> r * r * Math.PI;

     // ошибка: типы должны быть классами!
     Function<double, double> getCircleArea2 = r -> r * r * Math.PI;

    getCircleArea.apply( 10.0 );        // вызов

    Double[] array1 = {1.0, 2.0, 3.0};
    Double[] array2 = {1.0, 2.0, 3.0};
    apply(array1, getCircleArea);       // 3.14, 12.57, 28.28
    apply(array2, x-> x*x);             // 1, 4, 9
```


Объявление объекта типа Function - это фактически объявление нового класса (потомка от Function) и его экземпляра. Поэтому нельзя записать адрес уже готового метода.

```java
class SomeMethods {
    // на этот метод нельзя сослаться
    public static String foo(String s) {
        Random r = new Random();
        switch ( r.nextInt(2) ){
            case 0: return "Я люблю смотреть ответы StackOverflow";
            case 1: return "Я люблю смотреть ответы на русских формах по программированию";
        }
        return "Я люблю читать документацию";
    }
}


public class Main {

    public static void main(String[] args){

    // ошибка: записать отдельную функцию нельзя,
    // она, в отличие от лямбда-функции, не конвертируется в объект Function ...
    Function<String, String> f = SomeMethods.foo;

    // ... но отдельно объявленный объект типа Function может быть описан в несколько строк
    Function<String, String> foo = s -> {
        Random r = new Random();
        switch ( r.nextInt(2) ){
            case 0: return "Я люблю смотреть ответы StackOverflow";
            case 1: return "Я люблю смотреть ответы на русских формах по программированию";
        }
        return "Я люблю читать документацию";
    };

}
```

Функциональные интерфейсы в Java имеют один метод, который должен выполнять всё работу. Функциональные интерфейсы отличаются названием этих методов, параметрами и возвращаемым значением:
- `Function` - apply принимает аргумент и возвращает значение
- `Consumer` - accept только принимает
- `Supplier` -  get только возвращает
- `Predicate` - test принимает параметр и возвращает логическое значение
