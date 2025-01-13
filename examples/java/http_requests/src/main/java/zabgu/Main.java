package zabgu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.stream.Collectors;
import java.io.OutputStream;
import java.io.InputStream;

public class Main {

    /// Пример HTTP запроса,
    /// получает текст главной страницы сайта http://icanhazip.com/, который показывает IP адрес устройства,
    /// с которого к нему обратились
    /// Возвращает текст ответа сервера
    public static String simple_request() throws IOException {
        URL url = new URL("http://icanhazip.com/");
        // класс для отправки запросов к HTTP серверу
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        // Тип запроса - GET (см. также POST)
        con.setRequestMethod("GET");

        // Запрос к серверу, получение данных:
        // Метаинформация ответа (response)
        System.out.println("Connection Response Message : "+con.getResponseMessage());  // Текстовый статус
        System.out.println("Connection Response Code :    "+con.getResponseCode());     // Код. Если всё ОК, то должен быть 200

        // Получение тела ответа - длительная процедура. Для чтения ответа используется класс BufferedReader,
        // который умеет читать потоковые данные
        // InputStreamReader конвертирует полученные данные в набор символов
        BufferedReader br = new BufferedReader(new InputStreamReader((con.getInputStream())));

        // склеивание набора символов в строку
        String output = br.lines().collect(Collectors.joining());
        con.disconnect();

        return output;
    }


    /// Пример HTTP запроса к серверу c LLM,
    public static void simple_request_2() throws IOException {
        // 1. Получение списка доступных моделей (для примера)
        // По этому запросу сервер Ollama вернёт список доступных LLM
        // см. короткую шпаргалку по Ollama: https://github.com/ivtipm/ML/blob/main/tools.md#ollama
        URL url_llm_lst = new URL("http://localhost:11434/api/tags");
        // класс для отправки запросов к HTTP серверу
        HttpURLConnection con = (HttpURLConnection) url_llm_lst.openConnection();
        // Тип запроса - GET (см. также POST)
        con.setRequestMethod("GET");

        // Метаинформация ответа (response)
        System.out.println("Connection Response Message : "+con.getResponseMessage());  // Текстовый статус
        System.out.println("Connection Response Code :    "+con.getResponseCode());     // Код. Если всё ОК, то должен быть 200

        // Получение тела ответа - длительная процедура. Для чтения ответа используется класс BufferedReader,
        // который умеет читать потоковые данные
        // InputStreamReader конвертирует полученные данные в набор символов
        BufferedReader br = new BufferedReader(new InputStreamReader((con.getInputStream())));

        // склеивание набора символов в строку
        String output = br.lines().collect(Collectors.joining());
//        con.disconnect();

        System.out.println( "available models: " + output);


        //2. Отправка запроса к LLM
        String urlString = "http://localhost:11434/api/generate";                                               // Адрес для отправки запроса
        URL url_prompt = new URL(urlString);
        String jsonPayload = "{\"model\": \"llama3.2:1b\", \"prompt\": \"Who are you?\", \"stream\": false}";   // Данные запроса

        // Создание и настройка нового соединения
        con = (HttpURLConnection) url_prompt.openConnection();
        con.setRequestMethod("POST");
        con.setRequestProperty("Content-Type", "application/json");
        con.setDoOutput(true);
        // Добавление данных в запрос
        try (OutputStream os = con.getOutputStream()) {
            byte[] input = jsonPayload.getBytes("utf-8");
            os.write(input, 0, input.length); }

        // Получение ответа
        int responseCode = con.getResponseCode();
        System.out.println("Response Code: " + responseCode);
        System.out.println("Response: ");
        br = new BufferedReader(new InputStreamReader((con.getInputStream())));
        System.out.println( br.lines().collect(Collectors.joining()) );
        con.disconnect();
    }

    public static void main(String[] args) throws IOException {
//        System.out.println( "Request result: " + simple_request() );
        simple_request_2();

    }
}