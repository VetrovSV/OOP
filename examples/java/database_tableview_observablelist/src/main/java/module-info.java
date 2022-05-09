module com.example.database_tableview_observablelist {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.database_tableview_observablelist to javafx.fxml;
    exports com.example.database_tableview_observablelist;
}