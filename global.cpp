#ifndef GLOBAL_CPP
#define GLOBAL_CPP
#include "global.h"
#include <QDebug>

QString LEVEL_NAME = "";
QVector<QSoundEffect*>playerList;
QVector<QSoundEffect*>backplayerList;
MusicPlayer *musicPlayer = new MusicPlayer;

//音效区
QString BackMusic= ":/resources/music/game_over.wav";

void stopAllMusic()
{
    for(int i=0;i<playerList.size();i++)
    {
        QSoundEffect *m = playerList[i];
        m->stop();
        playerList.remove(i);
    }
}

void stopAllBackMusic()
{
    for(int i=0;i<backplayerList.size();i++)
    {
        QSoundEffect *m = backplayerList[i];
        m->stop();
        backplayerList.remove(i);
    }
}
#endif // GLOBAL_CPP
