#include <QDir>

#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions()
{

}

fileCopyFunctions::~fileCopyFunctions(){

}

void fileCopyFunctions::recursiveCopy(QStringList sourceFiles, QString Destination){

    for(int i = 0; i< sourceFiles.count(); i++) {
        QString srcName =  sourceFiles[i];
        QString destName = Destination + QDir::separator() + sourceFiles[i];
        QFile::copy(srcName, destName);
    }

//    sourceFiles.clear();
//    files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
//    for(int i = 0; i< files.count(); i++)
//    {
//        QString srcName = sourceFolder + QDir::separator() + files[i];
//        QString destName = destFolder + QDir::separator() + files[i];
//        success = copyRecursively(srcName, destName);
//        if(!success)
//            return false;
//    }
}

void fileCopyFunctions::normalCopy(QStringList sourceFiles, QString Destination){

}
