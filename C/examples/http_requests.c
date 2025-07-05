/**
 * @brief Пример отправки HTTP запроса
 * @date 2025-07-05
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
// Установка в debian:
// apt install libcurl4-openssl-dev
// См. аналогичную команду для WSL (Windows) 


/**
 * @brief колбэк-функция для накопления ответа во время получения данных по сети
 * 
 * @param data   - указатель на массив получаемых данных
 * @param size 
 * @param nmemb 
 * @param userp - указатель на массив, куда будут записывать данные
 * @return size_t 
 */
static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp) {
    size_t total = size * nmemb;
    strncat(userp, data, total);  // конкатенация новых полученных данных (data) со старыми userp
    return total;
}



int main(void) {
    // Инициализация переменной, для параметров http запросов
    CURL *curl = curl_easy_init();

    if (!curl) {    
        fprintf(stderr, "Ошибка инициализации libcurl\n");
        return 1;
    }


    char response[1024*1024] = {0};  // буфер ответа; на всякий случай большого объёма

    // Настроика http запроса (запись параметров в переменную curl_easy_setopt):
    // curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");                         // Задание адреса запроса
    curl_easy_setopt(curl, CURLOPT_URL, "https://wttr.in/Chita_RU?format=2");       // См. подробности про сайт wttr.in: https://github.com/chubin/wttr.in
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);          // Здание функции, которая будет получать и записывать в массив данные
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);                    // Задание переменной, для сохранения ответа

    // Выполнение запроса
    CURLcode res = curl_easy_perform(curl);     
    if (res != CURLE_OK) fprintf(stderr, "Ошибка запроса: %s\n", curl_easy_strerror(res));
    else printf("Ответ сервера:\n%s\n", response);

    curl_easy_cleanup(curl);

    return 0;
}


/*

Компиляция
clang -o lab lab.c -lcurl 
-lcurl -- подключить библиотеку curl\

*/