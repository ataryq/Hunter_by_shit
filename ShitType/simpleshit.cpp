#include "simpleshit.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QTime>

#include "../aniamtion.h"

SimpleShit::SimpleShit() : ShitBase(37, 25)
{
    qDebug() << "Create simple shit \n";
    qsrand( QTime().currentTime().msecsSinceStartOfDay() );
    speed_x = qrand() % 3 * ( (qrand() % 2 == 1) ? 1 : -1);
    speed_y = qrand() % 4 + 3;

    anim_falling = new Aniamtion(30);
    int delay = 30;
    anim_falling->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::SIMPLE_SHIT, ANIM::FALLING, delay) );
    anim_falling->SetDeley(delay);
    qDebug() << "SH delay = " << delay;
    anim_fall_off = new Aniamtion(30);
    anim_fall_off->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::SIMPLE_SHIT, ANIM::FELL_OFF, delay) );
    anim_fall_off->SetDeley(delay);
    qDebug() << "SH delay = " << delay;

    /*switch(qrand() % 3)
    {
        case 0:  anim_fall_off->AddFrame(":/immage/img/shits/simple/fell_off/8.png"); break;
        case 1:  anim_fall_off->AddFrame(":/immage/img/shits/simple/fell_off/8.png"); break;
    }*/

    qDebug() << "Create simple shit _2 \n";

    anim_fall_off->setAutoloop(false);

    anim_falling->start();
}

SimpleShit::~SimpleShit()
{
    qDebug() << "delete simple shit ";
}

QRectF SimpleShit::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void SimpleShit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
#ifdef DEBUG_MODE
    painter->setBrush(Qt::red);
    painter->drawEllipse(QRect(0, 0, 50, 50));
#endif
    if(is_active) {
        painter->drawPixmap(0, 0, *anim_falling->GetCurQPixmap());
    }
    else {
        painter->drawPixmap(0, 0, *anim_fall_off->GetCurQPixmap());
    }
}



void SimpleShit::advance(int step)
{
    if(!is_active) return;
    if(!step) return;

    this->setPos(pos().x() + speed_x, pos().y() + speed_y);
}
