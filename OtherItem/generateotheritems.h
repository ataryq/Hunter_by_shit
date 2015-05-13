#ifndef GENERATEOTHERITEMS_H
#define GENERATEOTHERITEMS_H

#include <QObject>
#include <QObject>
#include <QSet>
#include <QVector>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>

#include "baseotheritem.h"
#include "../player.h"
#include "../jopa.h"
#include "spoon.h"
#include "../gameinfo.h"
#include "hand.h"

class GenerateOtherItems : public QObject
{
    Q_OBJECT
public:
    explicit GenerateOtherItems(QObject *parent = 0);
    explicit GenerateOtherItems(QGraphicsScene *_scene,
                                Jopa *_jopa,
                                Player * _player);

    void stop();
    void start();

    void Reset();
protected:
    QVector<BaseOtherItem *> otherItems;
    QVector<BaseOtherItem *> otherItemsCreating;

    QTimer timer_create_other_item;
    QTimer timer_update;
    QGraphicsScene * scene;
    Jopa   * jopa;
    Player * player;
    QTime time;
    Hand * hand;

    void deleteOtherItem(int num);
    void checkDifficult();
    void CheckBorder();
    void checkCreate();
    void checkCollision();
private:
    bool isActive;


signals:

public slots:
    void CreateOtherItems();
    void Update();
};

#endif // GENERATEOTHERITEMS_H
