package io.github.vetrovsv.java_gui_arifm;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;


public class MainWindowController {

    public TextField textarea_h;
    public TextField textarea_a;

    public Label label_s;

    public TextArea text_area_report;

    public void calc_button_clicked(MouseEvent mouseEvent) {

        double h = 0.0, a = 0.0;
        double S = 0.0;

        // считывание данных из полей ввода
        String h_text = textarea_h.getText();
        String a_text = textarea_a.getText();

        // Преобразование текста в числа
        h = Double.parseDouble( h_text );
        a = Double.parseDouble( a_text );

        // Вычисление площади треугольника
        S = Geometry.triangle_area(a,h);


        //
        label_s.setText( String.valueOf( S ) );


//        text_area_report.setText( );
        text_area_report.appendText( "h = " + h + "; a = " + a + "; S = " + S + "\n" );
    }
}