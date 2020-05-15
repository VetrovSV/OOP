#ifndef CHATHISTORY_H
#define CHATHISTORY_H
#include <string>
#include <list>
/*
 * Класс для работы с историей сообщений чата.
 * Хранит, сохраняет и загружает истории сообщений из файла.
*/
class ChatHistory
{
    // список из сообщений бота и пользователя
    // можете использовать такой формат,
    // но можно реализовать свою структуру данных,
    // которая будет в удобном формате хранить время сообщения,
    // его автора и само сообщение
    std::list<std::string> messages;
    // см. документация по контейнеру list и похожему контейнеру vector
    // имя файла, для сохранения\загрузки сообщений
    std::string filename;
public:
    ChatHistory();
    // добавляет сообщение в конец истории сообщений
    void append(const std::string &text);
    std::string getFilename() const;
    void setFilename(const std::string &value);
    // возвращает количество сообщений
    std::size_t messageCount() const;
    // возвращает набор сообщений
    std::list<std::string> get_messages() const;
    // сохраняет сообщения в файл
    void save2file() const;
    // загружает сообщения из файла. Возвращает true, если загрузка успешна
    bool loadFromFile();
};
#endif // CHATHISTORY_H
