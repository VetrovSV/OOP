package Zabgu;

// Базовый (родительский, суперкласс) класс для всех геом. фигур
public abstract class Figure /* extends Object */{
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


    @Override
    public String toString() {
        return String.format( "x = %.2f, x = %.2f, color = %s", x, y, color);
    }

    @Override
    public boolean equals(Object o){
        Figure f2 = (Figure)o;
        // return (f2.x == this.x) && (f2.y == this.y) && ( f2.color.equals( this.color ) );//
        return ( Math.abs(f2.x - this.x) < 1.e-9 ) &&
               ( Math.abs(f2.y - this.y) < 1.e-9 ) &&
               ( f2.color.equals( this.color ) );
    }

    public abstract double area();

    public abstract double perimeter();
}
