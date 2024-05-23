package com.example.database_tableview_observablelist;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;

import java.net.URL;
import java.util.ResourceBundle;

public class MainWindowController implements Initializable {
    @FXML
    private TableView<Student> table;            /** Представление данных: будет показывать данные из ObservableList; */

    // Будут отображать отдельные поля класса Student в ячейки соответствующих строк
    // <Student, String> - из какого класса брать данные, в каком типе представлять в TableView
    // см. связывание метода из Student и колонки, добавление колонки в таблицу ниже
    private TableColumn<Student, String> col_name = new TableColumn<>("ФИО");
    private TableColumn<Student, Double> col_score1 = new TableColumn<>("Task1");
    private TableColumn<Student, Double> col_score2 = new TableColumn<>("Task2");
    private TableColumn<Student, Double> col_score3 = new TableColumn<>("Task3");
    private TableColumn<Student, Byte> col_exam = new TableColumn<>("Exam");

    @FXML
    private Label welcomeText;

    /** Содержит модель данных (ObservableList) */
    private DataBase db = new DataBase();

    /** Вызывается после того как форма создана. Можно обращаться к её содержимому */
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        // связывает колонку и метод из Student, с помощью которого колонка будет получать значения для каждой ячейки данных
        // аргумента PropertyValueFactory должен быь таким, чтобы получить име геттера и сеттера добавив get и set соответственно
        col_name.setCellValueFactory(new PropertyValueFactory<>("Name"));
        col_score1.setCellValueFactory(new PropertyValueFactory<>("Score_t1"));
        col_score2.setCellValueFactory(new PropertyValueFactory<>("Score_t2"));
        col_score3.setCellValueFactory(new PropertyValueFactory<>("Score_t3"));
        col_exam.setCellValueFactory(new PropertyValueFactory<>("Exam"));

        // добавление колонок в таблицу
        table.getColumns().add( col_name );
        table.getColumns().add( col_score1 );
        table.getColumns().add( col_score2 );
        table.getColumns().add( col_score3 );
        table.getColumns().add( col_exam );

        // связывание таблицы и модели данных
        table.setItems( db.getList_studs() );
    }

    /** Добавление строки со случайным содержимым в таблицу */
    @FXML
    protected void onHelloButtonClick() {
        db.add_random_student();
    }


}