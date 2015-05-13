#ifndef SPOON_H
#define SPOON_H

#include <QObject>
#include <QSet>
#include <QVector>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>
#include <QPixmap>

#include "baseotheritem.h"

class Spoon : public BaseOtherItem
{
public:
    Spoon();

    // QGraphicsItem interface
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
private:
    qreal dx, dy;
};

#endif // SPOON_H
