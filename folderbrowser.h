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
    QString getDocumentsfolder();
    QStringList folderContents(browseParameters &browseParameters_);
private:
    QStringList getDirectories(browseParameters &browseParameters_, QDir &currentPath);
    QStringList getVideos(browseParameters &browseParameters_, QDir &currentPath);
    QStringList getMusic(browseParameters &browseParameters_, QDir &currentPath);
};

#endif // FOLDERBROWSER_H
