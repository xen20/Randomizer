#include "folderbrowser.h"
#include <QStringList>
#include <QStandardPaths>
#include <QDir>
#include <QDirIterator>

folderBrowser::folderBrowser(){
    //ctor
}

folderBrowser::~folderBrowser(){
    //dtor
}

QString folderBrowser::getHomefolder(){
    folder = QStandardPaths::locate(QStandardPaths::HomeLocation,
                  QString(), QStandardPaths::LocateDirectory);
    return folder;
}

QString folderBrowser::getDocumentsfolder(){
    QString docFolder = QStandardPaths::locate(QStandardPaths::HomeLocation,
                  QString(), QStandardPaths::LocateDirectory);
    return docFolder;
}

QStringList folderBrowser::folderContents(QString folder_){
    QDir path = QDir(folder_);
    path.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    return path.entryList();
}

QStringList folderBrowser::folderContentsWithSubdirectories(QString folder_){
    QDir path = QDir(folder_);
    path.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
}
