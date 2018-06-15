#ifndef FOLDERBROWSER_H
#define FOLDERBROWSER_H

#include <QString>
#include <QDir>
#include <QStringList>

class Folderbrowser
{
public:
    Folderbrowser();
    ~Folderbrowser();
    QString browseFolder();
    QString getHomefolder();
    QString getLastfolder();
    QStringList folderContents(QString folder_);
private:
    QString folder;
};

#endif // FOLDERBROWSER_H
