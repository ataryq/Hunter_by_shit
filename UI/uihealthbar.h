#ifndef UIHEALTHBAR_H
#define UIHEALTHBAR_H

#include <QGraphicsItem>
#include <QRectF>
#include "../Regs.h"


class UIHealthBar : public QGraphicsItem
{
public:
    UIHealthBar();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QRectF boundingRect() const;
    QPainterPath shape() const;

private:
    const qreal h;
    const qreal w;

};

#endif // UIHEALTHBAR_H
