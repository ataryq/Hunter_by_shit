#ifndef ANIMATIONASS_H
#define ANIMATIONASS_H

#include <QObject>
#include <QString>
#include <QPixmap>

#include "aniamtion.h"

class AnimationAss : public QObject
{
    Q_OBJECT
public:
    explicit AnimationAss(QObject *parent = 0);
    void SetAnimation(int chooseAnim);
    QPixmap GetCurPixmap(){return * anim->GetCurQPixmap();}

private:
    Aniamtion * anim;
    Aniamtion * ANIM_MOVE;
    Aniamtion * ANIM_EAT;


signals:

public slots:
    void finish_animation_eat();
};

#endif // ANIMATIONASS_H
