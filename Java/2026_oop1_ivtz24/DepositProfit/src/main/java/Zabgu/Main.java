package Zabgu;

// подключаем тип данных Scanner (нужен для чтения данных)
import java.util.Scanner;
import java.lang.Math;

import Zabgu.Finance; // не нужно, т.к. этот файл (Main.java) находится тоже в пакете Zabgu

/*
Программа вычисляет доход по вкладу
Исходные данные:
    - исходная сумма вклада S0
    - ставка годовая p %
    - срок в годах t

    S = S0 * ( (p+100)/100 ) ^ t

Вычислить -- доход и итоговую сумму после t лет
*/


public class Main {

    public static void main(String[] args) {

        // Проверка работы функции
        assert Math.round( Finance.deposit_calc( 100.0, 14.0, 5 ) ) == 193;
        assert Math.round( Finance.deposit_calc( 100.0, 10.0, 1 ) ) == 110;
        assert Math.round( Finance.deposit_calc( 100.0, 1.0, 10 ) ) == 110;
        assert Math.round( Finance.deposit_calc( 534_259.0, 18.0, 47 ) ) == 1_277_044_968;
        // для включения проверок (assert) нужно задать ключ для виртуальной машины -ea
        // Три точки возле кнопки запуска -> Edit -> Add VM Options -> записать  -ea в поле ввода VM Options
        //


        // Объявление переменной для считывания данных из консоли
        // Scanner -- тип данных переменой;
        // input -- идентификатор переменной
        Scanner input = new Scanner( System.in );

        double S0;  // исходная сумма вклада
        double p;   //  годовая ставка %
        int t;      // срок в годах t
        double S;   // итоговая сумма
        double profit;

        System.out.printf("Программа вычисляет доход по вкладу\n");
        System.out.printf("Исходная сумма вклада: \n");
        S0 = input.nextDouble();

        System.out.println("Cтавка ( % ): ");
        p = input.nextDouble();

        System.out.printf("срок в годах: \n");
        t = input.nextInt();

//        S = S0 * Math.pow( (p + 100.0) / 100.0, t );
        S = Finance.deposit_calc( S0, p, t );       // вызов функции deposit_calc
        // функция возвращает значение, оно будет записано в переменную S
        // S0, p, t -- передаваемые параметры функции ( фактические параметры )
        profit = S - S0;

        System.out.printf("Итоговая сумма %.2f\n", S);
        System.out.printf("Доход %.2f", profit);

    }
}