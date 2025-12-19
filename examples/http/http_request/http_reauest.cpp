#include <iostream>

#include "httplib.h"
// библиотека только из заголовочного файла для HTTP запросов
// https://github.com/yhirose/cpp-httplib
// Требуется OpenSSL, устанвока в Убунту: sudo apt install libssl-dev
// См. также CmakeLists.txt


using namespace std;

int main() {
    // Объект для запросов; хранит адрес серсера, к которому будет отправляться запрос
    httplib::Client cli("https://wttr.in");


    // отправка запроса на сервер, указывается эндпоинт - адрес обработчика и параметры при необходимости
    httplib::Result res = cli.Get("/Chita_Ru?format=3");

    // проверка ошибки библиотеки httplib
    cout << "httplib error code: " << res.error() << "\n";

    // Если запрос выполнен успешно
    if ( res.error() == httplib::Error::Success){
        cout << "Request answer:\nstatus: " << res->status << "\n";         // HTTP код (int)
        cout << "Body: " << res->body << "\n\n";                            // Тело ответа (string)
    }



}