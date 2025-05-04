/**
 * @brief тут краткое описание файла
 * @author Vetrov
 */
// todo: см. интеграцию Qt со стандартом документирования кода Doxygen

#ifndef ABSTRACTCHATBOT_H
#define ABSTRACTCHATBOT_H

#include <string>

// см. диаграмму классов Untitled Diagram.drawio.png

/**
 * Абстрактный класс определяющий интерфейс для чат бота.
 * Нужен для соблюдения принципа Инверсии зависимостей (Dependency Inversion) из SOLID.
 */
class AbstractChatBot
{
public:
    AbstractChatBot();

    /// Отвечает на реплику input
    virtual std::string answer(const std::string& input) = 0;

};

#endif // ABSTRACTCHATBOT_H
