module com.example.javafx_lab {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.javafx_lab to javafx.fxml;
    exports com.example.javafx_lab;
}