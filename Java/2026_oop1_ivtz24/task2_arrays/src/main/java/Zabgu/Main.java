package Zabgu;

import java.lang.Math;

import java.util.Random;


// Дан массив a из N чисел
// Преобразовать эл-ты массива по формуле: a[i] = log2( a[i] +1  )



public class Main {


    public static void main(String[] args) {

        // ToDo: сделать тесты для функции random_fill_array

        // Определение переменной -- объявление + инициализация
        // Объявление переменной r типа Random: Random r
        Random r = new Random();            // генератор случайных чисел
        // new -- выделением памити для переменной
        // Random() -- инициализация переменной

        // Определение переменной N типа int, 51 -- начальное значение
        // Инициализация -- задание начального значения
        int N = 51;

        // объявление массива и выделение памяти под массив
        double[] a = ArraysFunctions.random_fill_array( N );

        System.out.println("Массив после заполнения случайными числами: ");
        ArraysFunctions.print_array( a );
        System.out.println("");


        System.out.println("Массив после заполнения случайными числами: ");
        ArraysFunctions.print_array( a );
        System.out.println("");

        // Заполнение массива
        for ( int i = 0; i<N; i++ ){
            a[i] = Math.log( a[i] + 1) / Math.log(2.0);
            // запись числа i в массив a по индексу i ( a[i] )
        }

        System.out.println("Массив после преобразования: ");
        ArraysFunctions.print_array( a );
        System.out.println("");




    }
    }
//
//// Условный оператор
//        if ( условие ) {
//action1 (если условие истино)
//        } else {
//action2 (если условие ложно)
//        }



//// цикл со счётчиком
//        for ( int i = 0; i < 3; i ++ )       // заголовок цикла
//        // 1) int i = 0 ( выполнится при заходе в цикл )
//        // i - счётчик цикла
//        // 2) i < 100 -- логическое выражение ( условие выполнениея цикла )
//        // если выражение истино, то переход к п. 3 (к телу цикла)
//        // если выраженеи ложно -- то выход из цикла
//        // 3) Тело цикла
//        // 4) i++ то же самое, что и i = i + 1
//        // 5) переход к п. 2
//
//        // тело цикла:
//        {
//        System.out.printf("i = %d; ", i);
//                System.out.println("Я буду делать контрольные работы заранее!");
//            }