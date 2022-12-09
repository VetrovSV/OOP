#include <QFileDialog>          // библиотека для создания диалоговых окон
#include <QTextStream>

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


/// загрузка содержимого файла в многострочное поле ввода textEdit
void MainWindow::on_actionopen_triggered(){
    // получение пути к домашней папке пользователя
    QString home = QDir::homePath();
    
    // функция getOpenFileName создаёт диалоговое окно для открытия существующего файла
    // Параметры: 
    // указатель на объект родительского окна
    // Заголовок окна
    // Путь к паке по умолчанию
    // Фильтр по типам файлов
    // После закрытия окна функция вернёт абсолютное имя файла, если он был выбран
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open Text File", home, "Text Files (*.txt)");
    
    // Чтение из файла в многострочное поле ввода
    QFile f(fileName);
    if ( f.open(QFile::ReadOnly) ){
        QTextStream s(&f);

        ui->textEdit->setText( s.readAll() );
    }
}


/// сохранение содержимого многострочного поля ввода textEdit в файл
void MainWindow::on_actionsave_triggered(){
    // получение пути к домашней папке пользователя
    QString home = QDir::homePath();
    
    // функция getSaveFileName создаёт диалоговое окно для выбора имени существующего файла или ввода нового имени
    // возвращает абсолютный путь к файлу
    QString fileName = QFileDialog::getSaveFileName(this,
        "Open Image", home);
    
    // запись в файл 
    QFile f(fileName);
    if ( f.open(QFile::WriteOnly) ){
        QTextStream s(&f);

        s << ui->textEdit->toPlainText();
        f.close();
    }
}


void MainWindow::on_action_exit_triggered()
{

}

void MainWindow::on_actionread_only_triggered()
{

}


/// очистка многострочного поля ввода
void MainWindow::on_actionclear_triggered()
{
    ui->textEdit->clear();
}
