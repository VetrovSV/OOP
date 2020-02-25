import static java.lang.Math.*;

import java.lang.Thread;
import java.lang.Runnable;


public class Main {

    // функция для выполнения в потоке
    private static void foo(int n, char c){
        // с - символ обозначающий 10% прогресса
        int d = n/10;
        double sum = 0;
        for (int i = 0; i<n; i++){
            sum += sin(i);
            if (i%d==0) {System.out.print(c);}
    }
        System.out.print("\nSum = " + sum);
    }


    // Пример 1. Простое создание потока и ожидание его завершения
    private static void example1(){
        int n = 100000000;

        // Объект для выполнения функция в отдельном потоке
        // Функция должна быть обёрнута в класс Runnable
        Thread th1 = new Thread(new Runnable() {
            @Override
            public void run() {
                foo(n,'.');
            }
        });

        Thread th2 = new Thread(new Runnable() {
            @Override
            public void run() {
                foo(n,'-');
            }
        });

        // Запуск потоков
        th1.start();
        th2.start();

        try {
            // Ожидание завершения потоков
            // join бросает проверяемые исключения, поэтому нужен try\catch
            th1.join();
            th2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }



    public static void main(String[] args) {

        // Простой запуск потоков
        example1();


    }
}
