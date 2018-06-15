#ifndef FOLDERHISTORY_H
#define FOLDERHISTORY_H

#include <QStringList>

class folderHistory
{
public:
    folderHistory(QStringList currentObjects, QString folderPath);
    folderHistory(QString folderPath);
    ~folderHistory();
    void readHistory();
    void writeHistory(QStringList randomlyGeneratedFolders);
    void clearHistory();
    QStringList compareNewOld();
private:
    QStringList folderContents;
    QStringList oldFolders;
    QStringList newFolders;
    QString currentLine;
    QString folderPath_;
};

#endif // FOLDERHISTORY_H
