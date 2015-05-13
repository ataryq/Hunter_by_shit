#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
//#include <QMovie>
#include <QString>
#include <QPixmap>
#include "aniamtion.h"

class AnimationPlayer : public QObject
{
    Q_OBJECT

private:
    Aniamtion * anim;
    Aniamtion * ANIM_MOVE;
    Aniamtion * ANIM_EAT;
public:
    explicit AnimationPlayer(QObject *parent = 0);

    void SetAnimation(int chooseAnim);
    QPixmap GetCurPixmap(){return *(anim->GetCurQPixmap());}

signals:

public slots:
    void finish_animation_eat();

};

#endif // ANIMATION_H
