# Интернет запросы. HTTPUrlConnection, URL

Слайды: https://docs.google.com/presentation/d/1FQS3mWwBZH51XhMIbG9GXkQp9BSU4G4gqIL4fShUS44/edit?slide=id.g342d133403a_0_211#slide=id.g342d133403a_0_211


### Пример простого запроса к сайту http://icanhazip.com/.
Этот сайт выдаёт в виде простого текста внешний IP устройства, с которого на него зашли.



#### Пример запроса с помощью класса HttpURLConnection
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



Пример вывода программы:
```text
Connection Response Message : OK
Connection Response Code :    200
Connection Response Body :    8.8.8.8
```

При необходимости можно настроить время ожидания соединения и получения данных - таймауты:
```java
con.setConnectTimeout(5000);
con.setReadTimeout(5000);
// время задаётся в миллисекундах
```

См. также пример GET и POST запросов с помощью классов java.net.http.{HttpClient,HttpRequest,HttpResponse} (и без явного использования потоков) папке http_requests

#### Пример запроса через класс HttpRequest
```java
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class SimpleGetExample {
    public static void main(String[] args) throws Exception {
        HttpClient client = HttpClient.newHttpClient();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://official-joke-api.appspot.com/random_joke"))
                .GET()
                .build();

        HttpResponse<String> response =
                client.send(request, HttpResponse.BodyHandlers.ofString());

        System.out.println("Status: " + response.statusCode());
        System.out.println("Body: " + response.body());
    }
}
```

### Пример запроса к LLM, запущенной на локальном сервере Ollama:

```java
HttpClient client = HttpClient.newHttpClient();

// неудобный способ записи JSON строки
String json = "{"
        + "\"model\": \"lakomoor/vikhr-llama-3.2-1b-instruct:q6_k\","
        + "\"prompt\": \"Почему небо синее?\","
        + "\"stream\": false"
        + "}";

// удобный способ записи JSON строки        
String json = """
        {
          "model": "llama3",
          "prompt": "Объясни, что такое HTTP простыми словами",
          "stream": false
        }
        """;

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


### Пример обращения к Mistral
```java
import java.net.URI;
import java.net.http.*;

public class MistralExample {
    public static void main(String[] args) throws Exception {
        String apiKey = "YOUR_API_KEY";

        String json = """
        {
          "model": "mistral-small",
          "messages": [
            {"role": "user", "content": "Что такое REST API?"}
          ]
        }
        """;

        HttpClient client = HttpClient.newHttpClient();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.mistral.ai/v1/chat/completions"))
                .header("Content-Type", "application/json")
                .header("Authorization", "Bearer " + apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(json))
                .build();

        HttpResponse<String> response =
                client.send(request, HttpResponse.BodyHandlers.ofString());

        System.out.println(response.body());
    }
}

```



### Простой разбор JSON
```java
String json = response.body();

// очень грубо (для обучения!)
int index = json.indexOf("temperature");
String part = json.substring(index, index + 30);

System.out.println(part);
```


### Разбор JSON через пакет Jackson
Пакет Jackson не входит в стандартную библиотеку. Но сборщик (например maven) автоматически его скачает, если указать название пакета в файле проекта (pom.xml для maven проекта). 

Добавить в раздел звисимостей 
```xml
<dependency>
  <groupId>com.fasterxml.jackson.core</groupId>
  <artifactId>jackson-databind</artifactId>
  <version>2.17.0</version>
</dependency>
```


Класс, в объект которого нужно преобразовать JSON строку
```java
class WeatherResponse {
    public CurrentWeather current_weather;

    static class CurrentWeather {
        public double temperature;
        public double windspeed;
    }
}
```

Преобразование JSON в объект
```java
import com.fasterxml.jackson.databind.ObjectMapper;

ObjectMapper mapper = new ObjectMapper();

WeatherResponse data =
    mapper.readValue(response.body(), WeatherResponse.class);

System.out.println("Temp: " + data.current_weather.temperature);
```


### Скачивание бинарного файла
```java
String image_url = "https://apod.nasa.gov/apod/image/2403/FullPlantonMoon_Horalek_1022.jpg";
String destination_file = "FullPlantonMoon_Horalek_1022.jpg";

try (
    InputStream in = new URL(image_url).openStream();          // объект для чтения входного потока из URL
    OutputStream out = new FileOutputStream(destination_file)   // объект для записи данных в файл
        )     
        {
            // Буфер для получения данных
            byte[] buffer = new byte[1024];
            int length;

            while ((    length = in.read(buffer)) != -1 ) {
                out.write(buffer, 0, length);
            }

            System.out.println("Изображение успешно скачано!");

        } catch (IOException e) {
        }
```

Для объектов внутри круглых скобок try будет автоматически вызван метод закрытия соединения и файла, если возникнет исключение (см. try-with-resources) 

### Ссылки
https://www.baeldung.com/httpurlconnection-post
