#include "generateotheritems.h"
#include "healthpoint.h"

GenerateOtherItems::GenerateOtherItems(QObject *parent) :
    QObject(parent)
{

}

GenerateOtherItems::GenerateOtherItems(QGraphicsScene *_scene, Jopa *_jopa, Player *_player)
{
    QObject::connect( &timer_create_other_item, SIGNAL(timeout()), this, SLOT(CreateOtherItems()) );
    timer_create_other_item.start(1000 / 0.25);

    QObject::connect( &timer_update, SIGNAL(timeout()), this, SLOT(Update()));
    timer_update.start(1000 / 30);

    scene = _scene;
    jopa = _jopa;
    player = _player;
    hand = new Hand();
    scene->addItem(hand);
    hand->setZValue(-1);

    time.start();

    isActive = false;
}

void GenerateOtherItems::stop()
{
    timer_create_other_item.stop();
    timer_update.stop();
    isActive = false;
}

void GenerateOtherItems::start()
{
   isActive = true;
   timer_create_other_item.start();
   timer_update.start();
}

void GenerateOtherItems::Reset()
{
    qDebug() << "Reset Generate Other Item";
    for(int i = otherItems.size() - 1; i >= 0; i--) {
        deleteOtherItem(i);
    }
}

void GenerateOtherItems::Update()
{
    if(!isActive) return;
    CheckBorder();
    checkCollision();
    checkCreate();
}

void GenerateOtherItems::checkDifficult()
{
    timer_create_other_item.stop();
    timer_create_other_item.start( 1000 / (0.25 * (GameInfo::GetDifficult() / 2) ) );
}

void GenerateOtherItems::CheckBorder()
{
    for(int i = 0; i < otherItems.size(); i++)
    {
        if(!otherItems[i]->GetActive()) continue;

        if(otherItems[i]->pos().x() > 850 || otherItems[i]->pos().x() < 50) deleteOtherItem(i);
        if(otherItems[i]->pos().y() > 540)
        {
            int pos = qrand() % 25 * ((qrand() % 2 == 0) ? -1 : 1) - 50;
            otherItems[i]->SetNotActive();
            otherItems[i]->setY(otherItems[i]->pos().y() + pos + 50 + 50);
            otherItems[i]->setZValue(pos);
        }
    }
}

void GenerateOtherItems::checkCollision()
{
    for(int i = 0; i < otherItems.size(); i++)
    {
        if(!otherItems[i]->GetActive()) continue;

        if( otherItems[i]->collidesWithItem(player) )
        {
            switch(otherItems[i]->GetTypeOject())
            {
                case TYPE_OBJECT::HEALTH_POINT : {
                    qDebug() << "collides HEALTH_POINT With Item";
                    GameInfo::SubstractHealth(otherItems[i]->GetDamage());
                    otherItems[i]->SetNotActive();
                    deleteOtherItem(i);
                } break;
                case TYPE_OBJECT::OTHER_OBJECT : {
                    qDebug() << "collides OTHER_OBJECT With Item";
                    GameInfo::SubstractHealth(otherItems[i]->GetDamage());
                    otherItems[i]->SetNotActive();
                    deleteOtherItem(i);
                }
            }
        }
    }
}

void GenerateOtherItems::deleteOtherItem(int num)
{
#ifdef DEBUG_MODE
    qDebug() << "delete item";
#endif
    scene->removeItem(otherItems[num]);
    if(otherItems[num] != 0) delete otherItems[num];
    otherItems.remove(num);
}

void GenerateOtherItems::CreateOtherItems()
{
    checkDifficult();

    BaseOtherItem * otherItem;
    if (qrand() % 2 == 0) otherItem = new HealthPoint();
    else otherItem = new Spoon();

    hand->PlayAnim();

    otherItemsCreating.push_back(otherItem);
    qreal new_x = qrand() * 10 % 600 + 100;
//    scene->addItem(otherItem);
    otherItem->setPos( new_x, 0 );
    hand->setPos(new_x, hand->pos().y());

    qDebug() << "Create OtherItems \n";
}

void GenerateOtherItems::checkCreate()
{
    for(int i = 0; i < otherItemsCreating.size(); i++)
    {
        if(otherItemsCreating[i]->timeCreate > 21)
        {
            BaseOtherItem * item = otherItemsCreating[i];
            otherItems.push_back(item);
            otherItemsCreating.remove(i);
            scene->addItem(item);
            qDebug() << "Create item\n";
        } else otherItemsCreating[i]->timeCreate++;
    }
}
