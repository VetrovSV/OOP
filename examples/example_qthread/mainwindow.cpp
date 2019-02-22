#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создадим обхект для управления потоком
    this->th = new QThread( this );
    // Укажем, что этим обектом может управлять класс главного окна
    // Например MainWindow сможет очищать выделенную память для th

    // Объект, который будет выполнять вычисления (в том числе в отдельном потоке)
    this->worker = new Worker( );
    // Он должен быть "сам по себе" (указатель на владельца не передаётся в конструктор),
    // чтобы его можно было перекинуть на другой поток


    // Запуск потока должен запустить вычисления в классе
    connect(th, &QThread::started, worker, &Worker::process);

    connect(worker, &Worker::finished, th, &QThread::quit);

    // остановка потока должна вызывать обновление label на форме
    connect(worker, &Worker::finished, this, &MainWindow::update_result);

    // соеденим сигнал Worker сообщающий о статусе вычислений
    // с методом устанавливающим состояние полосы прогресса
    connect(worker, &Worker::progress, ui->progressBar, &QProgressBar::setValue);
    connect(worker, SIGNAL(progress(uint)), this, SLOT(update()));

}

MainWindow::~MainWindow(){

    delete worker;
    delete ui;
}

void MainWindow::on_pushButton_run_here_clicked()
{
    unsigned long n = ui->spinBox_n->value();

    worker->moveToThread(QApplication::instance()->thread());

    worker->set_param(n);

    ui->label_result->setText("идут вычисления...");
    worker->process();

    update_result();
}

void MainWindow::on_pushButton_run_thread_clicked(){
    worker->set_param( ui->spinBox_n->value() );

    // класс (методы) будут работать не в данном, а в указаном в параметре потоке
    // метод moveToThread класса Worker унаследован от QObject
    worker->moveToThread(th);

    ui->label_result->setText("идут вычисления...");
    th->start();
}

void MainWindow::update_result(){
     ui->label_result->setText( QString::number(worker->get_result()));
}

