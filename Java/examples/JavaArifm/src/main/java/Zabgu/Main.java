package Zabgu;

import java.util.Scanner;

// Вычислить синус угла заданного в градусах

public class Main {

    public static void main(String[] args) {

        Scanner scaner = new Scanner(System.in);
        double a = 0.0;     // угол в радианах
        double a_deg;       // угол в градусах
        double sina = 0.0;  // синус угла в градусах

        System.out.println( "Введите угол в градусах" );
        a_deg = scaner.nextDouble();

        a = a_deg / 180.0 * Math.PI;

        sina = Math.sin( a );

        System.out.printf("sin(%f) = %f\n", a_deg, sina);

        }
    }