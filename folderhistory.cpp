#include "folderhistory.h"

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QApplication>

folderHistory::folderHistory(QStringList folderContents){

    newFolders = folderContents;
    programRootFolder = QApplication::applicationDirPath();
    resultFileFolder = "/results";
    resultFilePath = programRootFolder + resultFileFolder + "/results.txt";
}

folderHistory::folderHistory(){

    programRootFolder = QApplication::applicationDirPath();
    resultFileFolder = "/results";
    resultFilePath = programRootFolder + resultFileFolder + "/results.txt";
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

    QDir pathHandler;

    if(!(pathHandler.exists(resultFilePath))){
        pathHandler.mkdir(programRootFolder+resultFileFolder);
    }

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
