#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}


Form::~Form(){ delete ui; }


/// Открывает основное окно
void Form::on_pushButton_back_clicked()
{
    this->hide();               // скрывает это окно
    emit back_clicked();        // вызывает метод-сигнал
}


/// Обработчик, который вызывается при показе окна
void Form::showEvent(QShowEvent *event){
    // при отображении показывает строку из переменной data
    ui->label_data->setText( QString::fromUtf8(data->s.c_str()) );
}
