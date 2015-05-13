#ifndef SHITBASE_H
#define SHITBASE_H

#include <QGraphicsItem>
#include <ctime>
#include "../gameinfo.h"

#include "../aniamtion.h"

class ShitBase : public QGraphicsItem
{
public:
    ShitBase(qreal _weight_shit = 0, qreal _damage = 0);

    void SetNotActive();
    bool GetActive();
    qreal GetWeightShit(){return weight_shit;}
    qreal GetDamage(){return damage;}
    time_t timeDeath;
    time_t timeCreate;
    bool mastDelete;
protected:
    QPainterPath shape() const;
    bool is_active;
    qreal damage;
    qreal height_shit;
    qreal weight_shit;

    Aniamtion * anim_falling;
    Aniamtion * anim_fall_off;

    int w, h;
    qreal shape_x, shape_y;
};

#endif // SHITBASE_H
