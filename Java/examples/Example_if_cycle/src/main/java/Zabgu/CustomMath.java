package Zabgu;

public class CustomMath {

    // определение функции

    /// Вычисляет и возвращает сумму ряда, где слагаемое вычисляется по формуле:
    /// ln(i) * cos( 3*i*w ) / (i!+1), i = 1...N,    /// Находит и возвращает сумму для i = 1...N, где слагаемое:
    /// ln(i) * cos( 3*i*w ) / (i!+1)
    static double sum_of_series(double w, int N)     // заголовок функции
    // тело функции
    {
        // формальные аргументы (параметры) - w, N
        // Локальнеы переменные:
        double S = 0.0, a = 0.0;
        double f = 1.0;

        for ( int i = 1;
              i<=N;
              i++){
            f = f * i;
            a = Math.log( i ) * Math.cos ( 3.0 * i * w ) / (f + 1.0);
            S = S + a;}

        // возврат значения из функции
        return S;
    }



    static void test_sum(){
        //        ln(i) * cos( 3*i*w ) / (i!+1), N = 1, w = 1
//        ответ = 0.0

//        ln(i) * cos( 3*i*w ) / (i!+1), N = 2, w = 1
//        ответ = 0.22184644235

        // ..

        assert  CustomMath.sum_of_series(1.0, 1) == 0.0 ;
        assert  Math.abs(CustomMath.sum_of_series(1.0, 2) - 0.22184644235) < 1e-6;

        // FIXME: добавить ещё один тест
    }

}
