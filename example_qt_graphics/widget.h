#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsView>


class GraphicWidget : public QGraphicsView
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    explicit GraphicWidget(QWidget *parent = 0);
    ~GraphicWidget();

    void update();

private:

//    QGraphicsView предоставяет предназнаен только для отображения графических объектов
//    Объекты должны быть ассоциированы с QGraphicsScene, который ассоциирован с QGraphicsView
    QGraphicsScene scene;

// Графический объект (базовый класс)
    QGraphicsItem *my_item;
    QGraphicsItem *other_item;
    unsigned item_size = 20;
    QVector2D v;

// Таймер для анамиции
// Таймер будет отвечать за интервал обновления сцены
    QTimer* timer;

};

#endif // WIDGET_H
