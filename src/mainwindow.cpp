#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogresize.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QBrush>

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

void MainWindow::on_btnAddFile_clicked()
{
    QStringList list = QFileDialog::getOpenFileNames(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png)"));

    if(list.length() > 0)
    {
        standardItemModel = new QStandardItemModel(this);
        for(int i=0;i<list.length();++i)
        {
            QStandardItem *item = new QStandardItem(list[i]);
            if(i %2 == 1)
            {
                QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
                linearGrad.setColorAt(0, QColor(255,0,0));
                linearGrad.setColorAt(1, QColor(0,255,0));
                QBrush brush(linearGrad);
                item->setBackground(brush);
            }
            standardItemModel->appendRow(item);
        }
        ui->fileList->setModel(standardItemModel);//显示model中的内容
    }
}

void MainWindow::on_btnResize_clicked()
{
    DialogResize dlg;
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }


}
