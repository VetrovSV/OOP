package com.example.database_tableview_observablelist;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.util.Random;

/** Отвечает за хранение, загрузку, сохранение данных
 **/
public class DataBase {

    private ObservableList<Student> list_studs = FXCollections.observableArrayList();
    // FXCollections.observableArrayList() -- метод, создающий экземпляр класса ObservableArrayList

    /** Добавляет случаного студента в конец списка */
    public void add_random_student(){
        Random rand = new Random();
        Student s = new Student("Ivanov" + String.valueOf(rand.nextInt()),
                                rand.nextDouble()*10, rand.nextDouble()*10, rand.nextDouble()*10,
                                (byte)( rand.nextInt()%5 ) );
        list_studs.add( s );
    }

    public void load(){
    // todo: загрузка из файла
    }

    public void save(){
    // todo: сохранение в файл
    }

    public ObservableList<Student> getList_studs() {
        return list_studs;
    }
}
