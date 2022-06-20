#include "mainwindow.h"
#include "ui_mainwindow.h"

/// конструктор главного окна -- метод (функция класса), которая вызывается после создания
/// переменной типа MainWindow и инициазирует ей поля
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// метод - обработчик собития "нажатие на кнопку" pushButton_add
//  создаётся в дизайнере форм: ПКМ на кнопке -> перейти к слоту -> cliked()
void MainWindow::on_pushButton_calc_clicked()
{  unsigned short nn[] = {1, 4, 12};
    // text() -- возвращает содержимое поля ввода (тип QString)
    // toFloat() -- возвращает число (float) записанное в QString
    float sum = ui->lineEdit_sum->text().toFloat();
    float p = ui->spinBox_percent->value();       // SpinBox уже хранит число, а не строку
    float t = ui->slider_t->value();
    unsigned short n = ui->comboBox_n->currentIndex();
    n = nn[n];


    // вычисления
    float result = sum * powf(1 + p/100/n, n*t);

    // QString::number(result) -- преобразование числа в QString;
    // 'f' - выводи в формате десятичного числа (без e), 1 -- число знаков после запятой
    QString result_str = QString::number(result,'f', 1);

    // запись результатов
    ui->label_result->setText( result_str );

    if (ui->radioButton_brief->isChecked())
        ui->textEdit_report->append("Итого: " + QString::number(result,'f', 1) + "\n");
    else{
        QString report;
        report  = "A = " + QString::number(result,'f', 0) + "; ";
        report += "p = " + QString::number(p) + "%; ";
        report += "t = " + QString::number(t) + "; ";
        report += "n = " + QString::number(n) + "; ";
        report += "n = " + QString::number(n) + "; ";
        report += "Итого: " + result_str + "\n";

        ui->textEdit_report->append(report);
}
}


// обработчик собития "изменение состояния" флажка (чекбокса) checkBox
// в arg1 записано новое состояние чекбокса
void MainWindow::on_checkBox_read_only_stateChanged(int arg1){
    ui->textEdit_report->setReadOnly( arg1 );

}
