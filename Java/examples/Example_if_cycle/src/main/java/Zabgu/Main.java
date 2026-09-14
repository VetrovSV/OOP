package Zabgu;

// подклчение типа (класса) для чтения данных с клавиатуры
import java.util.Scanner;
// Найти сумму для i = 1...n, где слагаемое:
// ln(i) * cos( 3*i*x ) / (i!+1)

import java.math.*;


public class Main {


    public static void main(String[] args) {

        CustomMath.test_sum();


        // Локальнеы переменные:
        double S = 0.0, x = 0.0;
        int n = 0;

        Scanner sc = new Scanner(System.in);
        System.out.println("Введите х = ");
        x = sc.nextDouble();

        System.out.println("Введите n = ");
        n = sc.nextInt();

        // вызов функции
        S = CustomMath.sum(x, n);
        // фактические аргументы (параметры) - x, n;


        System.out.printf("S = %.4f\n", S);

//
//        if      ( x <= -3.0 )
//             y = 9.0;
//        else if ( x <= 0.0 )
//             y = x*x;
//        else y = 3.0 * x;
//
//        System.out.printf("y = %.4f\n", y);
        }
}