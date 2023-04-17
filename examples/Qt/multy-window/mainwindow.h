#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include "form.h"    // окно #2


namespace Ui {
class MainWindow;
}

/// Основное окно программы
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /// Открывает второе окно
    void on_pushButton_newwindow_clicked();

private:
    Ui::MainWindow *ui;

    /// Указатель на второе окно
    Form *form;

    /// Указатель на данные, которые должны быть доступным всем окнам
    Data *data;

};

#endif // MAINWINDOW_H






