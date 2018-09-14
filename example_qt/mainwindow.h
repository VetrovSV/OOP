#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "sole.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_gen_clicked();

    void on_pushButton_calc_clicked();

    void on_spinBox_n_valueChanged(int n);

private:
    Ui::MainWindow *ui;  // Этот класс генерируется автоматически из файла mainwindow.ui

    SoLE sole;
};

#endif // MAINWINDOW_H
