package Zabgu;


// Объявление нового типа данных -- Book
public class Book{
    // Поля класса (переменные внутри класса)
    private int pages_count;        // количество страниц
    private String title;           // название
    public String author;          // автор
    // ...

    // функция инициализации -- Конструктор без параметров -- конструктор по умолчанию
    public Book(){
        pages_count = 0;
        title = "Без названия";
        author = "Без автора"; }

    // функция инициализации -- Конструктор с параметрами
    public Book( int pages_count1,  String title1, String author1){
        set_pages_count( pages_count1 );
        set_title ( title1 );
        author = author1;
    }


    public void set_pages_count(int pages_count1 ) {
        // сеттер для поля pages_count
        if (pages_count1 >= 0) {
            pages_count = pages_count1;
        }
    }

    public int get_pages_count(){
        return pages_count;}

    public String get_title(){
        return title;}

    public void set_title( String title1 ){
        if ( ! title1.equals("") ){
            title = title1;}
    }

    public String toString(){
        String info =  String.format("%s, %s, %d стр.", title, author, pages_count );
        return info;
    }

}

// - Абстрагирование
// - Инкапсуляция = создание в классе полей и методов для работы с полями
//                  (методы, контролирует корректность данных)
// - Принцип сокрытия
// Метод -- функция, объявленная внутри класса
// Конструктор
// Сеттер -- метод, который проверяет корректность задаваемого значения, и если оно корреткно, то записывает его в поле класса
// Геттер -- метод, который возвращает значение поля класса
//