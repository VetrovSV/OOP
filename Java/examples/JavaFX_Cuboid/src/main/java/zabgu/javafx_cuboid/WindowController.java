package zabgu.javafx_cuboid;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class WindowController {
    @FXML
    private Label LabelS;

    @FXML
    private TextField TextFieldWidth;

    private Cuboid cuboid = new Cuboid(1,2,3);

//
//    private void initialize(){
//        cuboid = new Cuboid();
//    }

    @FXML
    protected void onButtonCalcClick() {

        String ws = TextFieldWidth.getText();

        double w = Double.parseDouble( ws );

        cuboid.setWidth( w );

        double S = cuboid.surfaceArea();
        LabelS.setText( String.format("%.2f", S) );


    }
}
