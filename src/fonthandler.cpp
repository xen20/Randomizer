#include "fonthandler.h"

#include <QApplication>
#include <QFontDatabase>

fontHandler::fontHandler(){

}

fontHandler::~fontHandler(){

}

void fontHandler::loadFontFromResources(QString selectedFont){

    QFontDatabase::addApplicationFont(":/fonts/"+selectedFont+".ttf");
}

void fontHandler::setGlobalFont(QString selectedFont, int selectedFontSize){

    this->loadFontFromResources(selectedFont);
    QFont selectedFontHandler(selectedFont);
    selectedFontHandler.setPixelSize(selectedFontSize);

    QApplication::setFont(selectedFontHandler);
}
