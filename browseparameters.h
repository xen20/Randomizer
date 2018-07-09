#ifndef BROWSEPARAMETERS_H
#define BROWSEPARAMETERS_H

#include <QString>


class browseParameters
{
public:
    browseParameters();
    ~browseParameters();
    QString selectedDirectory;
    QString objectType;
    int  objectCount;
    bool recursiveOrNot;
    bool absoluteOrNot;
};

#endif // BROWSEPARAMETERS_H
