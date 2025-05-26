/** Отдельные обработчики (функции)
 *  для выдачи ответа на отдельные запросы пользователя.
 *
 *  Эти функции стоит использовать в паре с регулярными выражениями,
 *  которые будут проверять подходит ли введённый пользователем текст,
 *  под заданный шаблон. Например запрос погоды.
 *
 *  Ссылки на функции добавляются в динамический массив бота (см. mainwindow.cpp)
*/
#ifndef ANSWERS_H
#define ANSWERS_H
#include <string>

/// указатель на функцию
using AnswerFunc = std::string(*)(const std::string&);

std::string hello(const std::string& );         // ответ на приветствие
std::string calc(const std::string& );          // ответ на запрос вычислений
std::string weather(const std::string& );       // ответ на запрос погоды
std::string get_ip(const std::string& );        // ответ не запрос внешнего IP


#endif // ANSWERS_H
