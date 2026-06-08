package Zabgu;


import Library.Book;


public class Main {

    public static void main(String[] args) {

//         b1 -- переменная типа Book -- ссылка на объект -- ссылка на экземпляр класса Book
        Book b1 = new Book( -120, "Незнайка на Луне", "Николай Носов" );
//
//
        b1.author;
        System.out.println( b1.toString() );
//
//        // b2 -- переменная типа Book -- объект -- экземпляр класса Book
//        Book b2 = new Book();       // вызывается конструктор без параметров
////        b2.pages_count = 500;
//        b2.set_pages_count( 500 );
//        b2.set_title("1984");
//        b2.author = "Джордж Оруэл";
//
//        b2.set_title(  "" );
////        System.out.println( b2.get_title() );
//
//        System.out.println( b2.toString() );
//
//
//        Book b3 = new Book();        // вызывается конструктор без параметров
//        b3.set_pages_count( 20 );
////        System.out.println( b3.get_pages_count() );
////
//        b3.set_pages_count(-22);
////        System.out.println( b3.get_pages_count() );
//
//        System.out.println( b3.toString() );
//

        // Массив из объектов


        Book b = new Book();
        // b - переменная которая хранит адрес объекта ( b ~ объект )

        // массив из 10 ссылок на книги
        Book[] books = new Book[10];

        books[0] = new Book(200, "Язык программирования Python", "Гвидо Ван Россум");

        for ( int i = 1; i<10; i++){
            books[i] = new Book();
        }

        // books[1] -- обращение к элементу массива ( ссылке на объект )
        books[1].set_title("Язык программирования C++");
        // .set_title("Язык программирования C++"); -- вызов метода


        for ( int i = 0; i<10; i++){
            System.out.print( books[i].toString() + "\n");
        }
        }
    }