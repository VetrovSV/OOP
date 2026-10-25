package Zabgu;

// Пареллепипед
public class Cuboid {
    private double length, width, height;   // длина, ширина, высота

    // Конструктор -- метод инициализирующий объект
    public Cuboid(double length1, double width1, double height1){
        setLength(length1);
        setWidth(width1);
        setHeight(height1);
    }

    // Конструктор -- метод инициализирующий объект
    public Cuboid(){
        length = 1.0;
        width  = 1.0;
        height = 1.0; }

    // Сеттер для Длины
    /// length1 -- длина, должна быть > 0
    /// бросает исключение IllegalArgumentException, если длина < 0
    public void setLength(double length1){
        if ( length1 < 0 )  // проверка предусловия - требования к входным данным
            throw new IllegalArgumentException("...");
        length = length1;}

    // Сеттер для Ширины
    public void setWidth(double  width1){
        if ( width1 < 0 )  // проверка предусловия - требования к входным данным
            throw new IllegalArgumentException("...");
        width = width1;}

    // Сеттер для Высоты
    public void setHeight(double height1){
        if ( height1 < 0 )  // проверка предусловия - требования к входным данным
            throw new IllegalArgumentException("...");
        height = height1;    }

    // геттер для Длины
    public double getLength(){ return length; }
    // геттер для Длины
    public double getWidth(){ return width; }
    // геттер для Длины
    public double getHeight(){ return height; }


    public String toString(){
        String info = String.format( "Длина %.2f; Ширина %.2f; Высота %.2f", length, width, height );
        return info;
    }
}


// public       +
// protected    #
// private      -
/*

+-------------------------------+
|     Cuboid                    |
+-------------------------------+



 */