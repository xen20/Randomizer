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
    QString racist = "nigger";
    racist.split("." );
    for (int idx = 0; idx < sourceFiles.count(); ++idx){
        if(folderAccessFunctions.exists(sourceFiles[idx])){

            QtShell::cp("-vR", sourceFiles[idx], Destination+"/"+QtShell::basename(sourceFiles[idx])+"-copy");
        }
        else{
            QtShell::cp("-vR", sourceFiles[idx], Destination);
        }
    }
}
