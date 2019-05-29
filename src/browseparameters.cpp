#include "browseparameters.h"

browseParameters::browseParameters(){
}

browseParameters::~browseParameters(){
    //dtor
}

QStringList browseParameters::getFileExtensions(QString fileType){

    if(fileType == "Videos"){
        this->fileExtensions << "*.ts" << "*.mp4" << "*.mkv" << "*.avi" << "*.rm" << "*.webm" << "*.flv";
    }
    else if (fileType == "Music") {
        this->fileExtensions << ".*mp3" << "*.m4a" << "*.ogg" << "*.wav" << "*.wma" << "*.flac";
    }
    else if (fileType == "Images") {
        this->fileExtensions << ".*jpeg" << "*.jpg" << "*.png" << "*.bmp";
    }
    else if (fileType == "Gifs") {
        this->fileExtensions << "*.gif";
    }

    return this->fileExtensions;
}
