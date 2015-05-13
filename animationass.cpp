#include "animationass.h"
#include "Regs.h"

AnimationAss::AnimationAss(QObject *parent) :
    QObject(parent)
{    
    ANIM_MOVE = new Aniamtion(200);
    ANIM_EAT  = new Aniamtion(200);

    ANIM_EAT->AddFrame(":/ass/eat/img/ass/eat/eat_1.png");
    ANIM_EAT->AddFrame(":/ass/eat/img/ass/eat/eat_2.png");
    ANIM_EAT->AddFrame(":/ass/eat/img/ass/eat/eat_3.png");
    ANIM_EAT->AddFrame(":/ass/eat/img/ass/eat/eat_4.png");
    ANIM_EAT->AddFrame(":/ass/eat/img/ass/eat/eat_5.png");

    ANIM_MOVE->AddFrame(":/ass/move/img/ass/move/move_1.png");
    ANIM_MOVE->AddFrame(":/ass/move/img/ass/move/move_2.png");

    anim = ANIM_MOVE;
    QObject::connect( ANIM_EAT, SIGNAL(finish_animation()), this, SLOT(finish_animation_eat()) );
    anim->start();
}

void AnimationAss::SetAnimation(int chooseAnim)
{
    anim->stop();

    switch(chooseAnim)
    {
    case ANIM::MOVE : anim = ANIM_MOVE; break;
    case ANIM::EAT  : anim = ANIM_EAT;  break;
    }

    anim->start();
}

void AnimationAss::finish_animation_eat()
{
     SetAnimation(ANIM::MOVE);
}
