
#ifndef PIPE_H
#define PIPE_H

#include <QVector>
#include <QMap>


class Pipe
{
public:
    Pipe();
    void PipeInit();

    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m_short;
    QMap<int, QVector<QVector < int>>> m_mid;
    QMap<int, QVector<QVector < int>>> m_long;
};

#endif // PIPE_H
