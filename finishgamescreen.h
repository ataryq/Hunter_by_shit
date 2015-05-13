#ifndef FINISHGAMESCREEN_H
#define FINISHGAMESCREEN_H

#include <QGraphicsItem>

class FinishGameScreen : public QGraphicsItem
{
public:
    FinishGameScreen();
    void Show();
    void Hide();
private:
    bool isActive;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void advance(int step);
    QRectF boundingRect() const;
};

#endif // FINISHGAMESCREEN_H
