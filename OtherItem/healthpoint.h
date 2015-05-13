#ifndef HEALTHPOINT_H
#define HEALTHPOINT_H

#include "baseotheritem.h"

#include <QObject>
#include <QSet>
#include <QVector>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>
#include <QPixmap>

class HealthPoint : public BaseOtherItem
{
public:
    HealthPoint();
protected:
    QRectF boundingRect() const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal dx, dy;
};

#endif // HEALTHPOINT_H
