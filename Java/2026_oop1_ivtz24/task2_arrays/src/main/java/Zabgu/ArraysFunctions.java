package Zabgu;

import java.util.Random;

public class ArraysFunctions {


    // Опредление функции print_array с аргументом  (параметром) типа double[],
    // которая не возвращает значение (возр. тип -- void)
    // ToDo: написать комент про функцию
    public static void print_array( double[] arr  )     // <- заголовок функции
    // тело функции:
    {
        // arr -- аргумент (формальный параметр функции)

        // Вывод массива на экран
        for ( int i = 0; i< arr.length; i++ ){
            // arr.length -- длина массива
            System.out.printf("%14.2f ", arr[i] );
            // если остаток от деления на 10 равен 9, то переходим на новую строку
            if ( i % 10 == 9 )    System.out.print("\n");
        }
    }
// Определение функции = объявление функции + тело функции

    /// Выделяет память под массив и заполняет его случайными числами
    /// n -- количество элементов массива
    /// Возвращает заполненный массив
    public static double[] random_fill_array( int n ){
        double[] arr = new double[n] ;
        Random r = new Random();
        for ( int i = 0; i<n; i++ ) {
            arr[i] = r.nextDouble()*99+1;  }
        return arr;
    }
}
