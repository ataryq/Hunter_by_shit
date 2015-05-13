#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QTime>

#include "../Regs.h"

#include "healthpoint.h"
#include "../gameinfo.h"

HealthPoint::HealthPoint() : BaseOtherItem(TYPE_OBJECT::HEALTH_POINT, -20)
{
    dx = qrand() % 3 * ( (qrand() % 2 == 1) ? 1 : -1);
    dy = qrand() % 4 + 3;

    is_active = true;

    anim_falling = new Aniamtion(30);
    int delay = 30;
    anim_falling->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::HEALTH_POINT, ANIM::FALLING, delay) );
    anim_falling->SetDeley(delay);
    anim_fall_off = new Aniamtion(30);
    anim_fall_off->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::HEALTH_POINT, ANIM::FELL_OFF, delay) );
    anim_fall_off->SetDeley(delay);

    anim_fall_off->setAutoloop(false);

    anim_falling->start();
}

void HealthPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
#ifdef DEBUG_MODE
    painter->setBrush(Qt::green);
    painter->drawEllipse(0, 0, 50, 70);
#endif
    if(is_active) {
        painter->drawPixmap(0, 0, *anim_falling->GetCurQPixmap());
    } else {
        painter->drawPixmap(0, 0, *anim_fall_off->GetCurQPixmap());
    }
}


void HealthPoint::advance(int phase)
{
    if(!is_active) return;
    if(!phase) {

    } else {
        this->setPos(pos().x() + dx, pos().y() + dy);
    }
}

QRectF HealthPoint::boundingRect() const
{
    return QRectF(0, 0, 50, 20);
}
