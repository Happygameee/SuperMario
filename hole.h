
#ifndef HOLE_H
#define HOLE_H

#include <QVector>
#include <QMap>


class Hole
{
public:
    Hole();
    void HoleInit();

    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
};

#endif // HOLE_H
