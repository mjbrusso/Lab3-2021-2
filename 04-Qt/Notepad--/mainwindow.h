#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionFont_triggered();

    void on_actionAbout_Notepad_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFileName;
    void showName();
    void setCurrentFileName(const QString& name);
    bool saveFile(bool isSaveAs=false);
};

#endif // MAINWINDOW_H
