///
#ifndef CHATBOT_H
#define CHATBOT_H

#include <regex>
#include <string>
#include <vector>

#include "abstractchatbot.h"
#include "answers.h"


///
class ChatBot : public AbstractChatBot {
private:
    // набор из <рег.выраж-для-запроса-пользователя, адр.функции-выдающий-ответ-на-запрос>
    std::vector < std::pair<std::regex, AnswerFunc> > answer_funcs;
    // см. answers.h

public:
    ChatBot();

    std::string answer(const std::string& ) override;

    /// Добавление нового обработчика(функции) на запрос пользователя
    void add_answer(const std::regex &regex, AnswerFunc func);
    // см. answers.h и вызов метода в конструкторе окна

    // todo:

};

#endif // CHATBOT_H
