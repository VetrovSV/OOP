#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "data.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    Data *data;


signals:
    void back_clicked();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::Form *ui;

    void showEvent ( QShowEvent * event );


};

#endif // FORM_H
