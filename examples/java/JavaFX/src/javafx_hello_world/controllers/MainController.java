package javafx_hello_world.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx_hello_world.MyRndNumber;

// Класс с обработчиками событий
// этот класс - контроллер в программе
// его имя (вместе с именем пакета javafx_hello_world)  указывается в FXML файле
public class MainController {
    public Button button_rnd;               // элемент с формы. его имя должно быть указано в свойстве fx:id в fxml файле
    private MyRndNumber rnd_number_gen;     // модель -- класс отвечающий за логику работы программы

    // этот метод вызывается после конструктора, после создания окна
    // поэтому он может обращаться к содержимому окна
    @FXML
    public void initialize(){
        rnd_number_gen = new MyRndNumber();     // создание объектов только динамически
        button_rnd.setText("Нажми!");
    }

    // имя обработчика события тоже должно быть указано в fxml файле
    public void onBtnClicked(MouseEvent mouseEvent) {
        button_rnd.setText( new Integer( rnd_number_gen.get_number() ).toString() );
    }
}
