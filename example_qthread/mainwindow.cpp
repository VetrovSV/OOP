#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->th = new QThread();
    this->worker = new Worker();

    // класс (методы) будут работать не в данном, а в указаном в параметре потоке
    // метод moveToThread класса Worker унаследован от QObject
    worker->moveToThread(th);

    // Запуск потока должен запустить вычисления в классе
    connect(th, &QThread::started, worker, &Worker::process);

    connect(worker, &Worker::finished, th, &QThread::quit);

    // остановка потока должна вызывать обновление label на форме
    connect(worker, &Worker::finished, this, &MainWindow::update_result);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_run_here_clicked()
{
    unsigned long n = ui->spinBox_n->value();
    worker->set_param(n);

    ui->label_result->setText("идут вычисления..."); // это никто не увидит
    worker->process();

    update_result();
}

void MainWindow::on_pushButton_run_thread_clicked(){

    ui->label_result->setText("идут вычисления...");
    th->start();
}

void MainWindow::update_result(){
     ui->label_result->setText( QString::number(worker->get_result()));
}

