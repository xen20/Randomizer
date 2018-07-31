#ifndef FILECOPYFUNCTIONS_H
#define FILECOPYFUNCTIONS_H

#include <QStringList>
#include <QFileInfo>

class fileCopyFunctions
{
public:
    fileCopyFunctions();
    ~fileCopyFunctions();
    void fileCopy(QStringList sourceFiles, QString Destination);
    void folderCopy(QStringList sourceFiles, QString Destination);
    QString handleFilePathFunctions(QStringList sourceFiles, QString Destination);
    bool checkIfDuplicateExistsAfterAppendingIndex();

private:
    /*in use by fileCopy function*/
    int  fileCopyIndex;
    int  fileIndex;
    QStringList fileNameAfterSplit;
    QStringList extractedDigits;
    QString fileNameIfDuplicateExists;
    QString destinationIfDuplicateExists;
    bool checkIfDuplicateInDest;
    bool doesDuplicateExistAfterAppendingIndex;
    /*in use by filyCopy function*/
};
#endif // FILECOPYFUNCTIONS_H
