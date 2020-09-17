#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    All = new QString();

    ui->lineEdit->setReadOnly(true);


    connect(ui->Button0, &QPushButton::clicked, [=](){ Logic("0"); });
    connect(ui->Button1, &QPushButton::clicked, [=](){ Logic("1"); });
    connect(ui->Button2, &QPushButton::clicked, [=](){ Logic("2"); });
    connect(ui->Button3, &QPushButton::clicked, [=](){ Logic("3"); });
    connect(ui->Button4, &QPushButton::clicked, [=](){ Logic("4"); });
    connect(ui->Button5, &QPushButton::clicked, [=](){ Logic("5"); });
    connect(ui->Button6, &QPushButton::clicked, [=](){ Logic("6"); });
    connect(ui->Button7, &QPushButton::clicked, [=](){ Logic("7"); });
    connect(ui->Button8, &QPushButton::clicked, [=](){ Logic("8"); });
    connect(ui->Button9, &QPushButton::clicked, [=](){ Logic("9"); });

    connect(ui->Multiply, &QPushButton::clicked, [=](){ Logic("*"); });
    connect(ui->Share, &QPushButton::clicked, [=](){ Logic("/"); });
    connect(ui->Minus, &QPushButton::clicked, [=](){ Logic("-"); });
    connect(ui->Plus, &QPushButton::clicked, [=](){ Logic("+"); });

    connect(ui->ButtonDot, &QPushButton::clicked, [=](){ Logic("."); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Logic(QString input)
{
    All->push_back(input);
    ui->lineEdit->setText(*All);
}



void MainWindow::on_Clear_clicked()
{
    ui->lineEdit->clear();
    All->clear();
}

void MainWindow::on_BackSpace_clicked()
{
    if(All->toLocal8Bit()[All->toLocal8Bit().size() - 1] == ' ')
        All->chop(3);
    else
        All->chop(1);

    ui->lineEdit->setText(*All);

}

void MainWindow::on_Equal_clicked()
{
    QString input(ui->lineEdit->text());
    Calculator calc;
    double result = calc.calculate(input.toStdString());

    *All = QVariant(result).toString();
    ui->lineEdit->setText(*All);
}
