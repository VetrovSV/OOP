#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile( "stylesheet.qss" );
    styleFile.open( QFile::ReadOnly );

    QString s = styleFile.readAll();
    // Apply the loaded stylesheet
//    a.setStyleSheet( s );

    a.setStyleSheet("QWidet{ background-color: yellow;} QPushButton{ color: yellow;}");


    MainWindow w;
    w.show();
    return a.exec();

}
