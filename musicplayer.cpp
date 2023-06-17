
#include "musicplayer.h"
#include<QSoundEffect>
//#include <global.h>
#include <QDebug>

MusicPlayer::MusicPlayer()
{
    mediaPlayer = new QSoundEffect;
    backPlayer = new QSoundEffect;
}

void MusicPlayer::play(QString str)
{
    mediaPlayer->setSource(QUrl::fromLocalFile(str));
    mediaPlayer->setLoopCount(1);
    mediaPlayer->setVolume(0.5f);
    mediaPlayer->play();
    qDebug() << 1;
}

void MusicPlayer::backMusicPlay(QString str)
{
    backPlayer->setSource(QUrl::fromLocalFile(str));
    backPlayer->setLoopCount(QSoundEffect::Infinite);
    backPlayer->setVolume(0.5f);
    backPlayer->play();
    //backplayerList.append(backPlayer);
}
