package Zabgu;

import java.lang.Math;          // подключение библиотеки Math;
import java.util.Scanner;       // подключение класса Scanner для считывания данных с консоли

// Стандартная библиотека Java имеет древовидное устройство, где одни пакеты содержат другие пакеты и отдельные классы и модули


// Определить индекс массы тела если дан рост h (метры) и масса m (кг)
// I = m / h^2

public class Main {


    // главный метод (функция) программы
    public static void main(String[] args) {

        // Создадим переменную для считывания данных с консоли
        Scanner input = new Scanner(System.in);

        double m;   // масса в кг
        double h;   // рост в метрах
        double I;   // индекс массы тела

        System.out.printf("Введите массу в кг:");
        m = input.nextDouble();     // считываем вещественное число, которое ввел пользователь

        System.out.printf("Введите рост в метрах:");
        h = input.nextDouble();

//        I = m / ( h*h );
        I = m / Math.pow(h, 2.0);

        System.out.printf("Индекс массы тела: %.1f", I);
        // %.1f - выводим вещественное число с одним знаком после запятой

    }
}
