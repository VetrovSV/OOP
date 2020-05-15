#include "chat_history.h"
ChatHistory::ChatHistory()
{
    // ...
}
std::string ChatHistory::getFilename() const
{
    return filename;
}
void ChatHistory::setFilename(const std::string &value)
{
    // TODO: ваш код, проверка предусловий
    filename = value;
}
std::size_t ChatHistory::messageCount() const
{
    // TODO: ваш код
}
std::list<std::string> ChatHistory::get_messages() const
{
    // TODO: ваш код
}
void ChatHistory::save2file() const
{
    // TODO: ваш код
    // list не поддерживает доступ по индексу
    // в истории чата это вряд ли нужно
    // пройтись по списку можно так
    for (const std::string &mes : this->messages){
        // TODO: записать все mes в файл
    }
    // TODO: ваш код
}
bool ChatHistory::loadFromFile()
{
    // TODO: ваш код
}
