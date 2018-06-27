#ifndef FOLDERBROWSER_H
#define FOLDERBROWSER_H

#include "browseparameters.h" //already includes <QStringList>

class folderBrowser
{
public:
    folderBrowser();
    ~folderBrowser();
    QString getHomefolder();
    QString getDocumentsfolder();
    QStringList folderContents(browseParameters &browseParameters_);
private:
    QStringList getDirectories();
    QStringList getVideos();
    QStringList getMusic();
};

#endif // FOLDERBROWSER_H
