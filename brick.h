
#ifndef BRICK_H
#define BRICK_H

#include <QVector>
#include <QMap>

class Brick
{
public:
    Brick();
    void BrickInit();

    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
};

#endif // BRICK_H
