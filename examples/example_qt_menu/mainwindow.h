#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionopen_triggered();

    void on_action_exit_triggered();

    void on_actionsave_triggered();

    void on_actionread_only_triggered();

    void on_actionclear_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
