package Zabgu;

public class Main {
    public static void main(String[] args) {

        // Класс - ссылочный тип данных

        // с2 -- ссылка на объект ( объекта пока нет )
        Cuboid c2;
        // с3 -- ссылка на объект ( объекта пока нет )
        Cuboid c3 = null;

        // Создаём объект ( new ), инициализируем объект (  Cuboid() )
        c2 = new Cuboid();
        c3 = new Cuboid( 6.0, 6.0, 3.0 );

        try {

            Cuboid c1 = new Cuboid( 12.0, 6.0, 3.0 );
            c1.setWidth( 6.5 );
            System.out.println( c1.getHeight() );
            System.out.println( c1.toString() );
            System.out.println( c1 );

        } catch (IllegalArgumentException e) {
            System.out.println( e.toString() );
        }


//        double[] arr = new double[10];
        // массив из 5 ссылок на объекты. Сами объекты пока не созданы
        Cuboid[] boxes = new Cuboid[5];

        for (int i = 0; i < 5; i++) {
            // Создание и инициализация объекта
            boxes[i] = new Cuboid();
        }

        boxes[0].setLength(10.0);


    }
}