#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QStringList>

class fileBrowser
{
public:
    fileBrowser();
    ~fileBrowser();
    QStringList getVideoFiles(QString usedFolder);
};

#endif // FILEBROWSER_H
