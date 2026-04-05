package Zabgu;

import java.util.HashMap;

public class Bot2 implements IBot {

    HashMap<String, String> questions_answers = new HashMap<>();

    Bot2(){
        questions_answers.put( "привет!", "Привет!" );
        questions_answers.put( "привет", "Привет!" );
        questions_answers.put( "привет!!", "Привет!" );
        questions_answers.put( "привет, бот!", "Привет!" );
        questions_answers.put( "пока", "Пока!" );
        questions_answers.put( "пока!", "Пока!" );
        questions_answers.put( "2+2", "5" );
    }

    @Override
    public String answer(String input){
        input = input.toLowerCase();

        // get выдаёт значение по ключу (здесь input) или null, если такого ключа нет
        String answer = questions_answers.get( input );

        if (answer == null) return "Я тебя не понял";
        else return answer;
    }

}
