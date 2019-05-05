#include "progressbar.h"
#include "ui_progressbar.h"

ProgressBar::ProgressBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressBar)
{
    ui->setupUi(this);
    ui->progressBar->reset();
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);

}

ProgressBar::~ProgressBar()
{
    delete ui;
}

void ProgressBar::updateProgressBar(int progress, QString fileName){
    ui->progressBar->setValue(progress);
    ui->label->setText("Copying: "+fileName);
}
