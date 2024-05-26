package zabgu.javafx_fxml_css;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.io.IOException;
import java.io.InputStream;


// Главный класс приложения
public class MainApplication extends Application {

    @Override
    public void init(){
        // Метод, который запускается до создания окна
        // Приведён для примера
    }

    @Override
    public void start(Stage stage) throws IOException {
        // Открытие FXML файла с описанием главного окна
        FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("main-view.fxml"));
        // Создание сцены (scene) на основе FXML файла
        Scene scene = new Scene(fxmlLoader.load(), 510, 450);

        // Загрузка и применение файла стилей (для примера)
        /* String stylesheet = getClass().getResource("style.css").toExternalForm();
        scene.getStylesheets().add(stylesheet);
        */
        // Удобнее файл стилей задавать в FXML файле, в свойстве stylesheet корневого элемента:
        // <AnchorPane stylesheets="@style.css"
        // @ означает, что используется относительный (относительно fxml файла) путь к файлу

        // Задание заголовка окна (Stage)
        stage.setTitle("Hello!");
        // Помещаем сцену (элементы интерфейса из FXML файла) в окно
        stage.setScene(scene);

        // Чтение данных файла с иконкой
        InputStream iconStream =
                getClass().getResourceAsStream("pi.jpg");
        // Создание изображения на основе прочитанных данных
        Image image = new Image(iconStream);
        // Задание иконки
        stage.getIcons().add(image);


        // Отобразить окно
        stage.show();
    }


    @Override
    public void stop(){
        // Этот метод выполнится после закрытия окна, но до завершения работы приложения
        // приведён для примера
    }

    public static void main(String[] args) {
        // launch создаёт экземпляр класса MainApplication
        // Вызывает методы: init, start, stop (после закрытия окна)
        launch();
    }
}