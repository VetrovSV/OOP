#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->on_spinBox_n_valueChanged( ui->spinBox_n->value() );
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_gen_clicked(){
    // Заполнение матриц случайными числами
    // Матрицы -> Таблица

    auto rnd = [](){return 1.*(random() % 100 - 50 )/10; };

    { // Это должно быть отдбельным методом отдельного класса СЛАУ
    for (auto &row : A)
        for (auto &e : row) e = rnd();

    for (auto &e : B) e = rnd();}

    size_t n = A.size();
    for (size_t i = 0; i<n; i++){
        for (size_t j = 0; j<n; j++)
            ui->tableWidget->item(i,j)->setText( QString::number(A[i][j]) );
    }

    for (size_t i = 0; i<n; i++) ui->tableWidget->item(i,n)->setText( QString::number(B[i]) );
}


void MainWindow::on_pushButton_calc_clicked(){
    // Таблица -> Матрицы
    // Решение...
    // Матрицы -> Таблицы
    size_t n = A.size();
    auto m = n+2;

    for (size_t i =0; i<n; i++)
        for (size_t j =0; j<n; j++)
            A[i][j] = ui->tableWidget->item(i,j)->text().toFloat(); // Здесь должна быть обработка искл.ситуаций: если в ячейке не число

    for (size_t i =0; i<n; i++) B[i] = ui->tableWidget->item(i,n)->text().toFloat();

    for (auto &e : X) e = 1. * random()/RAND_MAX;
    for (size_t i = 0; i<n; i++) ui->tableWidget->item(i,n+1)->setText( QString::number(X[i]) );
}


void MainWindow::on_spinBox_n_valueChanged(int n){
    // Изменение числа строк в таблице
    ui->tableWidget->setRowCount(n);
    ui->tableWidget->setColumnCount(n+2);

    // Содержимое каждой яйчейки талицы - это экземпляр класса QTableWidgetItem
    // Таблица создаётся с ячейками без содержимого. Сколько бы строк и столбцов там не было.
    // Поэтому нужно создавать для каждой яйчейки объекты.
    for (size_t i = 0; i<n; i++){
        for (size_t j = 0; j<n+2; j++){
        QTableWidgetItem *cell;
        if (ui->tableWidget->item(i,j) == NULL ) {
         cell = new QTableWidgetItem();
         ui->tableWidget->setItem(i,j,cell);} } }


    {  // Это должно быть отдбельным методом отдельного класса СЛАУ
    A.resize(n);
    for (auto &row : A) row.resize(n);
    B.resize(n);
    X.resize(n);}

}
