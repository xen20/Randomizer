#ifndef folderRandomizer_H
#define folderRandomizer_H

#include <QStringList>

class folderRandomizer
{
public:
    folderRandomizer();
    ~folderRandomizer();
    QStringList returnRandomObjects(int numOfObjects, QStringList objects);
};

#endif // folderRandomizer_H
