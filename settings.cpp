#include "settings.h"

#include <QSettings>
#include <QApplication>
#include <QCoreApplication>

guiSettings::guiSettings(){
    settingsFile = QApplication::applicationDirPath() + "/appsettings.ini";
}

guiSettings::~guiSettings(){

}

void guiSettings::loadSettings(browseParameters &browseParameters_){
    QSettings appSettings(settingsFile, QSettings::NativeFormat);

    browseParameters_.selectedDirectory = appSettings.value("LastParameters/LastDirectory", "/").toString();
    browseParameters_.objectType = appSettings.value("LastParameters/LastObjectType", "Directories").toString();
    browseParameters_.objectCount = appSettings.value("LastParameters/LastObjectCount", 1).toInt();
    browseParameters_.recursiveOrNot = appSettings.value("LastParameters/Recursive", false).toBool();
    browseParameters_.absoluteOrNot  = appSettings.value("LastParameters/AbsolutePaths", false).toBool();

}

void guiSettings::saveSettings(browseParameters &browseParameters_){
    QSettings appSettings(settingsFile, QSettings::NativeFormat);

    appSettings.setValue("LastParameters/LastDirectory", browseParameters_.selectedDirectory);
    appSettings.setValue("LastParameters/LastObjectType", browseParameters_.objectType);
    appSettings.setValue("LastParameters/LastObjectCount", browseParameters_.objectCount);
    appSettings.setValue("LastParameters/Recursive", browseParameters_.recursiveOrNot);
    appSettings.setValue("LastParameters/AbsolutePaths", browseParameters_.absoluteOrNot);

}
