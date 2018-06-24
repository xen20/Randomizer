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

QStringList folderBrowser::folderContents(QString folder, bool recursiveOrNot, bool absoluteOrNot){
    QDir path = QDir(folder);
    path.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList  foldersRetrieved;

    if(recursiveOrNot == false){
        foldersRetrieved = path.entryList();
    }
    else if(recursiveOrNot == true){
        QDirIterator iter(path, QDirIterator::Subdirectories);

        while(iter.hasNext()){
            foldersRetrieved << iter.next();
        }
    }

    return foldersRetrieved;
}
