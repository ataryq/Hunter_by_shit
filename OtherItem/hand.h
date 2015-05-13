#ifndef HAND_H
#define HAND_H

#include <QGraphicsItem>
#include "../aniamtion.h"

class Hand : public QGraphicsItem
{
public:
    Hand();
    void PlayAnim();
    // QGraphicsItem interface
    void Show();
    void Hide();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    Aniamtion * anim;
};

#endif // HAND_H
