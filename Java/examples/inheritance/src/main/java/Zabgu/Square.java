package Zabgu;

public class Square extends Figure {
    public double side = 1.0;

    Square(){}

    Square(double side1) { side = side1; }

    @Override
    public double area(){ return side*side; }

    @Override
    public double perimeter(){ return 4*side; }
}
