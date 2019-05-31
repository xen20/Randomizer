#ifndef folderRandomizer_H
#define folderRandomizer_H

#include <QStringList>
#include "messagedialog.h"

class folderRandomizer
{
public:
    folderRandomizer();
    folderRandomizer(MessageDialog *messageDialogWidget);
    ~folderRandomizer();
    QStringList returnRandomObjects(int numOfObjects, QStringList objects);
private:
    MessageDialog *_messageDialogWidget;
};

#endif // folderRandomizer_H
