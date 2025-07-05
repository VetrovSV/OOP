module io.github.vetrovsv.java_gui_arifm {
    requires javafx.controls;
    requires javafx.fxml;


    opens io.github.vetrovsv.java_gui_arifm to javafx.fxml;
    exports io.github.vetrovsv.java_gui_arifm;
}