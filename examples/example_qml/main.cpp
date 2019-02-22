#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlProperty>
#include <QObject>
#include "calc.h"

int main(int argc, char *argv[])
{
    // включить поддержку дисцплеев с высоким DPI (опционально)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // сделать класс Calc доступным в QML коде
    qmlRegisterType<Calc>("calc", 1, 0, "Calc");

    // Загрузка и разбор qml файла
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) return -1;


    return app.exec();
}
