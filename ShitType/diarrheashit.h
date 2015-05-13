#ifndef DIARRHEASHIT_H
#define DIARRHEASHIT_H

#include "../Regs.h"
#include "shitbase.h"

class DiarrheaShit : public ShitBase
{
public:
    DiarrheaShit();
    void advance(int step);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    qreal speed_x, speed_y;
};

#endif // DIARRHEASHIT_H
