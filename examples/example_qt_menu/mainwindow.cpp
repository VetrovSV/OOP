#include <QFileDialog>
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

void MainWindow::on_actionopen_triggered(){
    QString home = QDir::homePath();

    QString fileName = QFileDialog::getOpenFileName(this,
        "Open Image", home, "Text Files (*.txt *.scv)");

    QFile f(fileName);
    if ( f.open(QFile::ReadOnly) ){
        QTextStream s(&f);

        ui->textEdit->setText( s.readAll() );
    }
}


void MainWindow::on_actionsave_triggered(){
    QString home = QDir::homePath();

    QString fileName = QFileDialog::getSaveFileName(this,
        "Open Image", home);

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

void MainWindow::on_actionclear_triggered()
{
    ui->textEdit->clear();
}
