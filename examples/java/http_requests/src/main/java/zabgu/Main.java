package zabgu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;
import java.util.stream.Collectors;
import java.io.OutputStream;
import java.io.InputStream;

public class Main {

    /// Пример HTTP запроса,
    /// получает текст главной страницы сайта http://icanhazip.com/.
    /// Сайт на главной странице показывает IP адрес устройства, с которого к нему обратились.
    /// Возвращает текст ответа сервера
    public static String simple_request() throws URISyntaxException, IOException, InterruptedException {
        // Создаём HTTP клиент - объект, который будет выполнять веб-запросы
        HttpClient client = HttpClient.newHttpClient();

        // Формирование запроса:
        // Создание экземпляра HttpRequest.Builder, в конце он будет создать объекты типа HttpRequest
        HttpRequest request = HttpRequest.newBuilder()
                // далее идёт цепочка вызова методов:
                .uri(new URI("http://icanhazip.com/"))      // -> Builder, в котором задан адрес
                .GET()                                          // -> Builder, в котором задан вид запроса (GET запрос)
                .build();                                       // -> HttpRequest
        // Для HttpRequest нет удобного конструктора, через который можно было бы задать основные параметры запроса
        // URI - Uniform Resource Identifier - специальный класс, который может хранить URL, адреса электронной почты, имена файлов и т.п.

        // Отправка запроса и получение ответа
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
        // HttpResponse.BodyHandlers.ofString() - создаёт специальный объект, который преобразует результат запроса в String
        // todo: сделать обработку исключения, когда адрес недоступен или ответ не получен

        // Вывод статуса и тела ответа
        System.out.println("Response Code: " + response.statusCode()); // Код ответа
        return "Response Body: " + response.body();
    }
    // документация по https://download.java.net/java/early_access/loom/docs/api/java.net.http/java/net/http/HttpRequest.Builder.html





    /// Пример HTTP запроса к серверу c LLM,
    public static void simple_request_to_llm() throws IOException, URISyntaxException, InterruptedException {
        // 1. Получение списка доступных моделей (для примера)
        // По этому запросу сервер Ollama вернёт список доступных LLM
        // см. короткую шпаргалку по Ollama: https://github.com/ivtipm/ML/blob/main/tools.md#ollama
        HttpRequest request = HttpRequest.newBuilder().uri(new URI("http://localhost:11434/api/tags")).GET().build();
        // Создаём HTTP клиент - объект, который будет выполнять веб-запросы
        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

        // Метаинформация ответа (response)
        System.out.println("Connection Response Code : "+response.statusCode());  // Текстовый статус
        System.out.println( "available models: " + response.body());


        //2. Отправка запроса к LLM
        String urlString = "http://localhost:11434/api/generate";                                               // Адрес для отправки запроса
        String jsonPayload = "{\"model\": \"llama3.2:1b\", \"prompt\": \"Who are you?\", \"stream\": false}";   // Данные запроса
        request = HttpRequest.newBuilder().uri(new URI(urlString)).
                header("Content-Type", "application/json").POST(HttpRequest.BodyPublishers.ofString(jsonPayload, StandardCharsets.UTF_8))
                .build();
        response = client.send( request, HttpResponse.BodyHandlers.ofString() );
        System.out.println("Response Code: " + response.statusCode());
        System.out.println("Response: " + response.body());
        // todo: можно использовать сторонние библиотеки для работы с ответом в JSON

    }

    public static void main(String[] args) throws IOException, URISyntaxException, InterruptedException {
        System.out.println( "Request result: " + simple_request() );
//        simple_request_to_llm();

    }
}