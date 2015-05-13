#include "baseotheritem.h"
#include "../player.h"
#include "../Regs.h"

BaseOtherItem::BaseOtherItem(int _type, qreal _damage) : type_object(_type)
{

    damage = (_damage == -1) ? 20 : _damage;

    anim_falling = new Aniamtion(80);
    anim_fall_off = new Aniamtion(80);

    timeCreate = 0;
}

void BaseOtherItem::SetNotActive()
{
    qDebug() << "SetNotActive";
    anim_fall_off->SetCurIndexItem(0);
    is_active = false;
    anim_falling->stop();
    anim_fall_off->start();
}

QPainterPath BaseOtherItem::shape() const
{
    QPainterPath path;
    if(is_active)
    {
       path.addEllipse(0, 0, 50, 70);
    }
    return path;
}

