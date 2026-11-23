package Zabgu;

// Circle - потомок (дочерний, производный, подтип) класса Figure
/// Круг
public class Circle extends Figure {
    // класс Circle берёт все поля и методы из класса Figure
    // в этом классе есть 3 унаследованных поля из класса Figure
    // в этом классе есть 2 унаследованных метода: move, toString()

    private double radius;

    Circle(){
        // здесь будет происходить неявный автоматический вызов конструктора базвого класса
        radius = 1.0;
    }

    Circle(double radius1){
        // здесь будет происходить неявный автоматический вызов конструктора базвого класса
        radius = 0.0;
        setRadius(radius1);
    }

    Circle(double x1, double y1, String color1, double radius1){
        // здесь будет происходить неявный автоматический вызов конструктора базвого класса
        super( x1, y1, color1); // вызов конструктора базового класса
        radius = 0.0;
        setRadius(radius1);
    }

    public void setRadius(double radius1){
        if ( radius1 >= 0 ) radius = radius1;}

    public double getRadius(){ return radius; }

    @Override
    public double area(){
        return Math.PI * radius * radius;
    }

    @Override
    public double perimeter(){
        return 2 * Math.PI * radius;
    }


    // переопределение метода toString из базового класса
    // переопределение - создание новой версии метода с другим телом (реализацией), но с таким же заголовком
    @Override
    public String toString(){
        // super.toString() -- вызов метода toString из базового класса
        return super.toString() + String.format(", radius = %.2f", radius);
    }

    // TODO: equals



}
