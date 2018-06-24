#include "folderhistory.h"
#include "folderbrowser.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStandardPaths>

folderHistory::folderHistory(QStringList folderContents){
    newFolders = folderContents;
    folderBrowser browseDir;
    resultFilePath = browseDir.getDocumentsfolder();
    QString finalPath = resultFilePath.append("test.txt");
}

folderHistory::folderHistory(){
    folderBrowser browseDir;
    resultFilePath = browseDir.getDocumentsfolder();
    QString finalPath = resultFilePath.append("test.txt");
}

folderHistory::~folderHistory(){
    //dtor
}

void folderHistory::readHistory(){
    QFile filehandle(resultFilePath);
    filehandle.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream filestream(&filehandle);

    while(!filestream.atEnd()){
        currentLine = filestream.readLine();
        oldFolders.append(currentLine);
    }
    filehandle.close();
}

void folderHistory::writeHistory(QStringList randomlyGeneratedFolders){
    QFile filehandle(resultFilePath);
    filehandle.open(QIODevice::Append | QIODevice::Text);
    QTextStream filestream(&filehandle);
    QStringList::const_iterator iter;

    for (iter = randomlyGeneratedFolders.constBegin(); iter != randomlyGeneratedFolders.constEnd(); ++iter){
        filestream << *iter << "\n";
    }
    filehandle.close();
}

QStringList folderHistory::compareNewAndOldFolders(){
    int index = 0;
    while((oldFolders.size() > 0) && (index < oldFolders.size())){
        if(newFolders.contains(oldFolders[index])){
            newFolders.removeOne(oldFolders[index]);
            index++;
        }
        else{
            index++;
        }
    }

    return newFolders;
}

void folderHistory::clearHistory(){
    QFile filehandle(resultFilePath);
    filehandle.open(QIODevice::WriteOnly | QIODevice::Truncate);
    filehandle.close();
}
