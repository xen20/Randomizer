#include "folderhandlerbrowser.h"
#include <QString>
#include <QFileDialog>
#include <QObject>

Folderhandlerbrowser::Folderhandlerbrowser()
{

}

void Folderhandlerbrowser::acquireFolder(){
    selectedFolder = QFileDialog::getOpenFileName(this, QObject::tr("Open Image"), "/C:/",
                            QObject::tr("Image Files (*.png *.jpg *.bmp)"));
}

void Folderhandlerbrowser::modifyDefaultFolder(){

}
