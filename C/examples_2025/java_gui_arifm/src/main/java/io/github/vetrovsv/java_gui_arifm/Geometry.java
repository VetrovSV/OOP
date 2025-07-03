package io.github.vetrovsv.java_gui_arifm;
// Функции из этого файла доступны из других файлов автоматически, если у них такой же package


public class Geometry {


    /**
     * @brief Функция для вычисления площади треугольника по длине основания a и высоте h
     * @param a - основание треугольника
     * @param h - высота, опушенная на основание a
     * @return
     */
    public static double triangle_area(double a, double h){
        double S = 0.5 * a * h;
        return S;
    }

}
