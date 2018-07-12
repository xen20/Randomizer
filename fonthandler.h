#ifndef FONTHANDLER_H
#define FONTHANDLER_H

#include <QString>

class fontHandler
{
public:
    fontHandler();
    ~fontHandler();
    void setGlobalFont(QString selectedFont, int selectedFontSize);
private:
    void loadFontFromResources(QString selectedFont);
};

#endif // FONTHANDLER_H
