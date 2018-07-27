#include <QDir>
#include <QtShell> //Not stock library, provided by bennylau & his QtShell lib as found on github

#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions()
{

}

fileCopyFunctions::~fileCopyFunctions(){

}

void fileCopyFunctions::fileCopy(QStringList sourceFiles, QString Destination){
    int  fileCopyIndex = 1;
    QDir folderAccessFunctions;

    QStringList fileNameAfterSplit;
    QString fileNameIfDuplicateExists;
    QString destinationIfDuplicateExists;

    for (int idx = 0; idx < sourceFiles.count(); ++idx){
        if(folderAccessFunctions.exists(sourceFiles[idx]) && folderAccessFunctions.exists(Destination+"/"+QtShell::basename(sourceFiles[idx]))){

            fileNameAfterSplit = QtShell::basename(sourceFiles[idx]).split(".");
            fileNameIfDuplicateExists = fileNameAfterSplit.join("-"+QString::number(fileCopyIndex)+".");



            destinationIfDuplicateExists = Destination+"/"+fileNameIfDuplicateExists;

            QtShell::cp("-vR", sourceFiles[idx], Destination+"/"+QtShell::basename(fileNameIfDuplicateExists));
        }
        else{
            QtShell::cp("-vR", sourceFiles[idx], Destination);
        }
    }
}

void fileCopyFunctions::folderCopy(QStringList sourceFiles, QString Destination){
    for(int idx = 0; idx < sourceFiles.count(); ++idx){
        QtShell::cp("-vR", sourceFiles[idx], Destination);
    }
}
