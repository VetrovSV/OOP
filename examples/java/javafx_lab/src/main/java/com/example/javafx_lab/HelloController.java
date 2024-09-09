package com.example.javafx_lab;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.File;

public class HelloController {
    @FXML
    public Label label_status;

    @FXML
    protected void onHelloButtonClick() {

        // получить Stage (окно)
        Stage window = (Stage)label_status.getScene().getWindow();


        FileChooser dialog = new FileChooser();
        File f = dialog.showSaveDialog(window);

        if (f != null)
            label_status.setText(f.getPath());

//        window.hide();
    }
}