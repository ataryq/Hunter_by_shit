#include "shitbase.h"
#include "../player.h"
#include "../Regs.h"

ShitBase::ShitBase(qreal _weight_shit, qreal _damage)
{
    mastDelete = false;
    timeCreate = 0;
    timeDeath = 0;
    w = 50;
    h = 50;
    shape_x = 0;
    shape_y = 0;
    weight_shit = (_weight_shit == 0) ? _weight_shit : 50;
    damage = (_damage == 0) ? _damage : 20;
    is_active = true;

    anim_falling = new Aniamtion(80);
    anim_fall_off = new Aniamtion(80);
}

void ShitBase::SetNotActive()
{
    qDebug() << "SetNotActive_2";
    is_active = false;
    anim_falling->stop();
    anim_fall_off->SetCurIndexItem(0);
    anim_fall_off->start();
}

bool ShitBase::GetActive()
{
    return is_active;
}

QPainterPath ShitBase::shape() const
{
    QPainterPath path;
    if(is_active)
    {
       path.addEllipse(shape_x, shape_y, w, h);
    }
    return path;
}


