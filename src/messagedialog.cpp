#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

void MessageDialog::displayErrorMessage(QString message){
    ui->label->setText(message);
    this->show();
}

void MessageDialog::on_pushButton_clicked()
{
    this->close();
}
