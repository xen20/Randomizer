#include "folderbrowser.h"

#include <QStandardPaths>
#include <QDirIterator>   //includes <QDir> as well

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

QString folderBrowser::getDocumentsfolder(){
    QString docFolder = QStandardPaths::locate(QStandardPaths::HomeLocation,
                  QString(), QStandardPaths::LocateDirectory);
    return docFolder;
}

QStringList folderBrowser::folderContents(browseParameters &browseParameters_){
    QDir currentPath = QDir(browseParameters_.selectedDirectory);
    QStringList objectsRetrieved;

    if(browseParameters_.objectType == "Directories"){
        objectsRetrieved = this->getDirectories(browseParameters_, currentPath);
    }

    return objectsRetrieved;
}

QStringList folderBrowser::getDirectories(browseParameters &browseParameters_, QDir &currentPath){

    QStringList foldersRetrieved;
    currentPath.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    if(browseParameters_.recursiveOrNot == false){
        foldersRetrieved = currentPath.entryList();
    }
    else if(browseParameters_.recursiveOrNot == true){
        QDirIterator iter(currentPath, QDirIterator::Subdirectories);

        while(iter.hasNext()){
            foldersRetrieved << iter.next();
        }
    }

    return foldersRetrieved;
}

QStringList folderBrowser::getVideos(browseParameters &browseParameters_, QDir &currentPath){
    QStringList videoFileTypes;
    QStringList videosRetrieved;
    videoFileTypes << "*ts" << "*.mp4" << "*.mkv" << "*.avi" << "*.rm";

    currentPath.setFilter(QDir::Files);
    currentPath.setNameFilters(videoFileTypes);

    if(browseParameters_.recursiveOrNot)

    return path.entryList();
}
