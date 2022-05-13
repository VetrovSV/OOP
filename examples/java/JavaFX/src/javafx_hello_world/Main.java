package javafx_hello_world;


// 1.Создание проекта в intelij IDEA: File > New > Project: Шаблон JavFX
// Для компиляции и запуска нужен фреимворк JavaFX. Он не входит в стандартную библиотеку Java. Нужно скачать отдельно.
// 2.Скачать JavaFX SDK: https://gluonhq.com/products/javafx/. Разархивировать. Например, в папку проекта.
// 3. Указать путь к JavaFX SDK в настройках проекта: File > Project Structure > Libraries: "+", указать путь к папке lib JavaFX
// Теперь проект компилируется. Но не запустится, т.к. код JavaFX не включится в исполняемый файл.
// Нужно отдельно указать параметры запуска программы -- параметры виртуальной машины Java, при запуске этого Java приложения
// 4. Run > Edit configurations: в поле VM Options записать: --module-path "путь к JavaFX SDK" --add-modules javafx.controls,javafx.fxml
// Если поля VM Options в окне Edit configurations нет, то его можно показать: Modify Options > Add VM options
// Теперь программу можно запускать


// Ссылки:
// https://www.jetbrains.com/help/idea/javafx.html -- аналогичная инструкция на сайте JetBrains

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx_hello_world.tests.*;

public class Main extends Application {

    /** Создание главного окна приложения */
    @Override
    public void start(Stage primaryStage) throws Exception{
        // Stage -- JavaFX контейнер верхнего уровня, построен на основе javafx.stage.Window
        // Может содержать в себе несколько экземпляров Scene.
        // Scene -- контейнер для элементов UI, составляющих сцену.
        // Отдельные элементы сцены называют узлами (nodes). Кнопка, лейбл и т.п. -- узлы
        // Узлы могут содержать в себе другие узлы
        // +----- Stage -----+
        // |                 |
        // |  +-- Scene --+  |
        // |  | root node |  |
        // |  +-----------+  |
        // |                 |
        // +-----------------+

        // Создание корневого элемента сцены по его описанию из fxml файла
        Parent root = FXMLLoader.load(getClass().getResource("resources/sample.fxml"));
        
        Scene scene = new Scene(root, 600, 450);
        scene.getStylesheets().add(getClass().getResource("resources/style.css").toExternalForm());

        primaryStage.setTitle("Hello World");
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public static void main(String[] args) {

        // запуск главного цикла приложения
        // launc запускает методы init(), start() класса Application
        launch(args);
    }
}


