#ifndef FILECOPYFUNCTIONS_H
#define FILECOPYFUNCTIONS_H

#include <QStringList>

class fileCopyFunctions
{
public:
    fileCopyFunctions();
    ~fileCopyFunctions();
    void fileCopy(QStringList sourceFiles, QString Destination);
    void folderCopy(QStringList sourceFiles, QString Destination);
};

#endif // FILECOPYFUNCTIONS_H
