#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class LoginWindow;
}

///
class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    QString username;

    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    /// открывает основное (второе) окно программы
    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
