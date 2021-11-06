#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
// Пространство имён описывается ещё и в автоматически генерируемом
// при компиляции файле ui_mainwindow.h.
// Этот файл создаётся из mainwindow.ui
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




// Класс главного окна описывается программистом,
// но наследуется от обощёного класса "QMainWindow" - пустое окно.
// Этот класс предоставляет базовые возможности по работе с окном,
// отображению виджетов (элементов интерфейса)
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Конструктор -- функция-член класса, которая вызывается сразу после создании переменной типа MainWindow
    MainWindow(QWidget *parent = nullptr);

    // Деструктор -- функция-член класса, которая вызывается перед освобождением памяти,
    // которую занимает переменная типа MainWindow
    ~MainWindow();

private slots:
    // метод - обработчик собития "нажатие на кнопку" pushButton_add
    // создаётся в дизайнере форм: ПКМ на кнопке -> перейти к слоту -> cliked()
    void on_pushButton_calc_clicked();

private:
    // данные программы:
    float x, y,             // входные данные
            sum;            // выходные данные
    // они доступны во всех обработчиках событий


    // поле ui содержит все элементы интрефейса пользователя
    // расположеные в главном окне
    // ui - экземпляр класса MainWindow из пространства имён Ui

    // Этот класс MainWindow генерируется автоматически из файла формы  mainwindow.ui
    // Файл mainwindow.ui - это XML файл описывающий главную форму,
    // Этот фойл редактируется в Дизайнере форм,  встроеным в  Qt Creator
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
