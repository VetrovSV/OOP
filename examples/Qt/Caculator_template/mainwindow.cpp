#include <QKeyEvent>
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

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    ui->label_test->setText("You Pressed Key " + ev->text() );

    if (ev->key() == Qt::Key_Backspace)
        ui->lineEdit->clear();


    // Выход из программы на Ctrl + Q
    if (ev->modifiers() & Qt::ControlModifier){
        if (ev->key() == Qt::Key_Q){
            this->close();
        }
    }
}

void MainWindow::on_pushButton_sin_released()
{

}

void MainWindow::on_pushButton_div_clicked()
{
    // TODO: calc.set_operand
    try {
        calc.div();
    }  catch (const std::exception& e) {
        ui->lineEdit->setText(e.what());
    }

}
