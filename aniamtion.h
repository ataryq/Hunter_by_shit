#ifndef ANIAMTION_H
#define ANIAMTION_H

#include <QObject>
#include <QVector>
#include <QPixmap>
#include <QTimer>
#include "Regs.h"

class Aniamtion : public QObject
{
    Q_OBJECT
public:
    explicit Aniamtion(int delay_msec, QObject *parent = 0);

    void AddFrame(QString nameFileFrame);
    void stop();
    void start();
    void setAutoloop(bool _autoloop){autoloop = _autoloop;}
    void setFromVectorString(QVector<QString> _anim);
    bool getAutoloop(){return autoloop;}
    QPixmap * GetCurQPixmap();
    int GetCurIndexItem(){return curFrame;}
    void SetCurIndexItem(int _curFrame){curFrame = _curFrame ;}

    void SetDeley(int _deley);
    void PlayFromStart();
private:
    QTimer * timer_update;
    int curFrame;
    QVector<QPixmap *> anim;
    bool autoloop;

signals:
    void finish_animation();
public slots:
    void Update();
};

#endif // ANIAMTION_H
