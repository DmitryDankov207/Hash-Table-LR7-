#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    table = SortedHashTable(37);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    int value = ui->lineEdit->text().toInt(&ok);

    ui->listWidget->clear();

    if(ok){
        for (int i = 0; i < value; i++) {
            table.Push((double)(rand() % 10) + (double)(rand() % 1000) / 1000);
        }

        for (const auto str : table.TableToString()) {
            ui->listWidget->addItem(str);
        }
    }
    else
        ui->listWidget->addItem("Неверный ввод!");
}
