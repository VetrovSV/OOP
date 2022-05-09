# Пример совместной работы представления TableView и ObservableList
Проект создан в InteliJ IDEA по шаблону JavaFX приложения

В основе приложения классы из JavaFX:
- `TableView` - класс **отображающий** таблицу на форме; не хранит данные; [doc](https://javadoc.io/static/org.openjfx/javafx-base/18-ea+1/javafx.controls/javafx/scene/control/TableView.html)
- `ObservableList` - интерфейс-контейнер, шаблонный список, который может хранить данные и оповещать об их изменениях; [doc](https://javadoc.io/static/org.openjfx/javafx-fxml/17-ea+2/javafx.base/javafx/collections/ObservableList.html); [FXCollections](https://javadoc.io/static/org.openjfx/javafx-fxml/17-ea+2/javafx.base/javafx/collections/package-summary.html)

```java
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.cell.PropertyValueFactory;

// В классе с обработчиками событий главного окна
private TableView<Student> table;            /** представление данных: будет показывать данные из ObservableList; */

// Будут отображать отдельные поля класса Student в ячейки соответствующих строк
// <Student, String> - из какого класса брать данные, в каком типе представлять в TableView
// см. связывание метода из Student и колонки, добавление колонки в таблицу ниже
private TableColumn<Student, String> col_name = new TableColumn<>("Name");


// ==== Инициализация таблицы
// связывает колонку и метод из Student, с помощью которого колонка будет получать значения для каждой ячейки данных
// аргумента PropertyValueFactory должен быь таким, чтобы получить име геттера и сеттера добавив get и set соответственно
col_name.setCellValueFactory(new PropertyValueFactory<>("Name"));

// добавление колонок в таблицу
table.getColumns().add( col_name );


// связывание таблицы и модели данных
table.setItems( db.getList_studs() );
```


Класс, хранящий данные об одной строке таблицы
```Java
public class Student {
    
    private String name;

    /** ФИО */

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    ...
}
```


