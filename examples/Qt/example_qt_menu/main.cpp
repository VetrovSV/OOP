#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    srand(time(0));
    return a.exec();
}


/* Главное меню.
 * Обработчики и горячие клавиши
 * Панель инструментов
 * Диалоговые окна для выбора файлов: загрузка и создание
 *  Фильтры, название окна, домашняя папака
 * QTextEdit и настройка стиля текста
 * Ресурсы и иконка
 * */
