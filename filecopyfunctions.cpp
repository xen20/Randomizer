#include <QtShell> //Not stock library, provided by bennylau & his QtShell lib as found on github
#include <QRegularExpression>

#include "filecopyfunctions.h"

fileCopyFunctions::fileCopyFunctions(){
    fileCopyIndex = 1;
    fileIndex = 0;
    checkIfDuplicateInDest = false;
    doesDuplicateExistAfterAppendingIndex = false;
}

fileCopyFunctions::~fileCopyFunctions(){

}

void fileCopyFunctions::fileCopy(QStringList sourceFiles, QString Destination){

    QRegularExpression digitExtractingPattern("(\\d+)");

    for (int idx = 0; idx < sourceFiles.count(); ++idx){
        checkIfDuplicateInDest =   QFileInfo::exists(Destination+"/"+QtShell::basename(sourceFiles[idx])) && \
                                   QFileInfo(Destination+"/"+QtShell::basename(sourceFiles[idx])).isFile();

        if((checkIfDuplicateInDest) == true){

            fileNameAfterSplit   = QtShell::basename(sourceFiles[idx]).split(".");

            fileNameIfDuplicateExists = fileNameAfterSplit.join("-"+QString::number(fileCopyIndex)+".");
            destinationIfDuplicateExists = Destination+"/"+fileNameIfDuplicateExists;

            doesDuplicateExistAfterAppendingIndex = QFileInfo::exists(destinationIfDuplicateExists) && \
                                                        QFileInfo(destinationIfDuplicateExists).isFile();

            if(doesDuplicateExistAfterAppendingIndex == true){
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

                fileNameIfDuplicateExists = fileNameAfterSplit.join("-"+QString::number(fileCopyIndex)+".");
                destinationIfDuplicateExists = Destination+"/"+fileNameIfDuplicateExists;

                doesDuplicateExistAfterAppendingIndex = QFileInfo::exists(destinationIfDuplicateExists) && \
                                                            QFileInfo(destinationIfDuplicateExists).isFile();

                extractedDigits.clear();

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
