#include <QDir>
#include <QtShell> //Not stock library, provided by bennylau & his QtShell lib as found on github

#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions()
{

}

fileCopyFunctions::~fileCopyFunctions(){

}

void fileCopyFunctions::recursiveCopy(QStringList sourceFiles, QString Destination){
    QDir folderAccessFunctions;

    QStringList fileNameAfterSplit;
    QString fileNameIfDuplicateExists;

    for (int idx = 0; idx < sourceFiles.count(); ++idx){
        if(folderAccessFunctions.exists(sourceFiles[idx])){
            fileNameAfterSplit = sourceFiles[idx].split(".");
            fileNameIfDuplicateExists = fileNameAfterSplit.join("-copy.");
            QtShell::cp("-vR", sourceFiles[idx], Destination+"/"+QtShell::basename(fileNameIfDuplicateExists));
        }
        else{
            QtShell::cp("-vR", sourceFiles[idx], Destination);
        }
    }
}
