package Zabgu;

public class Main {
    public static void main(String[] args) {

        Figure f = new Figure(10, 20, "red");
        f.move(100, 200);
        System.out.println( f );


        Circle c1 = new Circle();
        Square s1 = new Square();

        c1.move(11231, 123123);
        System.out.println( c1.toString() );
        System.out.println( c1.getRadius() );

        s1.move(122, 544);
        System.out.println( s1.toString() );

    }
}