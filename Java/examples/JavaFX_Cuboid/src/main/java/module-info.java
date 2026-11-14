module zabgu.javafx_cuboid {
    requires javafx.controls;
    requires javafx.fxml;


    opens zabgu.javafx_cuboid to javafx.fxml;
    exports zabgu.javafx_cuboid;
}