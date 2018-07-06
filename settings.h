#ifndef SETTINGS_H
#define SETTINGS_H

#include "browseparameters.h"
#include <QMainWindow>

class guiSettings
{
public:
    guiSettings();
    ~guiSettings();
    void saveSettings(browseParameters &browseParameters_);
    void loadSettings(browseParameters &browseParameters_, QMainWindow &Ui);
    void adjustUI(browseParameters &browseParameters_, QMainWindow &Ui);
private:
    QString settingsFile;
};

#endif // SETTINGS_H
