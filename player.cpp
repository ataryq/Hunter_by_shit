#include "player.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include "gamescene.h"
#include "Regs.h"
//#include "gameinfo.h"

Player::Player() :
    ddx_speed(1.0), max_speed(12), min_speed(6)
{
    setFlag( QGraphicsItem::ItemIsFocusable, true );
    dx_speed = 0;
    pressSpace = false;
    pressLeft = false;
    pressRight = false;
    isActive = true;

    backgrnd = new QPixmap(":/immage/img/backgrnd.png");

    anim = new AnimationPlayer();
    time.start();
}

QRectF Player::boundingRect() const
{
    return QRectF(-100, -100, 400, 400);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addEllipse(0, 25, 250, 250);
//    path.addRect(0, 0, 200, 200);
//    path.addRect(0, 100, 25, 10);
//    path.addRect(150, 100, 25, 10);
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawText(QRectF(-50, -50, 50, 100), "Hello user!");
#ifdef DEBUG_MODE
    painter->setBrush(Qt::yellow);
//    painter->drawRect(QRect(0, 25, 150, 10));
//    painter->drawRect(QRect(0, 75, 25, 10));
//    painter->drawRect(QRect(0, 25, 200, 200));
    painter->drawEllipse(0, 25, 200, 200);
#endif
    painter->drawPixmap(-25, 15, *backgrnd);
    painter->drawPixmap(-50, -100, anim->GetCurPixmap());
}

void Player::KeyPressEvent_player(QKeyEvent *keyEvent)
{
#ifdef DEBUG_MODE
    //qDebug() << "key press in obj dx_speed" << this->dx_speed;
#endif
    switch(keyEvent->key())
    {
        case Qt::Key_A:
        case Qt::Key_Left: pressLeft = true; break;
        case Qt::Key_D:
        case Qt::Key_Right: pressRight = true; break;
        case Qt::Key_Space: pressSpace = true; break;
    }
}

void Player::KeyReliseEvent_player(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
        case Qt::Key_A:
        case Qt::Key_Left: pressLeft = false; break;
        case Qt::Key_D:
        case Qt::Key_Right: pressRight = false; break;
        case Qt::Key_Space: pressSpace = false; break;
    }
#ifdef DEBUG_MODE
    //qDebug() << "key relise in obj dx_speed" << this->dx_speed;
#endif
}

void Player::Eating()
{
    anim->SetAnimation(ANIM::EAT);
}

void Player::start()
{
    isActive = true;
}

void Player::stop()
{
    isActive = false;
}

void Player::advance(int step)
{
    if(!isActive) return;
    if(step) {
        return;
    }

    if(this->pressSpace)
    {
        if(dx_speed < max_speed)
        {
            dx_speed += ddx_speed;
        }
        if(pos().x() > BORDER_RIGHT) dx_speed = 0;
    } else
    {
        if(dx_speed > -max_speed)
        {
            dx_speed -= ddx_speed;
        }
        if(pos().x() < BORDER_LEFT) dx_speed = 0;
    }

    if( (dx_speed > 0 && pos().x() < BORDER_RIGHT) || (dx_speed < 0 && pos().x() > BORDER_LEFT) )
        setPos( this->pos().x() + this->dx_speed, this->pos().y() );
    else setPos( this->pos().x() + 0.1, this->pos().y() );
}


void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "mouse_2 \n";
}
