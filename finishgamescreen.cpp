#include "finishgamescreen.h" 
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include "gamescene.h"
#include "Regs.h"
#include "gameinfo.h"
#include <QFont>
#include <QPainterPath>
#include <QRectF>

FinishGameScreen::FinishGameScreen()
{
    isActive = false;
}

void FinishGameScreen::Hide()
{
    isActive = false;
    this->hide();
}

void FinishGameScreen::Show()
{
    isActive = true;
    this->show();
}

void FinishGameScreen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, QPixmap(":/immage/img/gray_background.png"));
    painter->drawPixmap(50, 50, QPixmap(":/immage/img/back_finish.png"));
    painter->setBrush(Qt::black);
    painter->setFont(QFont("Comic", 24));

    painter->drawText( 450, 350, QString("Score: " + QString::number(GameInfo::GetWeightShits()) ) );
}

void FinishGameScreen::advance(int step)
{
}

QRectF FinishGameScreen::boundingRect() const
{
    return QRectF(0, 0, 800, 600);
}
