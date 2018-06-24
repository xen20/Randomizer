#include "filebrowser.h"
#include <QStringList>
#include <QDir>


fileBrowser::fileBrowser(){
    //ctor
}

fileBrowser::~fileBrowser(){
    //dtor
}

QStringList fileBrowser::getVideoFiles(QString usedFolder){
    QDir path = QDir(usedFolder);
    QStringList videoFileTypes;
    videoFileTypes << "*ts" << "*.mp4" << "*.mkv" << "*.avi" << "*.rm";

    path.setFilter(QDir::Files);
    path.setNameFilters(videoFileTypes);

    return path.entryList();
}
