
#ifndef MONSTER_H
#define MONSTER_H

#include <QVector>
#include <QMap>


class Monster
{
public:
    Monster();
    void MonsterInit();    

    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;

    void MonsterMove();
};

#endif // MONSTER_H
