package sample;

import javafx.event.ActionEvent;
import javafx.scene.control.Label;

public class Controller {


    public Label label_main;

    public void on_button_main_click(ActionEvent actionEvent) {
        label_main.setText("Hello World!");
    }
}
