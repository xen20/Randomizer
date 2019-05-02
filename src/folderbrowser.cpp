#include "folderbrowser.h"

#include <QStandardPaths>
#include <QDirIterator>

folderBrowser::folderBrowser(){
    //ctor
}

folderBrowser::~folderBrowser(){
    //dtor
}

QString folderBrowser::getHomefolder(){

    QString homeFolder;
    homeFolder = QStandardPaths::locate(QStandardPaths::HomeLocation,
                  QString(), QStandardPaths::LocateDirectory);
    return homeFolder;
}

QStringList folderBrowser::folderContents(browseParameters &browseParameters_){

    QDir currentPath = QDir(browseParameters_.selectedDirectory);
    QStringList objectsRetrieved;

    if(browseParameters_.objectType == "Directories"){
        objectsRetrieved = this->returnDirectories(browseParameters_, currentPath);
    }
    else{
        objectsRetrieved = this->returnObjects(browseParameters_, currentPath);
    }

    return objectsRetrieved;
}

QStringList folderBrowser::returnDirectories(browseParameters &browseParameters_, QDir &currentPath){

    QStringList foldersRetrieved;
    currentPath.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    if(browseParameters_.recursiveOrNot == false){
        QDirIterator iter(currentPath, QDirIterator::NoIteratorFlags);

        while(iter.hasNext()){
            foldersRetrieved << iter.next();
        }
    }
    else if(browseParameters_.recursiveOrNot == true){
        QDirIterator iter(currentPath, QDirIterator::Subdirectories);

        while(iter.hasNext()){
            foldersRetrieved << iter.next();
        }
    }

    return foldersRetrieved;
}

QStringList folderBrowser::returnObjects(browseParameters &browseParameters_, QDir &currentPath){

    QStringList objectFileTypes;
    QStringList objectsRetrieved;

    objectFileTypes = this->getObjectType(browseParameters_);

    currentPath.setFilter(QDir::Files);
    currentPath.setNameFilters(objectFileTypes);

    if(browseParameters_.recursiveOrNot == false){
        QDirIterator iter(currentPath, QDirIterator::NoIteratorFlags);

        while(iter.hasNext()){
            objectsRetrieved << iter.next();
        }
    }
    else if(browseParameters_.recursiveOrNot == true){
        QDirIterator iter(currentPath, QDirIterator::Subdirectories);

        while(iter.hasNext()){
            objectsRetrieved << iter.next();
        }
    }

    return objectsRetrieved;
}

QStringList folderBrowser::getObjectType(browseParameters &browseParameters_){

    QStringList objectFileTypes;

    if(browseParameters_.objectType == "Videos"){
        objectFileTypes << "*.ts" << "*.mp4" << "*.mkv" << "*.avi" << "*.rm" << "*.webm" << "*.flv";
    }
    else if (browseParameters_.objectType == "Music") {
        objectFileTypes << ".*mp3" << "*.m4a" << "*.ogg" << "*.wav" << "*.wma" << "*.flac";
    }
    else if (browseParameters_.objectType == "Images") {
        objectFileTypes << ".*jpeg" << "*.jpg" << "*.png" << "*.bmp";
    }

    return objectFileTypes;
}
