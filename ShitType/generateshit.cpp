#include "generateshit.h"
#include <QTimer>
#include <QGraphicsItem>
#include "simpleshit.h"
#include <QDebug>
#include <ctime>
#include <iterator>
#include "../Utils.h"
#include "../Regs.h"
#include "../gameinfo.h"

GenerateShit::GenerateShit(QObject *parent) :
    QObject(parent), isActive(true)
{

}

GenerateShit::GenerateShit(QGraphicsScene *_scene, Jopa *_jopa, Player *_player)
{

    QObject::connect( &timer_create_enemy, SIGNAL(timeout()), this, SLOT(CreateEnemy()) );
    timer_create_enemy.start(1000 / 0.5);

    QObject::connect( &timer_update, SIGNAL(timeout()), this, SLOT(Update()));
    timer_update.start(1000 / 30);

    scene = _scene;
    jopa = _jopa;
    player = _player;

    time.start();

    isActive = false;
}

void GenerateShit::stop()
{
    timer_create_enemy.stop();
    timer_update.stop();
    isActive = false;
}

void GenerateShit::start()
{
   isActive = true;
   timer_create_enemy.start();
   timer_update.start();
}

void GenerateShit::ClearActive()
{
    qDebug() << "ClearActive ";
    for(int i = shits.size() - 1; i >= 0; i--) {
        if( shits[i]->isActive() ) deleteEnemy(i);
    }
    for(int i = shitsCreating.size() - 1; i >= 0; i--) {
        if( shitsCreating[i]->isActive() ) {
            if(shitsCreating[i] != 0) delete shitsCreating[i];
            shitsCreating.remove(i);
        }
    }
}

void GenerateShit::Reset()
{
    qDebug() << "Reset ";
    for(int i = shits.size() - 1; i >= 0; i--) {
        deleteEnemy(i);
    }
    for(int i = shitsCreating.size() - 1; i >= 0; i--) {
        if(shitsCreating[i] != 0) delete shitsCreating[i];
        shitsCreating.remove(i);
    }
}

void GenerateShit::Update()
{
    if(!isActive) return;
    CheckBorder();
    checkCollision();
    checkDelete();
    checkCreate();

}

void GenerateShit::checkDifficult()
{
    timer_create_enemy.stop();
    timer_create_enemy.start( 1000 / (0.5 * GameInfo::GetDifficult()) );
}

void GenerateShit::CheckBorder()
{
    for(int i = 0; i < shits.size(); i++)
    {
        if(!shits[i]->GetActive()) continue;
        if(shits[i]->pos().x() > 850 ||
                shits[i]->pos().x() < -100) deleteEnemy(i);
        if(shits[i]->pos().y() > 540)
        {
            int pos = qrand() % 25 * ((qrand() % 2 == 0) ? -1 : 1) - 50;
            shits[i]->SetNotActive();
            shits[i]->setY(shits[i]->pos().y() + pos + 50);
            shits[i]->setZValue(pos);
            if(!shits[i]->mastDelete) GameInfo::SubstractHealth(shits[i]->GetDamage());
        }
    }
}

void GenerateShit::checkDelete()
{
    for(int i = 0; i < shits.size(); i++)
    {
        if(shits[i]->mastDelete)
        {
            if(shits[i]->timeDeath > 3)
            {
#ifdef DEBUG_MODE
                qDebug() << "delete shit in checkDelete\n";
#endif
                deleteEnemy(i);
            } else shits[i]->timeDeath++;
        }
    }
}

void GenerateShit::checkCreate()
{
    for(int i = 0; i < shitsCreating.size(); i++)
    {
        if(shitsCreating[i]->timeCreate > 12)
        {
            ShitBase * enemy = shitsCreating[i];
            shits.push_back(enemy);
            shitsCreating.remove(i);
            scene->addItem(enemy);
            enemy->setPos( jopa->pos().x() + 230, jopa->pos().y() + 100 );
            qDebug() << "Create enemy\n";
        } else shitsCreating[i]->timeCreate++;
    }
}

void GenerateShit::checkCollision()
{
    for(int i = 0; i < shits.size(); i++)
    {
        if(!shits[i]->GetActive()) continue;
        if(shits[i]->mastDelete) continue;

        if( shits[i]->collidesWithItem(player) )
        {
            GameInfo::AddWeightShits( shits[i]->GetWeightShit() );
            player->Eating();
            shits[i]->timeDeath = 0;
            shits[i]->mastDelete = true;
        }
    }
}

void GenerateShit::deleteEnemy(int num)
{
#ifdef DEBUG_MODE
    qDebug() << "delete shit";
#endif
    scene->removeItem(shits[num]);
    if(shits[num] != 0) delete shits[num];
    shits.remove(num);
}

void GenerateShit::CreateEnemy()
{
    checkDifficult();

    ShitBase * enemy;
    if (qrand() % 2 == 0) enemy = new SimpleShit();
    else enemy = new DiarrheaShit();
    enemy->setZValue(-49);

    shitsCreating.push_back(enemy);
    jopa->Eating();

}
