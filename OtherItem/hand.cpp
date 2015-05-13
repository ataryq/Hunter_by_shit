#include "hand.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <QDebug>
#include <QWidget>
#include <QKeyEvent>
#include "../Regs.h"
#include "../gameinfo.h"

Hand::Hand()
{
    anim = new Aniamtion(100);
    anim->AddFrame(":/immage/img/other_item/hand/11.png");
    anim->AddFrame(":/immage/img/other_item/hand/1.png");
    anim->AddFrame(":/immage/img/other_item/hand/2.png");
    anim->AddFrame(":/immage/img/other_item/hand/3.png");
//    anim->AddFrame(":/immage/img/other_item/hand/4.png");
    anim->AddFrame(":/immage/img/other_item/hand/5.png");
    anim->AddFrame(":/immage/img/other_item/hand/6.png");
//    anim->AddFrame(":/immage/img/other_item/hand/7.png");
    anim->AddFrame(":/immage/img/other_item/hand/8.png");
//    anim->AddFrame(":/immage/img/other_item/hand/9.png");
    anim->AddFrame(":/immage/img/other_item/hand/10.png");
    anim->AddFrame(":/immage/img/other_item/hand/11.png");

    anim->setAutoloop(false);
}

void Hand::PlayAnim()
{
    anim->PlayFromStart();
}

void Hand::Show() {
    this->show();
}

void Hand::Hide() {
    this->hide();
}

QRectF Hand::boundingRect() const
{
    return QRectF(-100, -100, 300, 300);
}

void Hand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *anim->GetCurQPixmap());
}

