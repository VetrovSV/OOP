# Пример JavaFX приложения.

1. Создание проекта в intelij IDEA: File > New > Project: Шаблон JavFX\
  Для компиляции и запуска нужен фреимворк JavaFX. Он не входит в стандартную библиотеку Java. Нужно скачать отдельно.
2. Скачать JavaFX SDK: https://gluonhq.com/products/javafx/. Разархивировать. Например, в папку проекта.
3. Указать путь к JavaFX SDK в настройках проекта: File > Project Structure > Libraries: "+", указать путь к папке lib JavaFX \
  Теперь проект компилируется. Но не запустится, т.к. код JavaFX не включится в исполняемый файл. \
  Нужно отдельно указать параметры запуска программы -- параметры виртуальной машины Java, при запуске этого Java приложения
4. Run > Edit configurations: в поле VM Options записать: `--module-path "путь к JavaFX SDK" --add-modules javafx.controls,javafx.fxml` \
  Если поля VM Options в окне Edit configurations нет, то его можно показать: Modify Options > Add VM options \
  Теперь программу можно запускать


# Ссылки
https://www.jetbrains.com/help/idea/javafx.html -- аналогичная инструкция на сайте JetBrains


# ***
#### Аннотация `@FXML` перед полями котроллера

[SO](https://stackoverflow.com/questions/30210170/is-fxml-needed-for-every-declaration)
 
```Java
 public class MainWindowController {
    
    @FXML
    public Label label_status;
    
    // соответствующий fxml файл:
      // Корневой элемент окна содержит название класса- контроллера
      // <VBox alignment="CENTER" ...  fx:controller="com.example.my_javafx_program.MainWindowController">
      // ...
      // <Label fx:id="label_status"/>
    
}
```
В классе MainWindowController объект label_status не создаётся (нет оператора new) и не инициализируется. 
Аннотация @FXML заставляет экземпляр загрузчика fxlm файлов (FXMLLoader) создать объект и инициализировать его в методе load().
```java
  FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
  Scene scene = new Scene(fxmlLoader.load(), 320, 240);
```



#### Получить stage из контроллера окна

Stage -- это окно (построен на основе javafx.stage.Window)


```Java
обращение через любой экземпляр класса, представляющего элемент интерфейса

 
 
 public class Controller {
    @FXML
    public Label label_status;
    
    @FXML
    protected void onButtonClick(){
    
      Stage window = (Stage) label_status.getScene().getWindow();
      
      }
}
```


#### Диалог выбора имени файла для открытия или сохранения
```java
  // получить Stage (окно) через любой экземпляр класса, представляющего элемент интерфеса
  Stage window = (Stage)label_status.getScene().getWindow();
  
  FileChooser dialog = new FileChooser();
  
  // Диалог выбора файла для открытия
  File f = dialog.showOpenDialog(window);
  
  // Диалог выбора файла для сохранения
  File f = dialog.showSaveDialog(window);
```
