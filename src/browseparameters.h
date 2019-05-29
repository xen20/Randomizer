#ifndef BROWSEPARAMETERS_H
#define BROWSEPARAMETERS_H

#include <QStringList>

class browseParameters
{
public:
    browseParameters();
    ~browseParameters();
    QString selectedDirectory;
    QString copyTargetDirectory;
    QString objectType;
    int  objectCount;
    bool recursiveOrNot;
    QStringList getFileExtensions(QString fileType);
private:
    QStringList fileExtensions;
};

#endif // BROWSEPARAMETERS_H
