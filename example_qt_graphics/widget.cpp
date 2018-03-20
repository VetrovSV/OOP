#include <QDebug>
#include "widget.h"
#include "ui_widget.h"

GraphicWidget::GraphicWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    // Задаём поверхность (сцену, 2D мир) который будет нарисаван QGraphicsView
    this->setScene(&scene);

    // Добавляем Прямоугольник на сцену
    my_item = scene.addRect(this->width()/2 - item_size/2, this->height()/2 - item_size/2, item_size, item_size, QPen(), QBrush(QColor(Qt::red)));

    other_item = scene.addEllipse(this->width()/3 - item_size/2, this->height()/3 - item_size/2, item_size/2,item_size/2, QPen(), QBrush(QColor(Qt::green)));
    v = QVector2D(1,1);


    timer = new QTimer(this);
    auto r = QObject::connect(timer, &QTimer::timeout, this, &GraphicWidget::update);
    timer->start(1000/30);
}




GraphicWidget::~GraphicWidget()
{

}


void GraphicWidget::update(){
    auto x =other_item->pos().x();
    auto y =other_item->pos().y();
    if (other_item->pos().x() > 80  ||  other_item->pos().y() > 80)
        v = -QVector2D(abs(v.x()),  abs(v.y()));

    if (other_item->pos().x() < 0        ||  other_item->pos().y() < item_size)
        v = QVector2D(abs(v.x()),  abs(v.y()));

    this->other_item->setPos( other_item->pos() + v.toPointF());

}

// Переопределённый обработчик нажатия клавишы
void GraphicWidget::keyPressEvent(QKeyEvent *event){
    short v = 5;

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
