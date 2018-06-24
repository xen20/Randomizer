#ifndef FOLDERHISTORY_H
#define FOLDERHISTORY_H

#include <QStringList>

class folderHistory
{
public:
    folderHistory(QStringList currentObjects);
    folderHistory();
    ~folderHistory();
    void readHistory();
    void writeHistory(QStringList randomlyGeneratedFolders);
    void clearHistory();
    QStringList compareNewAndOldFolders();
private:
    QStringList folderContents;
    QStringList oldFolders;
    QStringList newFolders;
    QString currentLine;
    QString resultFilePath;
};

#endif // FOLDERHISTORY_H
