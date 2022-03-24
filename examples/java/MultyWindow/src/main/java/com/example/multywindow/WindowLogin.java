package com.example.multywindow;

// Этот файл добавлен вручную, после добавления FXML файла описания интерфейса:
// ПКМ на проекте (папка resources) > New > FXML файл
// В результате автоматически создан fxml файл

// Alt+Enter на WindowLogin (в fx:controller="com.example.multiwindow.WindowLogin") > Create class WindowLogin >
// выбрать папку с другими исходниками (java\com\example\multiwindow) для сохранения
// Но можно добавить этот файл отдельно: ПКМ на проекте (папка com/example/multywindow) > New > Java Class


import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Background;
import javafx.stage.Stage;

import java.io.IOException;



// Контроллер первого окна. Показывает новое (основное) окно window_main
public class WindowLogin {
    final String color_error = "#ffc3bf";

    public TextField TextField_login;
    public Label Label_status;

    // Создаёт и показывает новое (основное) окно программы
    // вызывается по нажатию на кнопку
    public void new_window() throws IOException {
        if ( TextField_login.getText().isEmpty() ) {
            Label_status.setText( "Ведите логин" );
            TextField_login.setStyle("-fx-control-inner-background: "+color_error);
            return;
        }

        // Загрузка окна из FXML такая же, как и в методе Start главного класса (MainApplication) программы
        FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("window_main.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 450,200);
        Stage stage = new Stage();
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();

        // Обращение к классу с обработчиками
        WindowMain main_window = fxmlLoader.getController();
        main_window.setLogin( TextField_login.getText() );

        // обращение к окну (можно сделать через любой элемент интерфейса) чтобы скрыть его
        TextField_login.getScene().getWindow().hide();
    }

    // Обработчик события TextFiled - нажатие на кнопку
    // должен быть указан в fxml файле
    public void onTextField_login_key_pressed(KeyEvent keyEvent) throws IOException {
        if (keyEvent.getCode().equals(KeyCode.ENTER)){
            new_window();
        }
    }
}
