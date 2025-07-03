module lab.javafx_canvas {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;
    requires javafx.swing;

    opens lab.javafx_canvas to javafx.fxml;
    exports lab.javafx_canvas;
}