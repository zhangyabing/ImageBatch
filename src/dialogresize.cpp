#include "dialogresize.h"
#include "ui_dialogresize.h"

DialogResize::DialogResize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResize)
{
    ui->setupUi(this);

    QIntValidator* aIntValidator = new QIntValidator;
    aIntValidator->setRange(0, 99999999);
    ui->lineEditWidth->setValidator(aIntValidator);

    QIntValidator* bIntValidator = new QIntValidator;
    bIntValidator->setRange(0, 99999999);
    ui->lineEditHeight->setValidator(bIntValidator);

    QDoubleValidator* cIntValidator = new QDoubleValidator;
    cIntValidator->setRange(0.0, 99999999.0);
    cIntValidator->setDecimals(1);
    ui->lineEditPer->setValidator(cIntValidator);
}

DialogResize::~DialogResize()
{
    delete ui;
}

void DialogResize::on_groupBoxValue_toggled(bool arg1)
{
    if(arg1==true)
    {
        ui->groupBoxPercentage->setChecked(false);
    }
}

void DialogResize::on_groupBoxPercentage_toggled(bool arg1)
{
    if(arg1==true)
    {
        ui->groupBoxValue->setChecked(false);
    }
}
