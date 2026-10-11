package Zabgu;

import java.util.Random;
import java.lang.Math;



public class Main {

    /// Вычиляет сумму ln(|a[i]|), i = 0...
    static double sum_array_ln(double[] a){
        double s = 0.0;
        for ( double el : a)
            s += Math.log( Math.abs( el ) );
        return s;
    }

    ///
    static double[] create_arr_42(int n){
        double[] arr = new double[n];

        for (int i = 0; i < arr.length; i++)
            arr[i] = 42;

        return arr;
    }

    public static void main(String[] args) {

        int N = 100;
        // Язык Java: динамический массив
//        double[] arr = new double[N];
        double[] arr = create_arr_42(N);
        Random rnd = new Random(10);        // 10 - seed -начальное значеие для генератора случ. чисел
//        Random rnd = new Random();

//        for (int i = 0; i < arr.length; i++) {
//            arr[i] = rnd.nextDouble(-100.0, 100.0);
//        }

        // соместный цикл ( цикл по коллекции )
         for ( double a : arr)
             System.out.printf("%.2f ",a);

         double S = sum_array_ln(arr);

        System.out.printf("S = %.4f", S);

        }
    }