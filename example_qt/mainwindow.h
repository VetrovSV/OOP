#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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


    // Эти поля представляют собой коэффициенты, cтолбец свободных членов и решения СЛАУ
    // Лучше всего они бы смотрелись внутри отдельного класса - СЛАУ, который бы агрегировался например сюда.
    vector <vector <float> > A;
    vector <float> B;
    vector <float> X;
};

#endif // MAINWINDOW_H
