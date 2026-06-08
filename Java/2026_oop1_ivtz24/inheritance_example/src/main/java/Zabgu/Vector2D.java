package Zabgu;


public class Vector2D {

    public double x;
    public double y;

    private int color;

    protected String text;

    public Vector2D() { x=0.0; y = 0.0; }

    public Vector2D(double x1, double y1) { x=x1; y = y1; }

    public double abs(){
        return Math.sqrt( x*x + y*y);
    }

    @Override
    public String toString(){
        return String.Format("(%.2f, %.2f,)", x, y);
    }
}



// Vector3D -- потомок (производный класс)
// Vector2D -- предок (базовый класс)
public class Vector3D extends Vector2D {
    public double z;

    public Vector3D() { 
        // Vector2D(); конструктор по умочланию базовго класса вызывается автоматически
        z = 0.0; }

    public Vector3D(double x1, double y1, double z1) { Vector2D(x1, y1); z = z1;}

    
    // переопределение метода базового класса -- создание новой версии метода, но с другим телом
    @Override
    public double abs(){
        return Math.sqrt( x*x + y*y + z*z);
    }

    @Override
    public String toString(){
        return String.Format("(%.2f, %.2f, %.2f)", x,y,z);
    }


}