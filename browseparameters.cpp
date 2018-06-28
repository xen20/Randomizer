#include "browseparameters.h"

browseParameters::browseParameters(){
    selectedDirectory = "";
    objectType = "Directories";
    recursiveOrNot =  false;
    absoluteOrNot = false;
}

browseParameters::~browseParameters(){
    //dtor
}
