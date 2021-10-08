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

void MainWindow::on_ok_pushButton_clicked()
{
    setWindowTitle("Clicou...");
    ui->saida_label->setText("Hello World!");
}

void MainWindow::on_valor_spinBox_valueChanged(int arg1)
{
    int dobro = arg1 * 2;
    ui->dobro_label->setText();
}
