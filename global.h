#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>
#include <QPixmap>
#include <musicplayer.h>
#include <QSoundEffect>

extern int LIVES;
extern QVector<QSoundEffect*>playerList;
extern QVector<QSoundEffect*>backplayerList;
extern MusicPlayer *musicPlayer;
extern void stopAllMusic();
extern void stopAllBackMusic();
extern QString BackMusic1;
extern QString BackMusic2;
extern QString DieMusic;
extern QString Game_Over;
extern QString Jump;

#endif // GLOBAL_H
