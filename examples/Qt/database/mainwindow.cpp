#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Связывание объекта с табличными данными  -- модели, на основе QStandardItemModel
    // и таблицы на форме -- представления, QTableView (не путать с QTableWidget);
    ui->tableView->setModel(&model);
    // все изменения таблице будут автоматически вносится в модель и наоборот

    // включить сортировку по клику на загловок таблицы
    ui->tableView->setSortingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// добавление случайной строки в таблицу
void MainWindow::on_pushButton_add_rnd_clicked()
{   // после добавления таблица автоматически отобразит новые данные
    model.add_random_row_simple();
}

/// сохранение данных в файл (CSV)
void MainWindow::on_actionSave_triggered(){
    QFileDialog dialog;
    model.save( dialog.getSaveFileName(this) );
}

/// загрузка данных из CSV файла в модель
void MainWindow::on_actionOpen_triggered(){
    QFileDialog dialog;
    // после загрузки таблица автоматически отобразит новые данные
    model.open( dialog.getOpenFileName(this) );
}
