#ifndef FILECOPYFUNCTIONS_H
#define FILECOPYFUNCTIONS_H

#include <QStringList>

class fileCopyFunctions
{
public:
    fileCopyFunctions();
    ~fileCopyFunctions();
    void recursiveCopy(QStringList sourceFiles, QString Destination);
    void normalCopy(QStringList sourceFiles, QString Destination);
};

#endif // FILECOPYFUNCTIONS_H
