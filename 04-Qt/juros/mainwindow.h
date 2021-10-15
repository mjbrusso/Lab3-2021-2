#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocale>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_fechar_pushButton_clicked();

    void on_calcular_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QLocale currLoc;
};

#endif // MAINWINDOW_H
