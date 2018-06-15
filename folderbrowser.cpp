#include "folderbrowser.h"
#include <QString>
#include <QStringList>
#include <QStandardPaths>
#include <QDir>

Folderbrowser::Folderbrowser(){
    //ctor
}

Folderbrowser::~Folderbrowser(){
    //dtor
}

QString Folderbrowser::getHomefolder(){
    folder = QStandardPaths::locate(QStandardPaths::HomeLocation,
                  QString(), QStandardPaths::LocateDirectory);
    return folder;
}

QString Folderbrowser::getLastfolder(){
    return folder;
}

QStringList Folderbrowser::folderContents(QString folder_){
    QDir path = QDir(folder_);
    path.setFilter(QDir::Dirs);

    return path.entryList();
}
