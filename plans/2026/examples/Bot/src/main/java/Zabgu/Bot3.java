package Zabgu;

import java.util.HashMap;
import java.util.function.Function;
import java.util.Random;
import java.time.LocalDateTime;


public class Bot3 implements IBot {

    public HashMap< String, Function<String, String> >  questions_functions =
            new HashMap<>();

    ///
    public static String hello(String input){
        String answers[] = {"Привет!", "Здравствуй!", "Приветствую!"};
        Random r = new Random();
        int ind = r.nextInt(0,3);
        return answers[ind];
    }

    public static String bye(String input){
        return "Пока!"; }

    public static String plus(String input){
        return "5"; }


    public static String get_time(String input){
        LocalDateTime t = LocalDateTime.now();
        return t.toString();
    }

    Bot3(){
        questions_functions.put( "привет!",  Bot3::hello);
        questions_functions.put( "пока!",  Bot3::bye);
        questions_functions.put( "2+2",  Bot3::plus);
        questions_functions.put( "/time",  Bot3::get_time);
    }

    @Override public String answer(String input){
        input = input.toLowerCase();

        Function<String, String> answer_func = questions_functions.get ( input );

        if (answer_func == null )
            return "Я тебя не понял";
        else
            // .apply - вызов функции, адре который запсиан в answer_func
            // .apply вернёт строку (String)
            return answer_func.apply( input );
    }
}
