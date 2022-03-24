package javafx_hello_world;

import java.util.Random;

// генерирует случайные числа
// этот класс - модель в программе
public class MyRndNumber {
    private int min;
    private int max;

    public MyRndNumber(){
        this.min=0;
        this.max=100;
    }

    public MyRndNumber(int _min, int _max){    // Java не поддерживает дефолтные значения параметров
        this.min=_min;
        this.max=_max;
    }

    public int get_number(){
        Random random = new Random();
        return random.nextInt(max - min) + min;
    }

    public int getMin() {
        return max;
    }

    public int getMax() {
        return max;
    }

    public void setMax(int max) {
        if (max < min) throw new IllegalArgumentException();
        this.max = max;
    }

    public void setMin(int min) {
        if (min > max) throw new IllegalArgumentException();
        this.min = min;
    }
}
