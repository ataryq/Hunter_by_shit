#include "animationplayer.h"
#include "Regs.h"
#include <QSize>

AnimationPlayer::AnimationPlayer(QObject *parent) :
    QObject(parent)
{
    ANIM_MOVE = new Aniamtion(150);
    ANIM_MOVE->AddFrame(":/player/move/img/player/move/move_1.png");
    ANIM_MOVE->AddFrame(":/player/move/img/player/move/move_2.png");
    ANIM_EAT  = new Aniamtion(100);
    ANIM_EAT->AddFrame(":/player/eat/img/player/eat/eat_1.png");
    ANIM_EAT->AddFrame(":/player/eat/img/player/eat/eat_2.png");
    ANIM_EAT->AddFrame(":/player/eat/img/player/eat/eat_3.png");
    ANIM_EAT->AddFrame(":/player/eat/img/player/eat/eat_4.png");

    anim = ANIM_MOVE;
    QObject::connect( ANIM_EAT, SIGNAL(finish_animation()), this, SLOT(finish_animation_eat()) );
    anim->start();
}

void AnimationPlayer::SetAnimation(int chooseAnim)
{
    anim->stop();

    switch(chooseAnim)
    {
    case ANIM::MOVE : anim = ANIM_MOVE; break;
    case ANIM::EAT  : anim = ANIM_EAT;  break;
    }

    anim->start();
}

void AnimationPlayer::finish_animation_eat()
{
    SetAnimation(ANIM::MOVE);
}
