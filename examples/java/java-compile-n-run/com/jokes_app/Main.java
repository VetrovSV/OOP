package com.jokes_app;

import java.io.Console;
// import Jokes; -- подключать классы, находящиеся в том же пакете (папке) не нужно

public class Main {
    public static void main(String[] args) {

        Console console = System.console();             // объект для считывания данных с клавиатуры
        System.out.println("Нажмите q для выхода");

        Jokes jokes = new Jokes("jokes.txt");

        while (true){
            System.out.println( jokes.next() );

            String s = console.readLine("");

            if ( s.toLowerCase().equals("q") ) {
                break;
            }

        }
    }
    }