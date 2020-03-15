#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_newwindow_clicked(){

// вариант #1: доступны обо окна
    if (form == nullptr){
        form = new Form();  // новое окно не добавляется дочерним к текущему: parent = nullprt
    }
    form->show();


// вариант #2: основное окно скрывается
//    if (form == nullptr){
//        this->hide();
//        form = new Form();
//        // когда на втором окне назать кнопка back показать главное окно
//        connect(form, &Form::back_clicked, this, &MainWindow::show);
//    }
//    this->hide();  // скрыть текущее окно
//    form->show();  // показать новое
}
