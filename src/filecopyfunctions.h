#ifndef FILECOPYFUNCTIONS_H
#define FILECOPYFUNCTIONS_H

#include <QStringList>
#include <QFileInfo>
#include "progressbar.h"
#include "messagedialog.h"

class fileCopyFunctions
{
public:
    fileCopyFunctions(ProgressBar *progressBarWidget, MessageDialog *messageDialogWidget);
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
    ProgressBar *_progressBarWidget;
    MessageDialog *_messageDialogWidget;
    /*in use by fileCopy function*/

};
#endif // FILECOPYFUNCTIONS_H
