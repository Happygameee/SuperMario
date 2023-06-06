
#ifndef UNKNOWN_H
#define UNKNOWN_H

#include <QVector>
#include <QMap>


class Unknown
{
public:
    Unknown();
    void UnknownInit();

    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
};

#endif // UNKNOWN_H
