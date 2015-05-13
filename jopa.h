#ifndef JOPA_H
#define JOPA_H

#include <QGraphicsItem>
#include "Regs.h"
#include "animationass.h"
#include "player.h"

class Jopa : public QGraphicsItem
{
public:
    Jopa(Player * _p);
    void Eating();
    void SetNotActive();

    void stop();
    void start();


protected:
    void advance(int step);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    void StrategyMoving();

    AnimationAss * anim;
    Player * player;
    qreal numStrategy;

    void StrategyMovingSimple();
private:
    bool isActive;

    qreal dx;
    qreal base_ddx;
    qreal max_dx;
    qreal min_dx;
    qreal ddx;

    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // JOPA_H
