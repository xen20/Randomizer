#include "folderrandomizer.h"

#include <QRandomGenerator> //true random number generator

folderRandomizer::folderRandomizer()
{
    //ctor
}

folderRandomizer::~folderRandomizer(){
    //dtor
}

QStringList folderRandomizer::returnRandomObjects(int numOfObjects, QStringList objects){

    int randomFolderRange = objects.length(); // range is 0 to amount of folders in initial list
    QStringList randomlySelectedFolders;

    if((randomFolderRange == 0) || (numOfObjects == 0 )){
        randomlySelectedFolders.clear();
        return randomlySelectedFolders;
    }
    else{
        for(int idx = 0; idx < numOfObjects; ++idx){
            quint32 randomBase = QRandomGenerator::global()->generate();
            int randomFolder = randomBase % randomFolderRange;
            if(!randomlySelectedFolders.contains(objects[randomFolder])){
                randomlySelectedFolders.append(objects[randomFolder]);
            }
            else if(objects.length() % numOfObjects){
                break;
            }
            else{
                --idx;
                continue;
            }
        }
        return randomlySelectedFolders;

        randomlySelectedFolders.clear();
    }
}
