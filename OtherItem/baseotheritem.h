#ifndef BASEOTHERITEM_H
#define BASEOTHERITEM_H

#include <QGraphicsItem>
#include <QTimer>
#include "../gameinfo.h"
#include "../aniamtion.h"

class BaseOtherItem : public QGraphicsItem
{
public:
    BaseOtherItem(int _type = TYPE_OBJECT::OTHER_OBJECT, qreal _damage = -1);

    bool GetActive() {return is_active;}
    void SetNotActive();
    qreal GetDamage() {return damage;}
    int GetTypeOject(){return type_object;}
    int timeCreate;

protected:
    QPainterPath shape() const;
    bool is_active;
    int type_object;

    Aniamtion * anim_falling;
    Aniamtion * anim_fall_off;
private:
    qreal damage;
};

#endif // BASEOTHERITEM_H
