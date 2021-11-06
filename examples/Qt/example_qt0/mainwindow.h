#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>


// Пространство имён описывается ещё и в автоматически генерируемом
// при компиляции файле ui_mainwindow.h.
// Этот файл создаётся из mainwindow.ui
namespace Ui {
class MainWindow;
}


// Класс главного окна описывается программистом,
// но наследуется от обощёного класса "QMainWindow" - пустое окно.
// Этот класс предоставляет базовые возможности по работе с окном,
// отображению виджетов (элементов интерфейса)
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    // метод - обработчик собития "нажатие на кнопку" pushButton_add
    //  создаётся в дизайнере форм: ПКМ на кнопке -> перейти к слоту -> cliked()
    void on_pushButton_add_clicked();


    // обработчик собития "нажатие на кнопку" pushButton_clear
    void on_pushButton_clear_clicked();


    // обработчик собития "изменение состояния" флажка (чекбокса) checkBox
    // в arg1 записано новое состояние чекбокса
    void on_checkBox_stateChanged(int arg1);

private:
    // Тут обычно описываются данные программы...


    // поле ui содержит все элементы интрефейса пользователя
    // расположеные в главном окне
    // ui - экземпляр класса MainWindow из пространства имён Ui

    // Этот класс MainWindow генерируется автоматически из файла формы  mainwindow.ui
    // Файл mainwindow.ui - это XML файл описывающий главную форму,
    // Этот фойл редактируется в Дизайнере форм,  встроеным в  Qt Creator

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
