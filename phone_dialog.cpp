#include "phone_dialog.h"
#include "ui_phone_dialog.h"

Phone_dialog::Phone_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Phone_dialog)
{
    ui->setupUi(this);
}

Phone_dialog::~Phone_dialog()
{
    delete ui;
}

void Phone_dialog::add_text(QString s)
{
    ui->label->setText(s);
    ui->label->adjustSize();
}
