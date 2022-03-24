# Многооконное приложение на JavaFX
1. Создать проект по шаблону JavaFX в InteliJ Idea
2. Добавить два новых файла для окна логина
  - window_login.fxml
  - WindowLogin.java
3. В WindowLogin.java создать поле и метод, которые будут принимать данные из извне
4. В главном классе приложения (MainApplication.java) создавать окно из файла window_login.fxml
```java
FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("window_login.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 250, 250);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
```
4. Добавить в окне `window_login.fxml` кнопку с обработчиком в `WindowLogin.java`
Обратится к контроллеру второго окна `window_main.fxml`.
```java
    public void new_window() throws IOException {
        // Загрузка окна из FXML такая же, как и в методе Start главного класса (MainApplication) программы
        FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("window_main.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 450,200);
        Stage stage = new Stage();
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();

        // Обращение к классу с обработчиками второго окна
        WindowMain main_window = fxmlLoader.getController();
        main_window.setLogin( TextField_login.getText() );

        // обращение к окну (можно сделать через любой элемент интерфейса) чтобы скрыть его
        TextField_login.getScene().getWindow().hide();
    }
```
