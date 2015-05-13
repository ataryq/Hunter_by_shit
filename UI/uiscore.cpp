#include "uiscore.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include "../gamescene.h"
#include "../Regs.h"
#include "../gameinfo.h"
#include <QFont>
#include <QPainterPath>
#include <QRectF>
#include <QFont>

UIScore::UIScore()
{
}

void UIScore::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    QFont * font = new QFont;
//    painter->setFont(font);
    painter->drawRect(0, 0, 200, 100);
    painter->setFont(QFont("Arial", 18));
    painter->drawText( 50, 50, QString("Score: " + QString::number(GameInfo::GetWeightShits()) ) );
}

void UIScore::advance(int step)
{
    if(!step) return;
    this->update(-100,-100, 100, 100);
    this->setPos(pos().x(), pos().y());
}

QRectF UIScore::boundingRect() const
{
    return QRectF(-100,-100, 200, 200);
}

QPainterPath UIScore::shape() const
{
    QPainterPath path;
    return path;
}
