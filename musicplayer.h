
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
    void close();
    void backMusicPlay(QString str);
    void backMusicclose();
signals:

public slots:
};

#endif // MUSICPLAYER_H
