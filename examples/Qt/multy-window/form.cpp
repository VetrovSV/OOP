#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form(){
    delete ui;

}

void Form::on_pushButton_back_clicked()
{
    this->hide();
    emit back_clicked();
}

void Form::showEvent(QShowEvent *event)
{
    ui->label_data->setText( QString::fromUtf8(data->s.c_str()) );
}
