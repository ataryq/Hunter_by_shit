#include "aboutgamegrit.h"
#include <QPainter>
#include <QRectF>

AboutGameGrIt::AboutGameGrIt()
{

}

AboutGameGrIt::~AboutGameGrIt()
{

}



QRectF AboutGameGrIt::boundingRect() const
{
    return QRectF(0, 0, 1000, 1000);
}

void AboutGameGrIt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(50, 50, QPixmap(":/immage/img/back_finish.png"));
    painter->setBrush(Qt::black);
    painter->setFont(QFont("Comic", 24));

    painter->drawText( 300, 100, QString( "Control:" ) );
    painter->drawText( 150, 150, QString( "Press SPACE or tap for moving right" ) );
    painter->drawText( 300, 200, QString( "Authors:" ) );
    painter->drawText( 150, 250, QString( "Programmer: Kuvshinov Igor (ataryq)" ) );
    painter->drawText( 150, 300, QString( "Artist:           Dmitrii Lomonosov" ) );
    painter->drawText( 150, 350, QString( "About all wishes or offers write to:" ) );
    painter->drawText( 150, 400, QString( "hunter_by_shit@mail.ru" ) );
}
