#ifndef FOLDERBROWSER_H
#define FOLDERBROWSER_H

#include "browseparameters.h" //already includes <QStringList>

#include <QDir>

class folderBrowser
{
public:
    folderBrowser();
    ~folderBrowser();
    QString getHomefolder();
    QStringList folderContents(browseParameters &browseParameters_);
    QStringList returnDirectories(browseParameters &browseParameters_, QDir &currentPath);
    QStringList returnObjects(browseParameters &browseParameters_, QDir &currentPath);
};

#endif // FOLDERBROWSER_H
