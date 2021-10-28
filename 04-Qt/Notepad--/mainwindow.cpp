#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showName();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName.isEmpty()) return;

    currentFileName = fileName;
    showName();
    ui->statusBar->showMessage("Opening " + fileName + "...", 2000);
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream textStream(&file);
    QString text = textStream.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::showName(){
    this->setWindowTitle(currentFileName.isEmpty()
                         ? "Unsaved document"
                         : currentFileName);
}

void MainWindow::on_actionNew_triggered()
{

}
