#include <QRegularExpression>
#include <QFile>
#include <QApplication>

#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QException>

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

void fileCopyFunctions::folderCopy(QStringList sourceFiles, QString Source, QString Destination){

    //this is the base directory to which all the others will be copied
    QDir sourceDir(Source); //static
    QString sourceDirName =  sourceDir.dirName(); //static

    QRegularExpression matchOnlySubdirs("\\(?:.(?!\\))+$");

    for(int idx = 0; idx < sourceFiles.count(); ++idx){

        // Get single dir
        // Get all files within selected single dir (recursive, includes also sub-folders)
        // make base dir and cd to it
        // from fllepath, remove all directory data before base directory, that is the new path for that file,
        // as it is basedir/filepathWithRemovedstart, qdir.mkpath to get all the parent dirs as well
        // iterate over files: one by one, copy files to dest using QFile.copy

        QDir currentDir(sourceFiles[idx]); //dynamic
        currentDir.setFilter( QDir::Files | QDir::Dirs | QDir::Hidden | QDir::NoSymLinks | QDir::NoDotAndDotDot);

        QDirIterator iter(currentDir, QDirIterator::Subdirectories); //dynamic
        QFileInfo currentFile;
        QString currentFilePath;
        QString currentPath;

        // Consider removing this "if" condition...
        if (QDir(Destination).isReadable()){
            try {
                while(iter.hasNext()){
                    currentFile = iter.next();
                    currentFilePath = currentFile.filePath();
                    currentPath = currentFile.path();

                    currentPath.replace(sourceDir.path(), "");

                    currentPath = Destination+"/"+sourceDirName+currentPath+"/";
                    currentDir.mkpath(currentPath);
                    currentFilePath = currentPath+currentFile.fileName();

                    QFile::copy(iter.next(), currentFilePath);
                }
            } catch (QException e) {
                qDebug() << e.what(); // make it a dialog later?
            }
        }
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
