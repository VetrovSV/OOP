#include <QApplication>
#include <QFile>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // файл с описанием стилей всех элементов интерфейса программы
    // https://doc.qt.io/qt-6/stylesheet.html
    // https://doc.qt.io/qt-6/stylesheet-reference.html
    QFile styles(":/style.qss");
    // этот файл приведён в файле ресурсов (res.qrc), поэтому будет включён в исполняемый файл после компиляции

    // открытие, чтение и применение файла стилей
    styles.open(QFile::ReadOnly);
    a.setStyleSheet(styles.readAll());

    MainWindow w;
    w.show();
    return a.exec();
}
