#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// метод - обработчик собития "нажатие на кнопку" pushButton_add
//  создаётся в дизайнере форм: ПКМ на кнопке -> перейти к слоту -> cliked()
void MainWindow::on_pushButton_add_clicked(){

    //  получить содержимое однострочного поля ввода lineEdit
    QString s = ui->lineEdit->text() + "\n";

    //  получить содержимое многострочного поля ввода TextEdit
    QString old_text = ui->textEdit->toPlainText();

    // Задать содержимое многострочного поля ввода TextEdit
    ui->textEdit->setText( old_text + s );
}


// обработчик собития "нажатие на кнопку" pushButton_clear
void MainWindow::on_pushButton_clear_clicked()
{
    ui->textEdit->clear();
}


// обработчик собития "изменение состояния" флажка (чекбокса) checkBox
// в arg1 записано новое состояние чекбокса
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    ui->textEdit->setReadOnly(arg1);
}
