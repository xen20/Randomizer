#include <QDir>
#include <QtShell> //Not stock library, provided by bennylau & his QtShell lib as found on github

#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions()
{

}

fileCopyFunctions::~fileCopyFunctions(){

}

void fileCopyFunctions::recursiveCopy(QStringList sourceFiles, QString Destination){
    for (int idx = 0; idx < sourceFiles.count(); ++idx){
        QtShell::cp("-vR", sourceFiles[idx], Destination);
    }
}
