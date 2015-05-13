#ifndef UTILS_H
#define UTILS_H

#include <Qt>
#include <QRect>
#include "Regs.h"

bool CheckCollisionBetweenCircles(Circle c1, Circle c2)
{
    qreal dist = qSqrt( qPow(c2.x - c1.x, 2) + qPow(c2.y - c1.y, 2) );
    if( dist <= (c1.r + c1.r) ) return true;
    else return false;
}

#endif // UTILS_H
