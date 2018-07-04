#ifndef SETTINGS_H
#define SETTINGS_H

#include <QLabel>
#include <QLineEdit>

class settings
{
public:
    settings();
    ~settings();
    void saveSettings();
    void loadSettings();
};

#endif // SETTINGS_H
