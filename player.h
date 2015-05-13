#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QWidget>
#include "Regs.h"
#include <QPixmap>
#include <QTime>
#include "animationplayer.h"

class Player : public QGraphicsItem
{
public:
    Player();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void KeyPressEvent_player(QKeyEvent * keyEvent);

    void KeyReliseEvent_player(QKeyEvent *keyEvent);
    void Eating();
    bool SpaceIsPress(){return pressSpace;}
    void stop();
    void start();
protected:
    void advance(int step);

    qreal dx_speed;
    const qreal ddx_speed;

    const qreal max_speed;
    const qreal min_speed;

    bool pressLeft;
    bool pressRight;
    bool pressSpace;

    AnimationPlayer * anim;
    QPixmap * backgrnd;

private:
    void choose_animation();
    bool isActive;

    QTime time;

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLAYER_H
