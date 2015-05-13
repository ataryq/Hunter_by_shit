#include "aniamtion.h"
#include "Regs.h"

Aniamtion::Aniamtion(int delay_msec, QObject *parent) :
    QObject(parent), curFrame(0)
{
    autoloop = true;

    timer_update = new QTimer(this);
    QObject::connect( timer_update, SIGNAL(timeout()), this, SLOT(Update()));
    timer_update->setInterval(delay_msec);
}

void Aniamtion::stop()
{
    timer_update->stop();
}

void Aniamtion::start()
{
    timer_update->start();
}

void Aniamtion::PlayFromStart()
{
    SetCurIndexItem(0);
    start();
}

void Aniamtion::SetDeley(int _deley)
{
    timer_update->stop();
    timer_update->setInterval(_deley);
    timer_update->start();
}

void Aniamtion::setFromVectorString(QVector<QString>  _anim)
{
    for(int i = 0; i < _anim.size(); i++) {
        AddFrame(_anim.at(i));
    }
}

void Aniamtion::Update()
{
    if(anim.size() - 1 > curFrame)
           curFrame++;
    else
    {
        if(!autoloop) stop();
        else curFrame = 0;
        emit finish_animation();
    }
}

QPixmap * Aniamtion::GetCurQPixmap()
{
    static QPixmap * pix = new QPixmap(":/immage/img/empty.png");
    if(anim.size() > 0)
        return anim.at(curFrame);
    else return pix;
}

void Aniamtion::AddFrame(QString nameFileFrame)
{
    anim.push_back(new QPixmap(nameFileFrame));
}
