```Java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.util.stream.Collectors;
import java.net.URL;


URL url = new URL("http://icanhazip.com/");
// класс для отправки запросов к HTTP серверу
HttpURLConnection con = (HttpURLConnection) url.openConnection();
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

System.out.println("Connection Response Body :    "+output);
con.disconnect();
```

См. также пример GET и POST запросов с помощью классов java.net.http.{HttpClient,HttpRequest,HttpResponse} (и без явного использования потоков) папке http_requests


Пример запроса к LLM, запущенной на локальном сервере Ollama:

```java
HttpClient client = HttpClient.newHttpClient();

String json = "{"
        + "\"model\": \"lakomoor/vikhr-llama-3.2-1b-instruct:q6_k\","
        + "\"prompt\": \"Почему небо синее?\","
        + "\"stream\": false"
        + "}";

HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create("http://localhost:11434/api/generate"))        
        .header("Content-Type", "application/json")
        .POST(HttpRequest.BodyPublishers.ofString(json))
        .build();
// в коде выше вызывается серия методов, каждый из которых (короме build) возвращает объект типа HttpRequest.Builder, но с заданными свойствами (полями).

// HttpRequest возвращает объект типа HttpRequest


HttpResponse<String> response = client.send(
        request,
        HttpResponse.BodyHandlers.ofString()        // возвращает специальный объект, который умеет преобразовывать строку с JSON данными в формат подхходящий для тела HTTP запроса.
);
```

Два приведённых примера решают одну и ту же задачу, но показывают разные способы обращения к http-серверу. 

### Ссылки
https://www.baeldung.com/httpurlconnection-post
