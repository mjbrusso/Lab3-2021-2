#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
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
                         ? tr("Unsaved document")
                         : currentFileName);
}

bool MainWindow::saveFile(bool isSaveAs){
    if(isSaveAs || currentFileName.isEmpty()){
        QString fileName = QFileDialog::getSaveFileName();
        if(fileName.isEmpty()) return false;
        setCurrentFileName(fileName);
    }
    ui->statusBar->showMessage(tr("Saving %1 ...").arg(currentFileName), 2000);
    QFile file(currentFileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    QTextStream textStream(&file);
    textStream << ui->plainTextEdit->toPlainText();
    file.close();
    return true;
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
    ui->statusBar->showMessage(tr("Opening %1...").arg(fileName), 2000);
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream textStream(&file);
    QString text = textStream.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
    int numLines = ui->plainTextEdit->document()->blockCount();
    ui->statusBar->showMessage(tr("%n line(s) read.", "", numLines));
}

void MainWindow::on_actionNew_triggered()
{
    if(ui->plainTextEdit->document()->isModified()){
        auto btn = QMessageBox::question(this,  // parent
                                         "",    // título (default=nome do programa)
                                         tr("The document has been modified.\nWould you like to save the changes?"),    // Texto
                                         QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, // Botões
                                         QMessageBox::Yes   // Botão default
                                         );

        if(btn==QMessageBox::Yes && !saveFile()) return;
        else if(btn==QMessageBox::Cancel) return;
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

void MainWindow::on_actionAbout_Notepad_triggered()
{
    AboutDialog *dlg = new AboutDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->show();
}

