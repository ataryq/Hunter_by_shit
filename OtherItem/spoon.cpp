#include "spoon.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QTime>
#include "../Regs.h"

#include "../gameinfo.h"

Spoon::Spoon() : BaseOtherItem(TYPE_OBJECT::OTHER_OBJECT)
{
    dx = qrand() % 3 * ( (qrand() % 2 == 1) ? 1 : -1);
    dy = qrand() % 4 + 3;

    is_active = true;

    anim_falling = new Aniamtion(30);
    int delay = 30;
    anim_falling->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::SPOON, ANIM::FALLING, delay) );
    anim_falling->SetDeley(delay);
    anim_fall_off = new Aniamtion(30);
    anim_fall_off->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::SPOON, ANIM::FELL_OFF, delay) );
    anim_fall_off->SetDeley(delay);

    anim_fall_off->setAutoloop(false);

    anim_falling->start();
}

void Spoon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
#ifdef DEBUG_MODE
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(0, 0, 50, 70);
#endif
    if(is_active) {
        painter->drawPixmap(0, 0, *anim_falling->GetCurQPixmap());
    } else {
        painter->drawPixmap(0, 0, *anim_fall_off->GetCurQPixmap());
    }
}


void Spoon::advance(int phase)
{
    if(!is_active) return;
    if(!phase) {

    } else {
        this->setPos(pos().x() + dx, pos().y() + dy);
    }
}

QRectF Spoon::boundingRect() const
{
    return QRectF(0, 0, 50, 20);
}
