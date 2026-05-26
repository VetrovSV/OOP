package Zabgu;
/// Модуль для финансовых вычислений


public class Finance {

    /// Функция вычисляет итоговую сумму вклада
    ///  s0 - ....
    /// percent - ...
    /// time - ...
    /// Возвращает итоговую сумму вклада
    public static double deposit_calc( double s0,  double percent, int time ){
        // double (который записан перед именем функции) -- тип возвращаемого значения
        // s0, percent, time -- формальные аргументы(параметры) функции
        double s;       // локальная переменная

        s = s0 * Math.pow( (percent+100.0)/100.0,  time);
        // Возврат значения
        return s;
    }
}
