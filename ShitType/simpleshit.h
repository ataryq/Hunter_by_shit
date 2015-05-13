#ifndef SIMPLESHIT_H
#define SIMPLESHIT_H

#include "shitbase.h"
#include "../Regs.h"

class SimpleShit : public ShitBase
{
public:
    SimpleShit();
    ~SimpleShit();
protected:
    void advance(int step);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
private:

    qreal speed_x, speed_y;

};

#endif // SIMPLESHIT_H
