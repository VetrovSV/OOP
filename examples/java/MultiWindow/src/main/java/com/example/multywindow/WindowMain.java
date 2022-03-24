package com.example.multywindow;
// Контроллер второго (основного) окна программы

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class WindowMain {

    // Будет хранить данные из первого окна (WindowLogin)
    private String login;

    @FXML
    private Label welcomeText;

    @FXML
    protected void onHelloButtonClick() {
        welcomeText.setText("login: " + login);
    }

    // Будет вызван первым окном для передачи данных в экземпляр этого класса
    public void setLogin(String login) {
        this.login = login;
    }
}