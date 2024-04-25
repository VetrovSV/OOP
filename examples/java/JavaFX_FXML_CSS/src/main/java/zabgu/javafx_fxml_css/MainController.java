package zabgu.javafx_fxml_css;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

// Контролер главного окна
public class MainController {

    //  для вывода результата вычисления
    public Label LabelPi;
    // задаёт количество точек, бросаемых для вычисления числа Пи
    public TextField Edit_n;

    @FXML
    protected void onCalcButtonClick() {
        int n = Integer.valueOf( Edit_n.getText() );
        LabelPi.setText( String.format("%.5f", PiCalculator.calc_pi(n) ) );

    }
}