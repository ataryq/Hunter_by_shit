#include "uirecordscreen.h"

#include <QDebug>
#include <QSize>
#include <QSizePolicy>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QPainter>
#include <QPixmap>


UIRecordScreen::UIRecordScreen()
{
    draw_records = NULL;
}


QRectF UIRecordScreen::boundingRect() const
{
    return QRectF(0, 0, 800, 600);
}

void UIRecordScreen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(100, 100, 600, 350, QPixmap(":/immage/img/back_records.png"));
    painter->setBrush(Qt::black);
    painter->setFont(QFont("Comic", 24));

    painter->drawText( 350, 150, QString("Records :" ) );
    if(draw_records != NULL)
    {
        for(int i = 0; i < draw_records->size(); i++) {
            if(i >= 5) break;
            QStringList list = draw_records->at(i).split("/");
            painter->drawText( 150, 200 + i * 50, QString::number(i + 1) );
            painter->drawText( 240, 200 + i * 50, list.at(1) );
            painter->drawText( 540, 200 + i * 50, list.at(2) );
        }
    }
}
