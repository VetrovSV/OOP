#include <QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout *layoyt = new QVBoxLayout();

    QPushButton *b = new QPushButton("PushMe");
    QPushButton *b2 = new QPushButton("Show Label");
    QLabel *l = new QLabel("I am Label");

    layoyt->addWidget(b);
    layoyt->addWidget(l);
    layoyt->addWidget(b2);
    w.setLayout(layoyt);


    QObject::connect(b, &QPushButton::clicked, l, &QLabel::hide);
    QObject::connect(b2, &QPushButton::clicked, l, &QLabel::show);
    // Чтобы вызвать нестандартное действие QLabel нужно создать новый класс на основе QLabel
    // в котором определить новый метод, реализующий требуемое действие.

    // Можно соединсять не только методы, но и метод с любой функцией.
    // в том числе с лямбда функцией
    QObject::connect(b, &QPushButton::clicked,
                     [=](){ qDebug() << "label is hide"; } );

    QObject::connect(b, &QPushButton::clicked, &w, &QWidget::close );


    w.show();

    return a.exec();
}
