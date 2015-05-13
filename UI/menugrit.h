#ifndef MENUGRIT_H
#define MENUGRIT_H

#include <QGraphicsItem>

class MenuGrIt : public QGraphicsItem
{
public:
    MenuGrIt();
    void Hide();
    void Show();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int step);
    QRectF boundingRect() const;

};

#endif // MENUGRIT_H
