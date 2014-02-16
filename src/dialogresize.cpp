#include "dialogresize.h"
#include "ui_dialogresize.h"

DialogResize::DialogResize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResize)
{
    ui->setupUi(this);
}

DialogResize::~DialogResize()
{
    delete ui;
}
