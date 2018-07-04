#include "gifplayer.h"

#include <QMovie>
#include <QLabel>
#include <QDebug>

gifPlayer::gifPlayer(){

}

gifPlayer::~gifPlayer(){

}

void gifPlayer::playGif(){
    QLabel gifPlayer;
    QMovie *gifPointer = new QMovie("/home/osboxes/ownrepos/Randomizer/test.gif");

    if(!gifPointer->isValid()){
        qDebug("fucktown\n");
    }

    gifPlayer.setMovie(gifPointer);

    gifPointer->start();
}
