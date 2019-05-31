#include "folderrandomizer.h"

#include <QRandomGenerator> //true random number generator

folderRandomizer::folderRandomizer()
{
    //default ctor
    _messageDialogWidget = NULL;
}

folderRandomizer::folderRandomizer(MessageDialog *messageDialogWidget){
    _messageDialogWidget = messageDialogWidget;
}

folderRandomizer::~folderRandomizer(){
}

QStringList folderRandomizer::returnRandomObjects(int numOfObjects, QStringList objects){

    int randomObjectMax = objects.length(); // range is 0 to amount of folders in initial list
    QStringList randomlySelectedFolders;

    if((randomObjectMax == 0) || (numOfObjects == 0 )){
        _messageDialogWidget->displayErrorMessage("There are no objects to randomize, choose another source directory.");
    }
    else{
        if(numOfObjects > objects.length()) numOfObjects = objects.length();

        while(randomlySelectedFolders.length() != numOfObjects){
            quint32 randomBase = QRandomGenerator::global()->bounded(0, randomObjectMax);
            int randomFolder = randomBase % randomObjectMax;
            if(!randomlySelectedFolders.contains(objects[randomFolder])){
                randomlySelectedFolders.append(objects[randomFolder]);
            }
        }
    }

    return randomlySelectedFolders;
}
