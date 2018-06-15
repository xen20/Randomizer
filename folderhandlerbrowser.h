#ifndef FOLDERHANDLERBROWSER_H
#define FOLDERHANDLERBROWSER_H

#include <QString>


class Folderhandlerbrowser
{
public:
    Folderhandlerbrowser();
    void acquireFolder();
    void modifyDefaultFolder();
private:
    QString defaultFolder;
    QString selectedFolder;
};

#endif // FOLDERHANDLERBROWSER_H
