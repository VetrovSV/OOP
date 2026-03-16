package Zabgu;


///
public class Bot implements IBot {

    ///
    @Override
    public String answer(String user_input) {
        String input = user_input.toLowerCase();

        if ( input.matches( "привет.*!*" ) ) return "Привет!";
        if ( input.equals( "пока!" ) )   return "Пока!";
        if ( input.equals( "2+2" ) )     return "5";
        return "Я тебя не понял";
    }

}


/**
 *
 *
 * - Диаграмма классов, реализация
 * - Словарь
 * - Callable
 */