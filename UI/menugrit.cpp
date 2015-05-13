#include "menugrit.h"

#include "../finishgamescreen.h"
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

MenuGrIt::MenuGrIt()
{
}

void MenuGrIt::Hide()
{
    this->hide();
}

void MenuGrIt::Show()
{
    this->show();
}

void MenuGrIt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-50, -50, QPixmap(":/immage/img/menyu.png"));
//    painter->drawPixmap(0, 0, QPixmap(":/immage/img/Komnata_2_2.png"));
////    painter->drawPixmap(130, 170, QPixmap(":/immage/img/green_background.png"));
//    painter->setBrush(Qt::white);
//    painter->drawRect(QRect(450, 300, 250, 100));
//    painter->setBrush(Qt::black);
//    painter->setFont(QFont("Comic", 24));

//    painter->drawText( 500, 350, QString("Score: " + QString::number(GameInfo::GetWeightShits()) ) );
////    painter->drawText( 350, 400, QString(" Press Space to repeat" ) );
}

void MenuGrIt::advance(int step)
{
}

QRectF MenuGrIt::boundingRect() const
{
    return QRectF(0, 0, 1000, 1000);
}
