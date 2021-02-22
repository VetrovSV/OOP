package javafx_hello_world;

import java.util.Random;

// генерирует случайные числа
// этот класс - модель в программе
public class MyRndNumber {
    private int min=0;
    private int max=100;

    // todo: сделать геттеры и сеттеры для min и max, конструктор с параметрами
    public int get_number(){
        Random random = new Random();
        return random.nextInt(max - min) + min;
    }
}
