package Zabgu;

import java.util.Random;

public class Main {
    public static void main(String[] args) {

//        Figure f1; = new Figure(10.000000001, 20, "red");
//        Figure f2; = new Figure(10.000000002, 20, "red");



        // System.out.println( f1.equals( f2 ) );
//        System.out.println( f1.equals( f2 ) );
//
//        f.move(100, 200);
//        System.out.println( f );
//
//
        Random rnd = new Random();
        Circle circles[] = new Circle[10];
        Square squares[] = new Square[10];

        Figure figures[] = new Figure[20];

        for (int i = 0; i < circles.length; i++){
            if ( rnd.nextBoolean() == true )
                figures[i] = new Circle(rnd.nextDouble(0.01, 100));
            else
                figures[i] = new Square(rnd.nextDouble(0.01, 100));
        }

        double S = 0.0;

        for (int i = 0; i < circles.length; i++) {
            S+=figures[i].area();
        }

        System.out.printf("S = %.2f", S);

//        for (int i = 0; i < circles.length; i++) {
//            circles[i] = new Circle( rnd.nextDouble(0.01, 100) );
//        }
//
//        for (int i = 0; i < squares.length; i++) {
//            squares[i] = new Square( rnd.nextDouble(0.01, 100) );
//        }



//        for (int i = 0; i < circles.length; i++) {
//            S += circles[i].area();     }
//
//        for (int i = 0; i < squares.length; i++) {
//            S += squares[i].area();
//        }




//
//        c1.move(11231, 123123);
//        System.out.println( c1.toString() );
//        System.out.println( c1.getRadius() );
//
//        s1.move(122, 544);
//        System.out.println( s1.toString() );

    }
}