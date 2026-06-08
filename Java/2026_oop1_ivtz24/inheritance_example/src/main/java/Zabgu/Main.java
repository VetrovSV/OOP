package Zabgu;


public class Main {
    public static void main(String[] args) {

        int x;

        Vector2D v1 = new Vector2D(3.0, 4.0);
        // v1 -- переменная - ссылка на объект класса Vector2D
        // объект = экземпляр класса

        System.out.println( v2.x );
        System.out.println( v2.y );
        System.out.println( v1.abs() );


        Vector3D v2 = new Vector3D(3.0, 4.0, 5.0);

        System.out.println( v2.abs() );     // 7.07
        System.out.println( v2.x );
        System.out.println( v2.y );
        System.out.println( v2.z );



    }
}