#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelstuds.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /// добавление случайной строки в таблицу
    void on_pushButton_add_rnd_clicked();

    /// сохранение данных в файл (CSV)
    void on_actionSave_triggered();

    /// загрузка данных из CSV файла в модель
    void on_actionOpen_triggered();

    void on_pushButton_add_rnd_simple_clicked();

private:
    Ui::MainWindow *ui;

    ModelStuds model;               // модель -- объект хранящий и обрабатывающий данные
};
#endif // MAINWINDOW_H
