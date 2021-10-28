#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>
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

void MainWindow::showName(){
    this->setWindowTitle(currentFileName.isEmpty()
                         ? "Unsaved document"
                         : currentFileName);
}

void MainWindow::saveFile(bool isSaveAs){
    if(isSaveAs || currentFileName.isEmpty()){
        QString fileName = QFileDialog::getSaveFileName();
        if(fileName.isEmpty()) return;
        setCurrentFileName(fileName);
    }
    ui->statusBar->showMessage("Saving " + currentFileName + "...", 2000);
    QFile file(currentFileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream textStream(&file);
    textStream << ui->plainTextEdit->toPlainText();
    file.close();
}

void MainWindow::setCurrentFileName(const QString& name){
    currentFileName = name;
    showName();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName.isEmpty()) return;

    setCurrentFileName(fileName);
    ui->statusBar->showMessage("Opening " + fileName + "...", 2000);
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream textStream(&file);
    QString text = textStream.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_actionNew_triggered()
{
    if(ui->plainTextEdit->document()->isModified()){
        if(QMessageBox::question(this,
                                 "",
                                 "The document has been modified.\nWould you like to save the changes?"
                                 )==QMessageBox::Yes){
            saveFile();
        }
    }
    ui->plainTextEdit->setPlainText("");
    setCurrentFileName("");
}

void MainWindow::on_actionSave_triggered()
{
    saveFile();
}

void MainWindow::on_actionSave_as_triggered()
{
    saveFile(true);
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->plainTextEdit->font());
    if(ok){
        ui->plainTextEdit->setFont(font);
    }
}
