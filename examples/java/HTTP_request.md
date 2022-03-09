```Java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
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

// Строки в Java неизменяемые.
// Поэтому используем StringBuilder, чтобы склеить набор символов в строку без потери производительности
StringBuilder sb = new StringBuilder();

// склеивание набора символов в строку
String output = br.lines().collect(Collectors.joining());

System.out.println("Connection Response Body :    "+output);
con.disconnect();
```
