#include <QtShell> //Not stock library, provided by bennylau & his QtShell lib as found on github
#include <QRegularExpression>

#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions(){
    fileCopyIndex = 1;
    fileIndex = 0;
    doesDuplicateFileExistInDest = false;
    doesDuplicateExistAfterAppendingIndex = false;
}

fileCopyFunctions::~fileCopyFunctions(){

}

void fileCopyFunctions::fileCopy(QStringList sourceFiles, QString Destination){

    for (int idx = 0; idx < sourceFiles.count(); ++idx){

        doesDuplicateFileExistInDest = checkIfDuplicateFileExistsInDest(sourceFiles[idx], Destination);

        if((doesDuplicateFileExistInDest) == true){

            destinationIfDuplicateExists = handleDuplicateFileName(sourceFiles[idx], Destination);

            doesDuplicateExistAfterAppendingIndex = checkIfDuplicateExistsAfterAppendingIndex();

            if(doesDuplicateExistAfterAppendingIndex == true){

                updateFileCopyIndex();

                destinationIfDuplicateExists = handleDuplicateFileName(sourceFiles[idx], Destination);

                doesDuplicateExistAfterAppendingIndex = checkIfDuplicateExistsAfterAppendingIndex();

                if(doesDuplicateExistAfterAppendingIndex){
                    --idx;
                    continue;
                }
            }
            QtShell::cp("-vR", sourceFiles[idx], destinationIfDuplicateExists);
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

bool fileCopyFunctions::checkIfDuplicateExistsAfterAppendingIndex(){
    bool doesDuplicateExistAfterAppendingIndex_ = false;

    doesDuplicateExistAfterAppendingIndex_ = QFileInfo::exists(destinationIfDuplicateExists) && \
                                                QFileInfo(destinationIfDuplicateExists).isFile();

    return doesDuplicateExistAfterAppendingIndex_;
}

bool fileCopyFunctions::checkIfDuplicateFileExistsInDest(QString sourceFile, QString Destination_){
    bool doesDuplicateFileExistInDest_ = false;

    doesDuplicateFileExistInDest_ =   QFileInfo::exists(Destination_+"/"+QtShell::basename(sourceFile)) && \
                                      QFileInfo(Destination_+"/"+QtShell::basename(sourceFile)).isFile();

    return doesDuplicateFileExistInDest_;
}

QString fileCopyFunctions::handleDuplicateFileName(QString sourceFile, QString Destination_){
    QString destinationIfDuplicateExists_;
    fileNameAfterSplit = QtShell::basename(sourceFile).split(".");

    fileNameIfDuplicateExists = fileNameAfterSplit.join("-"+QString::number(fileCopyIndex)+".");
    destinationIfDuplicateExists_ = Destination_+"/"+fileNameIfDuplicateExists;

    return destinationIfDuplicateExists_;
}

void fileCopyFunctions::updateFileCopyIndex(){

    QRegularExpression digitExtractingPattern("(\\d+)");

    QRegularExpressionMatchIterator digitsInDestinationPath = \
            digitExtractingPattern.globalMatch(destinationIfDuplicateExists);

    while(digitsInDestinationPath.hasNext()){
        QRegularExpressionMatch matchedtDigit = digitsInDestinationPath.next();
        QString currentDigit = matchedtDigit.captured(1);
        extractedDigits << currentDigit;
    }

    if(extractedDigits.count() == 1){
        fileIndex = extractedDigits.count();
    }
    else if(extractedDigits.count() > 1 ){
        fileIndex = extractedDigits.count()-1;
    }

    fileCopyIndex = extractedDigits[fileIndex-1].toInt()+1;

    extractedDigits.clear();
}
