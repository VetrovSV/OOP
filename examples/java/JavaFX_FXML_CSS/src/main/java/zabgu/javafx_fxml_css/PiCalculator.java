package zabgu.javafx_fxml_css;

import java.util.Random;

// Клас для вычислений числа Пи методом монте-карло
// https://habr.com/ru/articles/128454/
public class PiCalculator {


    public static double calc_pi(int points_n){
        int m = 0;
        Random rnd = new Random();

        for (int i = 0; i < points_n; i++) {
            double x = rnd.nextDouble();
            double y = rnd.nextDouble();

            if ( x*x + y*y < 1) m++;
        }

        return  4.0 * m / points_n;
    }
}
