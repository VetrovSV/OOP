package Zabgu;



import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

import java.util.function.Function;

public class Main {

    public static String foo(Integer x){
        return "111";
    }

    public static String bar(Integer x){
        return "skjfdhskjfhsdkfhkjsdf";
    }

    public static void main(String[] args) {//TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text

        // переменная f - указатель на функцию,
        // которая принмиает 1 аргумент типа Integer
        // возвращает значение типа String
        Function<Integer, String> f;
        f = Main::foo;
        f = Main::bar;

        foo(1);
        Main.foo(1);

        // вызов функции, на которую указывает переменная f
        f.apply(1);

        IBot b = new Bot4();
        System.out.println( b.answer("Привет!") );
        System.out.println( b.answer("Привет!") );
        System.out.println( b.answer("Привет") );
        System.out.println( b.answer("ПРиВеТ") );

        System.out.println( b.answer("/time") );

//        {
//            IBot b = new Bot3();
//            String fact = b.answer("Привет!");
//            assert   fact.equals("Привет!") ;
//            assert   b.answer("привет!") .equals("Привет!");
//        }

//        {
//            IBot b = new Bot3();
//            assert   b.answer("привет!!") .equals("Привет!");
//            assert   b.answer("привет") .equals("Привет!");
//            assert   b.answer("привет, Бот!") .equals("Привет!");
//
//        }
//
//
//        {
//            IBot b = new Bot3();
//            String fact = b.answer("Пока!");
//            assert   fact.equals("Пока!") ;
//            assert   b.answer("ПоКа!") .equals("Пока!");
//        }
//
//        {
//            IBot b = new Bot3();
//            String fact = b.answer("2+2");
//            assert   fact.equals("5") ;
//        }
//
//        {
//            IBot b = new Bot3();
//            String fact = b.answer("ыловарыловарывлоарывла");
//            assert   fact.equals("Я тебя не понял") ;
//        }
//
//        {
//            IBot b = new Bot3();
//            String fact = b.answer("");
//            assert   fact.equals("Я тебя не понял") ;
//        }




    }
}