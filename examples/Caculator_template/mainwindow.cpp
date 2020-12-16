#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_sin_clicked()
{
    float a = ui->lineEdit->text().toFloat();

    float result = this->calc.sin( a );

    ui->lineEdit->setText( QString::number(result) );
}
