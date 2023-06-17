
#ifndef BOOM_H
#define BOOM_H

#include <QVector>
#include <QMap>



class Boom
{
public:
    Boom();
    void BoomInit();
    void BoomRelease(QVector<QVector < int>>::iterator it);

    int boomstate = -1;

    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
};

#endif // BOOM_H
