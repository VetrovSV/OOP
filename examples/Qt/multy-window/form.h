#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "data.h"

namespace Ui {
class Form;
}

/// Второе окно программы
class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    /// Указатель на данные, которые должны быть доступным всем окнам
    Data *data;


signals:
    void back_clicked();

private slots:

    /// Открывает основное окно (MainWindow)
    void on_pushButton_back_clicked();

private:
    Ui::Form *ui;

    /// Обработчик, который вызывается при показе окна
    void showEvent ( QShowEvent * event );


};

#endif // FORM_H
