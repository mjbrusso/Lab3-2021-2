#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLocale>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->valores_tableWidget->setColumnWidth(0, 60);
    ui->valores_tableWidget->setColumnWidth(1, 150);
    ui->valores_tableWidget->setColumnWidth(2, 150);

    currLoc = QLocale();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fechar_pushButton_clicked()
{
    QApplication::exit(0);
}

void MainWindow::on_calcular_pushButton_clicked()
{
    double valor = ui->valor_doubleSpinBox->value();
    double taxa_juros = ui->taxa_doubleSpinBox->value();
    int meses = ui->nummeses_spinBox->value();
    ui->valores_tableWidget->setRowCount(0);
    for(int i = 0; i < meses; i++){
        double juro = valor * taxa_juros / 100;
        valor += juro;
        ui->valores_tableWidget->insertRow(i);
        // QTableWidgetItem* item = new QTableWidgetItem(QString::number(i + 1));
        //item->setBackgroundColor(QColor::fromRgb(0, 255, 0));
        ui->valores_tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->valores_tableWidget->setItem(i, 1, new QTableWidgetItem(currLoc.toCurrencyString(juro)));
        ui->valores_tableWidget->setItem(i, 2, new QTableWidgetItem(currLoc.toCurrencyString(valor)));
    }
}

