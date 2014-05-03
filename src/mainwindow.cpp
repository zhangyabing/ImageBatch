#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialogresize.h"
#include "dialogresize.h"

#include <iostream>

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
//        standardItemModel = new QStandardItemModel(this);
//        for(int i=0;i<list.length();++i)
//        {
//            QStandardItem *item = new QStandardItem(list[i]);
//            if(i %2 == 1)
//            {
//                QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
//                linearGrad.setColorAt(0, QColor(255,0,0));
//                linearGrad.setColorAt(1, QColor(0,255,0));
//                QBrush brush(linearGrad);
//                item->setBackground(brush);
//            }
//            standardItemModel->appendRow(item);
//        }
//        ui->fileList->setModel(standardItemModel);//显示model中的内容
        for(int i =0; i < 100 ; i ++)
        {
            QListWidgetItem *item = new QListWidgetItem(ui->fileList);
            QStyle::StandardPixmap sp = (QStyle::StandardPixmap)(i % 57);

            item->setData(Qt::DecorationRole, qApp->style()->standardPixmap(sp).scaled(QSize(16,16), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
            item->setData(Qt::DisplayRole,QObject::tr("Item %1").arg(i));
        }
    }
}

void MainWindow::on_btnResize_clicked()
{
    DialogResize dlg;
    if (dlg.exec() == QDialog::Rejected)
    {
        return;
    }

    QString strCammond="-resize";
    QString strParame;

    if(dlg.ui->groupBoxPercentage->isChecked())
    {
        char data[200]="111";
        ::sprintf_s(data,"%%%s",qPrintable(dlg.ui->lineEditPer->displayText()));
        strParame=data;
    }
    execute(strCammond,strParame);
}

void MainWindow::execute(const QString &command,const QString &parame)
{
    QString fmt="convert %1 %2 %3 %4";
    QString str=fmt.arg(command).arg(parame).arg("c:/1.png").arg("c:/1.png");
    std::cout<<qPrintable(str)<<std::endl;
    system(qPrintable(str));
}







