#ifndef GENERATESHIT_H
#define GENERATESHIT_H

#include <QObject>
#include <QSet>
#include <QVector>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>

#include "shitbase.h"
#include "diarrheashit.h"
#include "../player.h"
#include "../jopa.h"

class GenerateShit : public QObject
{
    Q_OBJECT
    void checkCollision();
    void deleteEnemy(int num);

public:
    explicit GenerateShit(QObject *parent = 0);
    explicit GenerateShit(QGraphicsScene *_scene, Jopa *_jopa, Player * _player);
   void stop();

   void start();
   void Reset();
   void ClearActive();
protected:
    void CheckBorder();
    void checkDelete();
    void checkCreate();

    QVector<ShitBase *> shits;
    QVector<ShitBase *> shitsCreating;

    QTimer timer_create_enemy;
    QTimer timer_update;
    QGraphicsScene * scene;
    Jopa * jopa;
    Player * player;
    QTime time;

private:
    bool isActive;

    void checkDifficult();
signals:

public slots:
    void CreateEnemy();
    void Update();
};

#endif // GENERATESHIT_H
