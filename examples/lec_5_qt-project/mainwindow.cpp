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

// обработчик нажатия на кнопку.
// создаётся автоматически: пкм на кнопке > перейти к слоту > clicked()
void MainWindow::on_pushButton_calc_clicked()
{
    float x, y, sum;
    // получение данных с формы
    // в ui лежат все элементы интерфейса с формы
    // text() выдаёт содержащийся в элементе текст
    // toFloat() -- преобразовать строку в число
    x = ui->lineEdit_num1->text().toFloat();
    y = ui->lineEdit_num2->text().toFloat();

    // TODO: перенести в модуль
    sum = x + y;

    // добавление строк в PlainTextEdit
    // QString::number(x) - преобразование числа x в строковый тип данных QString (аналог std::string)
    ui->plainTextEdit_report->appendPlainText("x = " + QString::number(x) +
                                              ", y = " + QString::number(y) +
                                              "\nсумма = " + QString::number(sum)+
                                              "\n");

}
