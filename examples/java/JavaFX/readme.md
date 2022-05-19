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
**Получить stage из котроллёра окна.**

Stage -- это окно (построен на основе javafx.stage.Window)


```Java
обращение через любой экземпляр класса, представляющего элемент интерфейса

 
 
 public class Controller {
    @FXML
    public Label label_status;
    
    @FXML
    protected void onButtonClick(){
    
      Stage window = (Stage)label_status.getScene().getWindow();
      
      }
}
```
