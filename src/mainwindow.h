#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStandardItemModel;
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
    void on_btnAddFile_clicked();

    void on_btnResize_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *standardItemModel;//声明model

};

#endif // MAINWINDOW_H
