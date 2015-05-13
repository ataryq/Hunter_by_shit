#ifndef ABOUTGAMEGRIT_H
#define ABOUTGAMEGRIT_H

#include <QGraphicsItem>



class AboutGameGrIt : public QGraphicsItem
{
public:
    AboutGameGrIt();
    ~AboutGameGrIt();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ABOUTGAMEGRIT_H
