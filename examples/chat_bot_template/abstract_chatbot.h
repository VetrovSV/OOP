#ifndef ANSTRACTCHATBOT_H
#define ANSTRACTCHATBOT_H

#include <string>
#include <list>
#include "chat_history.h"

/*
 * Абстрактный класс чат-бот.
 * Описывает программный интерфейс чат-бота.
 * Не дописывайте этот класс.
 * Создайте свой класс, унаследовавшись от этого и реализовав все методы.
 * Можно немного изменить класс, но не рекомендуется менять его имя и имя методов reply и help.
 *
 * */
class AbstractChatBot{

public:
    // История сообщений чат-бота и пользователя
    ChatHistory messages;

    AbstractChatBot();

    // Ответ чат-бота на сообщение text
    // Здесь должна быть запись сообщения в историю,
    // обработка сообщения, выбор ответа и сам ответ
    // рекомендуется привести text к нижнему регистру
    // Документация по std::string:
    // https://ru.cppreference.com/w/cpp/string/basic_string

    virtual std::string reply(const std::string text) = 0;

    // Возвращает для пользователя информацию о чат-боте.
    virtual std::string help() const = 0;

};

#endif // ANSTRACTCHATBOT_H
