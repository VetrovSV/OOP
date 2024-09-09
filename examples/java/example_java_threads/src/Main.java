import static java.lang.Math.*;

import java.lang.Thread;
import java.lang.Runnable;   // для запуска функции в отдельном потоке

import java.util.concurrent.*;  // Для запуска функции возвращающей значение в отдельном потоке


public class Main {


    private static int n = 10000000;


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


    // функция для выполнения в потоке и возврата значения
    private static double foo2(int n){
        double sum = 0;
        for (int i = 0; i<n; i++){
            sum += sin(i);
        }
        return sum;
    }



    // Пример 1. Простое создание потока и ожидание его завершения
    private static void example1(){
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


    // Пример 2. Возврат значения из потока
    private static void example2(){

        ExecutorService ex_ser = Executors.newSingleThreadExecutor();

        Future<Double> result = ex_ser.submit(new Callable<Double>(){
            @Override
            public Double call(){
                return Double.valueOf(foo2(n));
            }
        });

        Double sum = 0.0;
        try{
            sum = result.get(); //  Ожидание завершения потока
        } catch (Exception e){
            e.printStackTrace();
        }


        System.out.print("Sum = " + sum.toString());

        ex_ser.shutdown();

    }



    public static void main(String[] args) {

        // Простой запуск потоков
//        example1();

        // Запуск потока с возвратом значения
        example2();

        // Аналогичную примеру 2 работу можно было реализовать:
        // 1. создав потомка от класса Thread
        // 2. Добавив в этот класс поле для хранения результата
        // 3. Запустить поток, в методе run вызвать foo2, записать возвращённое значение в поле класса
        // 4. Дождаться завершения потока (join) и прочитать его поле


    }
}
