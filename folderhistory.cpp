#include "folderhistory.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

folderHistory::folderHistory(QStringList folderContents, QString folderPath){
    newFolders = folderContents;
    folderPath_ = folderPath;
}

folderHistory::folderHistory(QString folderPath){
    folderPath_= folderPath;
}

folderHistory::~folderHistory(){
    //dtor
}

void folderHistory::readHistory(){
    QFile filehandle(folderPath_);
    filehandle.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream filestream(&filehandle);

    while(!filestream.atEnd()){
        currentLine = filestream.readLine();
        oldFolders.append(currentLine);
    }
    filehandle.close();
}

void folderHistory::writeHistory(QStringList randomlyGeneratedFolders){
    QFile filehandle(folderPath_);
    filehandle.open(QIODevice::Append | QIODevice::Text);
    QTextStream filestream(&filehandle);
    QStringList::const_iterator iter;

    for (iter = randomlyGeneratedFolders.constBegin(); iter != randomlyGeneratedFolders.constEnd(); ++iter){
        filestream << *iter << "\n";
    }
    filehandle.close();
}

QStringList folderHistory::compareNewOld(){
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
    QFile filehandle(folderPath_);
    filehandle.open(QIODevice::WriteOnly | QIODevice::Truncate);
    filehandle.close();
}
