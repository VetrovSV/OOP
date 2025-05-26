#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "abstractchatbot.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);

private slots:
    void on_pushButton_send_clicked();

private:
    void keyPressEvent(QKeyEvent *e);

    Ui::MainWindow *ui;
    QString username;

    AbstractChatBot *bot;
};
#endif // MAINWINDOW_H
