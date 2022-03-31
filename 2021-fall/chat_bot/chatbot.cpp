#include <cctype>
#include <algorithm>
#include <locale>

#include <regex>

#include "chatbot.h"

using namespace std;


ChatBot::ChatBot()
{

}

// ответ на зпрос пользователя
std::string ChatBot::answer(const std::string& input){

    for (unsigned i = 0; i<answer_funcs.size(); i++ ) {

        regex r = answer_funcs[i].first;
        AnswerFunc f = answer_funcs[i].second;

        if ( regex_match(input, r) ){
            return f( input );
        }

    }

    return "???";

    // старый вариант метода:
    // todo: предобработка строки: к нижнему регистру, strip, убрать множественные пробелы

    // Std::string плохо работает с не ASCII символами при смене регистра
    // поэтому будет передавать в функцию сразу нижний регистр

    regex hello("привет[!.]{0,1}");

    // Вариант обработки ввода #1:
     if ( regex_match( input, hello ) )
            return "Hello";
    // else if рег.выражение_2
    //         return hello_world();
    // todo: сделать цикл по рег. выражениям
     else return "???";


    // вариант 2: использовать ассоциативный массив с условными обозначениями фраз
    // input -> усл.обозначение
     // return фразы[усл.обозначение]
}

void ChatBot::add_answer(const std::regex &regex, AnswerFunc func){
    std::pair<std::regex, AnswerFunc> p;
    p.first = regex;
    p.second = func;

    answer_funcs.push_back( p );
}



