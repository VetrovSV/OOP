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
    for (auto &row : sole.A)
        for (auto &e : row) e = rnd();

    for (auto &e : sole.B) e = rnd();}


     // Такой код тоже стоит выделить в отдельный метод
    size_t n = sole.A.size();
    for (size_t i = 0; i<n; i++){
        for (size_t j = 0; j<n; j++)
            ui->tableWidget->item(i,j)->setText( QString::number(sole.A[i][j]) );
    }


    for (size_t i = 0; i<n; i++) ui->tableWidget->item(i,n)->setText( QString::number(sole.B[i]) );
}


// Метод который должен выполнять полезную работу
// ... но он только имитирует деятельность
void MainWindow::on_pushButton_calc_clicked(){
    // Алгоритм работы с данными полученными от польователя может быть примерно таким
    // Записать данные в соответствующие объекты (здесь: Таблица -> Матрицы)
    // Изменить данные( Решение )
    // Отобразить на форме новые данные (здесь: Матрицы -> Таблицы )
    size_t n = sole.A.size();

    {// Считывание данных из таблицы. Хорошо бы сделать методом
    for (size_t i =0; i<n; i++)
        for (size_t j =0; j<n; j++)
            // Здесь должна быть обработка искл.ситуаций: если в ячейке не число
            sole.A[i][j] = ui->tableWidget->item(i,j)->text().toFloat();
    }

    for (size_t i =0; i<n; i++) sole.B[i] = ui->tableWidget->item(i,n)->text().toFloat();

    // Симуляция решения СЛАУ: заполним иксы случайными числами
    for (auto &e : sole.X) e = 1. * random()/RAND_MAX;

    for (size_t i = 0; i<n; i++) ui->tableWidget->item(i,n+1)->setText( QString::number(sole.X[i]) );
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
    sole.A.resize(n);
    for (auto &row : sole.A) row.resize(n);
    sole.B.resize(n);
    sole.X.resize(n);}

}
