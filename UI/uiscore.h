#ifndef UISCORE_H
#define UISCORE_H

#include <QGraphicsItem>

class UIScore : public QGraphicsItem
{
public:
    UIScore();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void advance(int step);
    QRectF boundingRect() const;
    QPainterPath shape() const;
};

#endif // UISCORE_H
