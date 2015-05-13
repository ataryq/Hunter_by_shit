#include "uihealthbar.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include "../gamescene.h"
#include "../Regs.h"
#include "../gameinfo.h"
#include <QPainterPath>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>

UIHealthBar::UIHealthBar() : h(20), w(500)
{
}

void UIHealthBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static qreal health = 0;
    painter->drawPixmap(-50, -50, QPixmap(":/immage/img/health_background.png"));
    health = GameInfo::GetHealth() > 0 ? GameInfo::GetHealth() : 0;
    painter->setBrush(Qt::red);
    painter->drawRect(QRect(50, 10, w * health / 100, h));
}

QRectF UIHealthBar::boundingRect() const
{
    return QRectF(0, 0, w, h);
}

QPainterPath UIHealthBar::shape() const
{
    QPainterPath path;
    return path;
}
