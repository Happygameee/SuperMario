
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include<QSoundEffect>

class MusicPlayer
{
public:
    explicit MusicPlayer();
    QSoundEffect *mediaPlayer;
    QSoundEffect *backPlayer;
    void play(QString str);
    void backMusicPlay(QString str);
signals:

public slots:
};

#endif // MUSICPLAYER_H
