module com.example.multiwindow {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.example.multywindow to javafx.fxml;
    exports com.example.multywindow;
}