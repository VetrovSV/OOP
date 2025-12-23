#include <iostream>

#include "httplib.h"
// библиотека только из заголовочного файла для HTTP запросов
// https://github.com/yhirose/cpp-httplib
// Требуется OpenSSL, устанвока в Убунту: sudo apt install libssl-dev
// См. также CmakeLists.txt


using namespace std;


/// Пример: GET запрос
void simple_https_get_request() {
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


/// Извлекает из JSON строки (ответ Ollama) значение поля response
/// @return: значение поля response
string extract_responce(const string& raw_json) {
    int start = raw_json.find("response")+8+3;            // начало текста ответа; длина слова response + ":"
    if (start == string::npos) return "";       // если слово response не найдено
    int end = start+1;

    // поиск завершаюшей двойной кавычки
    while ( (raw_json[end] != '"' or raw_json[end-1] == '\\') and end < raw_json.size() )
        end++;

    return raw_json.substr(start, end-start);
}


/// Пример: POST запрос к Ollama
void simple_post_request() {
    // Клиент для запроса к серверу Ollama
    httplib::Client cli("http://localhost:11434");

    // JSON строка для запроса; R - raw (сырая) строка, такую строку можно записать как многострочный литерал
    const char* json = R"(
    {
        "model": "smollm2:135m",
        "prompt": "Who is sir Tim Berners-Lee?",
        "stream": false
    }
    )";


    // Отправка POST запроса
    httplib::Result res = cli.Post(
        "/api/generate",
        json,
        "application/json"
    );

    if (!res) {     // у Result перегружен оператор bool, поэтому можно писать !res
        std::cerr << "Ошибка соединения с Ollama\n";
        return;
    }

    std::cout << "HTTP status: " << res->status << "\n";
    // std::cout << "Response body:\n" << res->body << "\n\n";
    std::cout << "Response body:\n" << extract_responce(res->body) << "\n";


}


int main() {
    // simple_https_get_request();
    simple_post_request();
}