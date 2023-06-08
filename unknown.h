
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

    bool coin;//金币是否已经出现
    int coin_y;
    int coin_state;
    int coinheight;
    int upstate;

    void Unknown_crash(QVector<QVector < int>>::iterator it);
    void CoinAppear();
};

#endif // UNKNOWN_H
