package Zabgu;

import java.util.InputMismatchException;
import java.util.Random;
import java.lang.Math;
import java.util.Scanner;



public class Main {

    /// Вычиcляет сумму ln(|a[i]|), i = 0...
    static double sum_array_ln(double[] a){

        if ( a == null) {
            throw new IllegalArgumentException("Передана пустая ссылка вместо массива");
//            System.out.println("...");
        }

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

                double[] arr = new double[10];
                arr = null;

                    try {
                    if (arr == null ) {
                        System.out.printf("Пустая ссылка вместо массива");
                    }
//                    sum_array_ln(arr);

//                try {
//                    if (arr == null ) {
//                        throw new IllegalArgumentException("Пустая ссылка вместо массива");
//                    }
//                    sum_array_ln(arr);
//                } catch (IllegalArgumentException e) {
//                    System.out.println("Не удалось вычислить сумму элементов массива из-за ошибки");
//                    System.out.println( e.getMessage() );
//                }
//
//                Scanner sc = new Scanner(System.in);
//                System.out.print("Введите число X: ");
//                int x = 0;
//
//                sc.close();
//
//                try {
//                     x = sc.nextInt();   // что будет, если ввести "abc"?
//                } catch ( InputMismatchException e ) {
//                    System.out.println("Вы ввели не число! Используем значение X по умолчанию");
//                    x = 10;
//                } catch ( IllegalStateException e ) {
//                    System.out.println("Канал считывания закрыт! Используем значение X по умолчанию");
//                    x = 10;
//                }
//
//        System.out.println("X = " + x);


        }
    }