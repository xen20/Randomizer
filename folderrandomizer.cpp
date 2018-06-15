#include "folderRandomizer.h"

folderRandomizer::folderRandomizer()
{
    //ctor
}

folderRandomizer::~folderRandomizer(){
    //dtor
}

QStringList folderRandomizer::returnRandomObjects(int numOfObjects, QStringList objects){

    int randomFolderRange = objects.length(); //0 to amount of folders in initial list
    QStringList randomlySelectedFolders;

    if((randomFolderRange == 0) || (numOfObjects == 0 )){
        randomlySelectedFolders.clear();
        return randomlySelectedFolders;
    }
    else{
        for(int idx = 0; idx < numOfObjects; idx++){
            int randomFolder = qrand() % randomFolderRange;
            if(!randomlySelectedFolders.contains(objects[randomFolder])){
                randomlySelectedFolders.append(objects[randomFolder]);
            }
            else if(objects.length() % numOfObjects){
                break;
            }
            else{
                idx--;
                continue;
            }
        }
        return randomlySelectedFolders;
        randomlySelectedFolders.clear();
    }
}
