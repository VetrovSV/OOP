package Zabgu;

public class Bot4 implements IBot {

    String[] questions_regex = {
            "привет.*!*",        //
            "пока.*!*",          //
            "\\d+\\+\\d+",        //
    };

    String[] answers = { "Привет!", "Пока!", "Я не умею складывать числа" };


    @Override public String answer(String input){
        input = input.toLowerCase();

        for( int i = 0; i < questions_regex.length; i++){
            String regex = questions_regex[i];
            if ( input.matches( regex ) ){
                return answers[i];
            }
        }
        return "Я тебя на понял";
    }
}
