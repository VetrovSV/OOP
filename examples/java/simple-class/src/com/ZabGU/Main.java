package com.ZabGU;      // имя пакета определяет пространство имён
                        // имя пакета = структура каталогов

// подключение пакетов
import com.ZabGU.simple_class.Seconds;
import com.ZabGU.student.     Student;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.*;         // * подключить всё содержимое модуля java.util
// без * придётся писать полные имена классов. Например java.util.ArrayList

// можно подключить только конкретный класс из модуля:
// import java.util.ArrayList;

import org.junit.jupiter.api.*;

import java.util.Random;
import java.util.stream.Collectors;


public class Main {

    public static void getRequest() throws IOException {

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

//        Map<String, String> params = Collections.emptyMap();
//        StringBuilder result = new StringBuilder();
//
//        for (Map.Entry<String, String> entry : params.entrySet()) {
//            result.append(URLEncoder.encode(entry.getKey(), "UTF-8"));
//            result.append("=");
//            result.append(URLEncoder.encode(entry.getValue(), "UTF-8"));
//            result.append("&");
//        }

//        String resultString = result.toString();
//        System.out.println(resultString);
    }

    public static void main(String[] args) {

        try {
            getRequest();
        } catch (IOException e) {
            e.printStackTrace();
        }

//        System.out.println("Hello World!");
//
//        Seconds s = new Seconds();  // создание объектов только через оператор new
//        s.setS(55);
//
//        Seconds s1 = new Seconds(20);
//
//        s.tick();
//        System.out.println("s: " + s.toString());
//
//        s1.add(59);
//        System.out.println("s1: " + s1.toString());
//
//        Seconds s2 = s1.add( s );
//
//        System.out.println("s2: " + s2.toString());
//
//
//        // В Java почти для всего используются классы, не функции
//        Random rand = new Random();
//
//        Integer N = 200;
//        Seconds[] arr = new Seconds[N];     // массивы создаются тоже динамически
//        // т.к. в Java все классы ссылочные типы (переменные хранят ссылки на объекты),
//        // то массив arr -- массив их ссылок на объекты
//
//        // можно ещё объявлять массивы как в C++, но лучше использовать стиль Джавы - как в примере выше
////        Seconds arr2[] = new Seconds[N];
//
//        for (int i = 0; i<N; i++){
//            arr[i] = new Seconds( rand.nextInt( 60) );
//        }
//
//        // Создадим список
//        ArrayList list = new ArrayList< Seconds >();
//
//        list.add( new Seconds(rand.nextInt(60) ));      // nextInt выдаст случайное число от 0 до 59
//        list.add( new Seconds(rand.nextInt(60) ));
//        list.add( new Seconds(rand.nextInt(60) ));
//        list.add( new Seconds(rand.nextInt(60) ));
//        list.add( new Seconds(rand.nextInt(60) ));
//
//        System.out.println("ArrayList of Seconds: ");
//
//        for (Object si: list ) {
//            System.out.print( si.toString() + " " );
//        }
    }
}
