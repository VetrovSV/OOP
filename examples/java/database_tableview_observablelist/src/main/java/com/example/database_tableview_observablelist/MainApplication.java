package com.example.database_tableview_observablelist;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class MainApplication extends Application {
    @Override

    public void init() throws Exception {
        // запускается первым
        // инициализация (крое интерфейса)
    }

    @Override
    public void start(Stage stage) throws IOException {
        // запускается после init
//        FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("main_window.fxml"));
//        Scene scene = new Scene(fxmlLoader.load(), 600, 300);
//        stage.setTitle("DataBase Example!");
//        stage.setScene(scene);
//        stage.show();

        // Загрузка файла Main.fxml, описывающего окно
        // main_window.fxml может находиться в папке resources, а не java.
        // но имя пакета должно быть такое же, как и у текущего класса
        Parent root = FXMLLoader.load(getClass().getResource("main_window.fxml"));
        // root - корневой элемент UI, содержащий все остальные элементы UI

        // Создание сцены для всех элементов интерфейса
        Scene scene = new Scene(root);
        // Создание окна, добавление в него 
        stage.setScene(scene);
        stage.setTitle("Hello JavaFX");
        stage.setWidth(500);
        stage.setHeight(400);
        stage.show();
    }

    @Override
    public void stop() throws Exception {
        // запускается после закрытия окна
    }

    public static void main(String[] args) {
        // создаёт экземпляр Application
        // далее запускает: init, start
        launch();
    }
}