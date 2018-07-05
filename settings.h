#ifndef SETTINGS_H
#define SETTINGS_H

#include <QLabel>
#include <QLineEdit>

class guiSettings
{
public:
    guiSettings();
    ~guiSettings();
    void saveSettings();
    void loadSettings();
private:
    QString settingsFile;
    QString ziga;
};

#endif // SETTINGS_H
