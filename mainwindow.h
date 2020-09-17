#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtCore>
#include <QPushButton>
#include <string>
#include <QRegExp>
#include "Calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Clear_clicked();

    void on_BackSpace_clicked();

    void on_Equal_clicked();

private:
    Ui::MainWindow *ui;
    QString *All;

    void Logic(QString input);

};

#endif // MAINWINDOW_H
