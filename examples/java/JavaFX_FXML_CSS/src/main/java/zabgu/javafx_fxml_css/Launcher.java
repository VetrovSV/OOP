package zabgu.javafx_fxml_css;

import javafx.application.Application;

// Главный класс приложения. Необходим для запуска приложения из JAR файла
// В остальных случаях, можно пользоваться классом MainApplication
public class Launcher {

    public static void main(String[] args){

        Application.launch(MainApplication.class, args);
    }
}
