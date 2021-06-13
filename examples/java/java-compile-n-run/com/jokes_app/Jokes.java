package com.jokes_app;

import java.nio.file.Files;                 // nio -- новая, рекомендованная, библиотека для работы с файлами
import java.nio.file.Paths;                 // в Java большиснтво классов вместо строкового имени файла принимают обхект типа Path
import java.lang.Exception;
import java.util.Random;
import java.util.List;

/*
Класс, который выдаёт случайные шутки
*/

public class Jokes{
    
    private List<String> jokes;             

    public Jokes(String filename)           // загружает шутки из файла. одна строка файла = одна шутка
    {   
        try{
            jokes = Files.readAllLines( 
                Paths.get(filename)         // преобразование строкового имени файла в объект типа Path
                );
        } catch (Exception e){
            e.printStackTrace();
        }

    }

    public String next(){
        Random random = new Random();
        Integer i = random.nextInt(jokes.size());
        return jokes.get( i );
    }
}