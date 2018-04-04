#include <math.h>
#include "widget.h"


GraphicWidget::GraphicWidget(QWidget *parent) :
    QGraphicsView(parent){

    scene.setSceneRect(0,0, width(), height());

    this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    // Задаём поверхность (сцену, 2D мир) который будет нарисаван QGraphicsView
    this->setScene(&scene);

    scene.addRect(0,0, scene.width(), scene.height(), QPen(Qt::black));

    // Добавляем Прямоугольник на сцену
    my_item = scene.addRect(this->width()/2 - item_size/2, this->height()/2 - item_size/2, item_size,
                            item_size, QPen(), QBrush(QColor(Qt::red)));

    // Добавляем Круг на сцену
    other_item = scene.addEllipse( this->width()/3 - item_size/2, this->height()/3 - item_size/2,
                                   item_size/2,item_size/2,
                                   QPen(), QBrush(QColor(Qt::green)));

    // v отвечает за скорость перемещения круга
    v = QVector2D(3,3);

    // Таймер при срабатывании будет вызывать изменениие объектов на сцене
    timer = new QTimer(this);

    // "Соединяет" метод timeout вызываемый при срабатывании таймера
    // с методом изменения объектов на сцене
    QObject::connect(timer, &QTimer::timeout,
                     this, &GraphicWidget::update);

    //Таймер будес срабатывать один раз в 1000/30 = 33 милисикунды
    timer->start(1000/30);
}



// Изменение объектов на сцене
void GraphicWidget::update(){

    // Проверка: не вышел ли круг за пределе области (80х80)
    // если вышел, то изменяем знак у вектора скорости
    if (other_item->pos().x() > 200 ||  other_item->pos().y() > 200)
        v = -QVector2D(abs(v.x()),  abs(v.y()));

    if (other_item->pos().x() < 10  ||  other_item->pos().y() < 10)
        v = QVector2D(abs(v.x()),  abs(v.y()));

    // изменяем координаты круга
    this->other_item->setPos( other_item->pos() + v.toPointF());
}


// Переопределённый обработчик нажатия клавишы
void GraphicWidget::keyPressEvent(QKeyEvent *event){
    // скорость квадрата
    short v = 5;

    // event->key() - возвращает код нажатой клавиши

    switch ( event->key() ){

        case Qt::Key_Up:
            my_item->moveBy(0, -v);
            break;

        case Qt::Key_Down:
            my_item->moveBy(0, v);
            break;

        case Qt::Key_Right:
            my_item->moveBy(v, 0);
            break;

        case Qt::Key_Left:
            my_item->moveBy(-v, 0);
            break;

    }

}

// обработчик нажатия кнопки мыши
void GraphicWidget::mousePressEvent(QMouseEvent* event){
    short d = 1;
    scene.addEllipse( event->x()-ceil(d/2)-1,
                      event->y()-ceil(d/2)-1, d,d,
                      QPen(), QBrush(Qt::yellow));
}


GraphicWidget::~GraphicWidget(){}
