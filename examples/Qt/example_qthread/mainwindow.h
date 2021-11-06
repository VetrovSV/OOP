#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "worker.h"

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
    // запуск вычислений прямо в данном методе
    void on_pushButton_run_here_clicked();

    // запуск вычислений в отдельном потоке
    void on_pushButton_run_thread_clicked();

    // метод обновляющий label на фрме
    void update_result();

private:
    Ui::MainWindow *ui;

    // поток для отдельных вычислений
    QThread *th;
    // класс выполняющий отдельные вычисления
    Worker *worker;
};

#endif // MAINWINDOW_H
