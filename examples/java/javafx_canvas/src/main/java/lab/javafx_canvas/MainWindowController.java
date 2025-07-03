package lab.javafx_canvas;

// Используется для сохранения в файл
import javafx.embed.swing.SwingFXUtils;
/* 1. Нужно добавить дополнительную стороннюю библиотеку в файл проекта pom.xml
        <dependency>
            <groupId>org.openjfx</groupId>
            <artifactId>javafx-swing</artifactId>
            <version>17.0.6</version>
        </dependency>
    2. Добавить requires javafx.swing; в module-info.java
 */

import javafx.event.ActionEvent;
import javafx.scene.SnapshotParameters;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.WritableImage;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;


import javax.imageio.ImageIO;
import java.awt.image.RenderedImage;
import java.io.File;
import java.io.IOException;

import static javafx.scene.paint.Color.hsb;

public class MainWindowController {

    // Компонент для рисования на нём (см. раздел Miscellaneous в Scene Builder);
    // Canvas = полотно\холст для рисования
    public Canvas canvas;
    // Документация по Canvas:
    // https://openjfx.io/javadoc/20/javafx.graphics/javafx/scene/canvas/Canvas.html

    // Обработчик снажатия на кнопку
    public void onDrawButtonClick(ActionEvent actionEvent) {
        // 1. Экранные координаты (Canvas):
        // Начало координат в левом верхнем углу
        // Ось X направлена вправо
        // Ось Y направлена вниз

        // Объект (переменная) для рисования
        GraphicsContext gc;
        gc = canvas.getGraphicsContext2D();
        // Документация: https://openjfx.io/javadoc/20/javafx.graphics/javafx/scene/canvas/GraphicsContext.html

        // Задать цвет заливки для фигуры
        // gc.setFill(Color.WHITESMOKE);    // Через константу
        // gc.setFill( rgb(128, 0, 64) );   // Через функцию, создающую значение типа Color на основе RGB
        gc.setFill( hsb(0.7, 0.01, 1) );    // Через функцию, создающую значение типа Color на основе Hue-Saturation-Brightness

        // Очистка холста через рисование прямоугольника во весь холст
        // Нарисовать прямоугольник. Задаются с координаты левого верхнего угла
        gc.fillRect(0, 0, canvas.getWidth(), canvas.getHeight() );          // fillRect - прямоугольник с заливкой

        // Линия
        gc.setStroke(Color.BLUE);                   // Задать цвет линий
        gc.setLineWidth(3);                         // Задать толщину линий
        gc.strokeLine(50, 30, 200, 30);

        // Для точки нет отдельной функции, можно рисовать линию, или другую фигуры минимально возможного размера
        gc.setStroke(Color.BLACK);
        gc.strokeLine(350, 350, 350.5, 350.5);

        // Прямоугольники
        gc.setFill(Color.LIGHTGREEN);
        gc.fillRect(20, 40, 100, 60);
        gc.setStroke(Color.DARKGREEN);
        gc.strokeRect(150, 40, 100, 60);

        // Круг (элипс с равными сторонами)
        gc.setFill(Color.RED);
        gc.fillOval(20, 120, 80, 80);       // 20, 120 - (x,y); 80, 80 - ширина и высота
        gc.setStroke(Color.DARKRED);
        gc.setLineWidth(3);
        gc.strokeOval(120, 120, 80, 80);

        // Закруглённый прямоугольник
        gc.setFill(Color.ORANGE);
        gc.fillRoundRect(220, 120, 100, 60, 15, 15);
        gc.setStroke(Color.BROWN);
        gc.strokeRoundRect(220, 120, 100, 60, 15, 15);
        // последние два параметра - ширина и высота эллипса, который является частью скругления

        // Дуга
        gc.setFill(Color.PURPLE);
        // параметры fillArc: x, y
        // w, h – ширина и высота этого прямоугольника. Этим задаётся форма эллипса (круг, если w = h).
        //  arcExtent — насколько градусов растянуть дугу от startAngle. Положительное значение – против часовой, отрицательное – по часовой стрелке.
//        OPEN – рисуется только сама кривая, без треугольников или линий к центру.
//        CHORD – хорда
//        ROUND – закрашиваемая «вееровидная» фигура/ от концов дуги проводятся к центру эллипса/

        gc.fillArc(20, 220, 80, 80, 45, 270, ArcType.ROUND);
        gc.setStroke(Color.MAGENTA);
        gc.strokeArc(120, 220, 80, 80, 0, 180, ArcType.OPEN);

        // Многоугольник
        double[] xPoly = {220, 260, 300, 240};
        double[] yPoly = {220, 260, 220, 260};
        gc.setFill(Color.CADETBLUE);
        gc.fillPolygon(xPoly, yPoly, xPoly.length);

        // Ломаная
        double[] xLine = {320, 360, 400};
        double[] yLine = {220, 260, 220};
        gc.setStroke(Color.SLATEBLUE);
        gc.strokePolyline(xLine, yLine, xLine.length);

        // Текст
        gc.setFont(Font.font("Arial", FontWeight.BOLD, 24));
        gc.setFill(Color.BLACK);
        gc.fillText("Простой текст", 50, 350);           // заполняемый текст
        gc.strokeText("Дизайн!!11", 50, 380);         // контур текста


        // Сохранение в файл (требует доп. библиотек, см. раздел подключения)
        // 1. Создаём WritableImage нужного размера
        WritableImage wi = new WritableImage((int)canvas.getWidth(), (int)canvas.getHeight());
        // 2. Скриншот содержимого Canvas
        canvas.snapshot(new SnapshotParameters(), wi);
        // 3. Конвертируем в BufferedImage - промежуточный формат, удобный для сохранения
        RenderedImage ri = SwingFXUtils.fromFXImage(wi, null);
        // 4. Записываем в файл PNG
        File file = new File("canvas.png");
        try {
            ImageIO.write(ri, "png", file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void draw_pixel(MouseEvent mouseEvent) {
        GraphicsContext gc;
        gc = canvas.getGraphicsContext2D();

        gc.setStroke(Color.BLACK);
        gc.strokeLine(mouseEvent.getX(), mouseEvent.getY(),mouseEvent.getX()+0.5, mouseEvent.getY()+0.5);
    }
}


// todo: 3D