#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Данные, указатель на которые будет передан второму окну
    data = new Data();
    data->s = "Secret String";
}


MainWindow::~MainWindow(){ delete ui; }


/// Открывает второе окно
void MainWindow::on_pushButton_newwindow_clicked(){
    // текст из поля ввода в общую для окон переменную data
    data->s = ui->lineEdit->text().toStdString();

// вариант #1: доступны оба окна
    //    if (this->form == nullptr){
    //        this->form = new Form();  // новое окно не добавляется дочерним к текущему: parent = nullprt
    //        // второму окну даём доступ к данным этого (главного) окна
    //        this->form->data = this->data;
    //    }
    //    this->form->show();


// вариант #2: основное окно скрывается
    if (form == nullptr){       // если второе окно не создавалось
        // скрываем текущее окно
        // выделаем память под объект нового, второго окна
        this->form = new Form();
        // второму окну даём доступ к данным этого (главного) окна
        this->form->data = this->data;

        // с помошью механизма Qt для связывания методов,
        // задаём второй метод show как обработчик первого back_clicked
        // когда на втором окне нажата кнопка back показать главное окно
        connect(form, &Form::back_clicked, this, &MainWindow::show);
    }
    this->hide();  // скрыть текущее окно
    form->show();  // показать новое
}
