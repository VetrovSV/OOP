package Zabgu;



import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

import java.util.function.Function;

import com.fasterxml.jackson.databind.ObjectMapper;


public class Main {

    public static String foo(Integer x){
        return "111";
    }

    public static String bar(Integer x){
        return "skjfdhskjfhsdkfhkjsdf";
    }



    public static void main(String[] args) throws IOException, InterruptedException {


        HttpClient client = HttpClient.newHttpClient();

// удобный способ записи JSON строки
        String json = """
        {
          "model": "smollm2:135m",
          "prompt": "What is standard deviation?",
          "stream": false
        }
        """;

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("http://localhost:11434/api/generate"))
                .header("Content-Type", "application/json")
                .POST(HttpRequest.BodyPublishers.ofString(json))
                .build();
// в коде выше вызывается серия методов, каждый из которых (короме build) возвращает объект типа HttpRequest.Builder, но с заданными свойствами (полями).

// HttpRequest возвращает объект типа HttpRequest


        HttpResponse<String> response = client.send(
                request,
                HttpResponse.BodyHandlers.ofString()        // возвращает специальный объект, который умеет преобразовывать строку с JSON данными в формат подхходящий для тела HTTP запроса.
        );

        System.out.println( response.statusCode() );

        if ( response.statusCode() == 200 )
            System.out.println( response.body() );
//
//
//        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
//
//        // переменная f - указатель на функцию,
//        // которая принмиает 1 аргумент типа Integer
//        // возвращает значение типа String
//        Function<Integer, String> f;
//        f = Main::foo;
//        f = Main::bar;
//
//        foo(1);
//        Main.foo(1);
//
//        // вызов функции, на которую указывает переменная f
//        f.apply(1);
//
//        IBot b = new Bot4();
//        System.out.println( b.answer("Привет!") );
//        System.out.println( b.answer("Привет!") );
//        System.out.println( b.answer("Привет") );
//        System.out.println( b.answer("ПРиВеТ") );
//
//        System.out.println( b.answer("/time") );

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