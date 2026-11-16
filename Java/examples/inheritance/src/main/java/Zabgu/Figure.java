package Zabgu;

// Базовый (родительский, суперкласс) класс для всех геом. фигур
public class Figure {
    public double x, y;
    public String color;

    Figure(){
        x = 0.0;
        y = 0.0;
        color = "white";}

    Figure(double x1, double y1, String color1){
        x = x1; y = y1; color = color1;}

    public void move(double x1, double y1){
        x = x1; y = y1;}


    public String toString() {
        return String.format( "x = %.2f, x = %.2f, color = %s", x, y, color);
    }

}
