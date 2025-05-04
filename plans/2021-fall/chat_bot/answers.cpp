#include <math.h>

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <qeventloop.h>

#include "answers.h"

// ответ на приветствие
std::string hello(const std::string& ){
    // todo: сделать массив из приветствий
    switch (rand()%2){
       case 0: return "Hello";
       case 1: return "Hi!";
    }
}


// ответ на запрос вычислений
std::string calc(const std::string& ){return "42";}


// ответ на запрос погоды
std::string weather(const std::string& ){return "15 C";}


// ответ не запрос IP (публичного)
std::string get_ip(const std::string& ){
    // Объект для выполнения сетевых запросов
    // для работы с сетевыми запросами нужно подключить модуль network в pro файле: QT += network
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    // QNetworkRequest(QUrl("https://icanhazip.com/")) -- конструктор HTTP запроса
    // netReply -- указатель на объект, который: умеет ждать ответа на запрос, умеет хранить запрос
    QNetworkReply *netReply = manager->get(QNetworkRequest(QUrl("https://icanhazip.com/")));
    // Ответ на запрос может занимать заметное количество времени
    // Реализуем простой вариант -- ожидание ответа
    QEventLoop loop;    // Объект, который умеет ждать (содержит в себе бесконечный цикл)
    // Соединим сигнал о получении ответа с заверением бесконечного цикла ожидания
    QObject::connect(netReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    // Запуск бесконечного цикла, пока не будет получен сигнал от netReply
    loop.exec();
    // readAll() возвращает QString с содержимым

    delete netReply;
    return netReply->readAll().toStdString();
}
// https://icanhazip.com -- сайт который показывает IP посетителя и больше ничего
