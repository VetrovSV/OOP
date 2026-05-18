package Zabgu;

import java.lang.Math;
import java.util.Scanner;

// Определить индекс массы тела если дан рост h (метры) и масса m (кг)
// I = m / h^2

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        // масса в кг
        double m;

        System.out.printf("Введите массу в кг:");
        m = input.nextDouble();

        // рост в метрах
        double h;

        System.out.printf("Введите рост в метрах:");
        h = input.nextDouble();

        // индекс массы тела
        double I;

//        I = m / ( h*h );
        I = m / Math.pow(h, 2.0);

        System.out.printf("Индекс массы тела: %.1f", I);

    }
}
