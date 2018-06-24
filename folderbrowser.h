#ifndef FOLDERBROWSER_H
#define FOLDERBROWSER_H

#include <QString>
#include <QDir>
#include <QStringList>

class folderBrowser
{
public:
    folderBrowser();
    ~folderBrowser();
    QString browseFolder();
    QString getHomefolder();
    QString getDocumentsfolder();
    QStringList folderContents(QString folder, bool recursiveOrNot, bool absoluteOrNot);
private:
    QString folder;
};

#endif // FOLDERBROWSER_H
