#ifndef FILECOPYFUNCTIONS_H
#define FILECOPYFUNCTIONS_H

#include <QStringList>
#include <QFileInfo>
#include "progressbar.h"

class fileCopyFunctions
{
public:
    fileCopyFunctions(ProgressBar *widget);
    ~fileCopyFunctions();
    void fileCopy(QStringList sourceFiles, QString Destination);
    void folderCopy(QStringList sourceFiles, QString Destination);

private:
    void updateFileCopyIndex();
    bool checkIfDuplicateExistsAfterAppendingIndex();
    bool checkIfDuplicateFileExistsInDest(QString sourceFile, QString Destination_);
    QString handleDuplicateFileName(QString sourceFile, QString Destination_);
    int     copyProgress;
    /*in use by fileCopy function*/
    int  fileCopyIndex;
    QStringList fileNameAfterSplit;
    QStringList extractedDigits;
    QString fileNameIfDuplicateExists;
    QString destinationIfDuplicateExists;
    bool doesDuplicateFileExistInDest;
    bool doesDuplicateExistAfterAppendingIndex;
    ProgressBar *_widget;
    /*in use by fileCopy function*/

};
#endif // FILECOPYFUNCTIONS_H
