#include <QRegularExpression>
#include <QFile>
#include <QApplication>


#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions(ProgressBar *progressBarWidget, MessageDialog *messageDialogWidget){
    copyProgress = 0;
    fileCopyIndex = 1;
    doesDuplicateFileExistInDest = false;
    doesDuplicateExistAfterAppendingIndex = false;
    _progressBarWidget = progressBarWidget;
    _messageDialogWidget = messageDialogWidget;
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
            if(QFile::exists(sourceFiles[idx])){
                QFile::copy(sourceFiles[idx], destinationIfDuplicateExists);
                fileCopyIndex = 1;
                ++copyProgress;
                float totalProgess = ((float)copyProgress/sourceFiles.size())*100; // Cast to force float division
                _progressBarWidget->updateProgressBar(totalProgess, QFileInfo(sourceFiles[idx]).fileName());
                qApp->processEvents();
            }
        }
        else{
            if(QFile::exists(sourceFiles[idx])){
                QFile::copy(sourceFiles[idx], Destination+"/"+QFileInfo(sourceFiles[idx]).fileName());
                ++copyProgress;
                float totalProgess = ((float)copyProgress/sourceFiles.size())*100;
                _progressBarWidget->updateProgressBar(totalProgess, QFileInfo(sourceFiles[idx]).fileName());
                qApp->processEvents();
            }
        }
    }
}

void fileCopyFunctions::folderCopy(QStringList sourceFiles, QString Destination){
    //WIP
    for(int idx = 0; idx < sourceFiles.count(); ++idx){
    }
}

bool fileCopyFunctions::checkIfDuplicateFileExistsInDest(QString sourceFile, QString Destination_){
    bool doesDuplicateFileExistInDest_ = false;

    doesDuplicateFileExistInDest_ =   QFileInfo::exists(Destination_+"/"+QFileInfo(sourceFile).fileName()) && \
            QFileInfo(Destination_+"/"+QFileInfo(sourceFile).fileName()).isFile();

    return doesDuplicateFileExistInDest_;
}

bool fileCopyFunctions::checkIfDuplicateExistsAfterAppendingIndex(){
    bool doesDuplicateExistAfterAppendingIndex_ = false;

    doesDuplicateExistAfterAppendingIndex_ = QFileInfo::exists(destinationIfDuplicateExists) && \
            QFileInfo(destinationIfDuplicateExists).isFile();

    return doesDuplicateExistAfterAppendingIndex_;
}

QString fileCopyFunctions::handleDuplicateFileName(QString sourceFile, QString Destination_){
    QString destinationIfDuplicateExists_;
    fileNameAfterSplit = QFileInfo(sourceFile).fileName().split(".");

    fileNameIfDuplicateExists = fileNameAfterSplit.join("-"+QString::number(fileCopyIndex)+".");
    destinationIfDuplicateExists_ = Destination_+"/"+fileNameIfDuplicateExists;

    return destinationIfDuplicateExists_;
}

void fileCopyFunctions::updateFileCopyIndex(){

    QRegularExpression digitExtractingPattern("(\\d+)\\.");
    int fileIndex = 0;

    QRegularExpressionMatchIterator digitsInDestinationPath = \
            digitExtractingPattern.globalMatch(destinationIfDuplicateExists);

    while(digitsInDestinationPath.hasNext()){
        QRegularExpressionMatch matchedtDigit = digitsInDestinationPath.next();
        QString currentDigit = matchedtDigit.captured(1);
        extractedDigits << currentDigit;
    }

    fileIndex = extractedDigits.count();

    fileCopyIndex = extractedDigits[fileIndex-1].toInt()+1;

    extractedDigits.clear();
}
