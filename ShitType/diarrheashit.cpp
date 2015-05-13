#include "diarrheashit.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QTime>

DiarrheaShit::DiarrheaShit() : ShitBase(20, 5)
{
    qsrand( QTime().currentTime().msecsSinceStartOfDay() );
    speed_x = qrand() % 3 * ( (qrand() % 2 == 1) ? 1 : -1);
    speed_y = qrand() % 2 + 8;

    anim_falling = new Aniamtion(30);
    int delay = 30;
    anim_falling->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::DIARRHEA, ANIM::FALLING, delay) );
    anim_falling->SetDeley(delay);
    anim_fall_off = new Aniamtion(30);
    anim_fall_off->setFromVectorString( GameInfo::xmlInfo->GetPathImgs(TYPE_ENEMY::DIARRHEA, ANIM::FELL_OFF, delay) );
    anim_fall_off->SetDeley(delay);

    qDebug() << "Create simple shit _2 \n";

    anim_fall_off->setAutoloop(false);

    anim_falling->start();

    shape_y = 50;
}

QRectF DiarrheaShit::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void DiarrheaShit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
#ifdef DEBUG_MODE
    painter->setBrush(Qt::red);
    painter->drawEllipse(QRect(0, 0, 50 + shape_x, 50 + shape_y));
#endif

    if(is_active) {
        painter->drawPixmap(0, 0, *anim_falling->GetCurQPixmap());
    }
    else {
        painter->drawPixmap(0, 0, *anim_fall_off->GetCurQPixmap());
    }
}

void DiarrheaShit::advance(int step)
{
    if(!is_active) return;
    if(!step) return;

    this->setPos(pos().x() + speed_x, pos().y() + speed_y);
}
