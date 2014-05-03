#ifndef DIALOGRESIZE_H
#define DIALOGRESIZE_H

#include <QDialog>

namespace Ui {
class DialogResize;
}

class DialogResize : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResize(QWidget *parent = 0);
    ~DialogResize();

private slots:

    void on_groupBoxValue_toggled(bool arg1);

    void on_groupBoxPercentage_toggled(bool arg1);

public:
    Ui::DialogResize *ui;
};

#endif // DIALOGRESIZE_H
