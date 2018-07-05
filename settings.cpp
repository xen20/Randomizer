#include "settings.h"

#include <QSettings>
#include <QApplication>
#include <QCoreApplication>

guiSettings::guiSettings(){
    settingsFile = QApplication::applicationDirPath().left(1) + ":/appsettings.ini";
}

guiSettings::~guiSettings(){

}

void guiSettings::loadSettings(){
    settingsFile = QApplication::applicationDirPath().left(1) + "appsettings.ini";
    QSettings appSettlings(settingsFile, QSettings::NativeFormat);
    QString loadedText = appSettlings.value("text", "").toString();
}

void guiSettings::saveSettings(){
    QSettings appSettlings(settingsFile, QSettings::NativeFormat);
    appSettlings.setValue("text", "text");
}
