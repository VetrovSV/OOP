package com.example.database_sqlite;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;

import java.io.IOException;
import java.net.URL;

import java.sql.Connection;     // класс для подключения и взаимодействия с CУБД
import java.sql.DriverManager;  // класс для создания подключений
import java.sql.SQLException;
import java.sql.Statement;      // класс для выполнения SQL запросов
import java.sql.ResultSet;      // класс для хранения результатов запроса

import java.util.ResourceBundle;

// java.sql не подключается по умолчанию.
// в файл module-info.java (дискриптор модуля проекта) нужно добавить requires java.sql;
// см. Модули в Java


public class Controller_mainwin implements Initializable {
    @FXML
    private Label welcomeText;

    Connection db_con;

    // JDBC (Java DataBase Connectivity) -- стандарт взаимодействия с СУБД;
    // всё взаимодействие происходи через специальный драйвер. Для каждой СУБД он свой.
    // скачать JDBC драйвер (jar файл) для sqlite: https://mvnrepository.com/artifact/org.xerial/sqlite-jdbc
    // добавить драйвер в проект: Project Structure >
    //      Project Settings | Modules | вкладка Dependencies |
    //      + > As JARs > выбрать jar файл драйвера

    // строка подключения (конфигурация подключения): название_стандарта:название_драйвера:имя_sqlite_файла
    String con_str = "jdbc:sqlite:";

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        System.out.println(System.getProperty("user.dir"));

    try {
        con_str = con_str + "studs_db.sqlite";
        // текущая папка -- папка проекта

        // подключение
        db_con = DriverManager.getConnection(con_str);
        System.out.println("Connected!");

    } catch (SQLException e) {
        e.printStackTrace();
    }
    }

    @FXML
    protected void onSelectButtonClick() {
        try {
            // объект для SQL запросов
            Statement stmt = db_con.createStatement();
            // выполнение запроса
            ResultSet resultSet = stmt.executeQuery("select * from students;");
            while (resultSet.next()){
                // получение данных из полей
                System.out.print(   resultSet.getLong(1) + "; ");            // нумерация полей начинается с единицы
                System.out.print(   resultSet.getString(2) + "; " );
                System.out.print(   resultSet.getDouble(3) + "; " );
                System.out.print(   resultSet.getDouble(4) + "; " );
                System.out.print(   resultSet.getDouble(5) + "; " );
                System.out.println( resultSet.getDouble(6) );
            }
        } catch (SQLException e) {
            System.out.println( e.toString() );
            throw new RuntimeException(e);
        }
        //Execute select (query) operation



    }


    public void onCreateButtonClick(ActionEvent actionEvent) {

        try {
            Statement create = db_con.createStatement();
            create.execute("create table students  (" +
                    "id integer constraint table_name_pk primary key autoincrement " +
                    ",name       text not null" +
                    ",UML        real" +
                    ",Model      real" +
                    ",ui         real" +
                    ",Controller real);" );
            System.out.println("table created");

            Statement schema = db_con.createStatement();
            schema.

        } catch (SQLException e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }

    }
}

// Ultima