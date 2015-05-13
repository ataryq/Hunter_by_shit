#include "jopa.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include <QWidget>
#include <QKeyEvent>
#include "Regs.h"
#include "gameinfo.h"

Jopa::Jopa(Player *_p)
{
    anim = new AnimationAss();
    player = _p;
    isActive = true;

    dx = 3;
    base_ddx = 0.3;
    max_dx = 6;
    min_dx = -6;
    ddx = 0.3;
}

void Jopa::Eating()
{
    anim->SetAnimation(ANIM::EAT);
}

void Jopa::start()
{
    isActive = true;
}

void Jopa::stop()
{
    isActive = false;
}

QRectF Jopa::boundingRect() const
{
    return QRectF(-500, J_Y, 1500, 1000);
}

QPainterPath Jopa::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 160, 160);

    return path;
}

void Jopa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
#ifdef DEBUG_MODE
    painter->setBrush(Qt::yellow);
    painter->drawRect(QRect(J_X + 50, J_Y + 25, 160, 100));
#endif
    painter->drawPixmap(J_X, J_Y, anim->GetCurPixmap());
}

void Jopa::StrategyMoving()
{
    switch(GameInfo::GetStrategy())
    {
        case TYPE_STRATEGY::BEGIN : {
            StrategyMovingSimple();
        } break;
    }
}

void Jopa::StrategyMovingSimple()
{

    const qreal RightBorder = 350;
    const qreal LeftBorder =   -100;

    static qreal _dx = 3;
    qreal _base_ddx = base_ddx  * GameInfo::GetDifficult();
    static qreal _ddx = ddx;
    static const qreal _max_speed = 6, _min_speed = -6;

    int curPos = pos().x();
    unsigned int absCurPos = pos().x() + 200;


    if(curPos > RightBorder) {
        _ddx = -_base_ddx;
    } else if(curPos < LeftBorder) {
        _ddx = _base_ddx;
    }
    /*
    else {
        static int num = 0;
        static int border = 120;
        num++;
        if(num > border) {
            qDebug() << "change direction";
            _ddx = -_ddx;
            border = 60 + (qrand() % 60);
            num = 0;
        }
    }
    */
//    int swathes[4] = {
//        BORDER_RIGHT / 4, BORDER_RIGHT / 2, BORDER_RIGHT / 2 * 3, BORDER_RIGHT
//    };
     static bool was_tried_change_dir[4] = {0,0,0,0};

//    qDebug() << curPos;
    if(!was_tried_change_dir[absCurPos / (SCENE_W / 4)]) {
        qDebug() << "change dir = " << absCurPos / (SCENE_W / 4);
        for(unsigned int i = 0; i < 4; i++) {
            if(i != absCurPos / (SCENE_W / 4))
                was_tried_change_dir[i] = false;
            else
                was_tried_change_dir[i] = true;
        }
        if( qrand() % 2 ) _ddx = -_ddx;
    }

    _dx += _ddx;
    if(_dx > _max_speed || _dx < _min_speed) _dx -= _ddx;

    setPos( this->pos().x() + _dx, this->pos().y() );
}

void Jopa::advance(int step)
{
    if(!isActive) return;
    if(!step){

    }
    else {
        StrategyMoving();
    }
}


void Jopa::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "mouse \n";
}
