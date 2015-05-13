#include "gamescene.h"
#include <QPainter>
#include <QRectF>
#include <QBrush>
#include <QKeyEvent>
#include <QEvent>
#include <QDebug>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsObject>
#include "gameinfo.h"
#include <QSize>

#include "Regs.h"

GameScene::GameScene(QObject *parent) :
    QGraphicsScene(parent)
{
    imgSource = QPixmap(":/immage/img/Komnata.png");
    player = new Player;
    this->addItem(player);
    player->setPos(P_X, P_Y - 96);
    player->setZValue(-1);

    isActive = true;

    jopa = new Jopa(player);
    this->addItem(jopa);
    jopa->setPos(J_X, J_Y);
    jopa->setZValue(-50);

    gener = new GenerateShit(this, jopa, player);

    timeDifficult = new QTime();
    timeDifficult->start();

    generOtherItem = new GenerateOtherItems(this, jopa, player);

    Hide();

    isDrawBackground = false;
}

void GameScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(-45, -50, imgSource );
}

void GameScene::StopGame()
{
    gener->stop();
    gener->ClearActive();
    jopa->stop();
    player->stop();
    generOtherItem->stop();
}

void GameScene::Hide()
{
    jopa->hide();
    player->hide();
    isDrawBackground = false;
    HideScene();
}

void GameScene::StartGame()
{
    jopa->show();
    player->show();

    gener->start();
    jopa->start();
    player->start();
    generOtherItem->start();

    isDrawBackground = true;
    ShowScene();
}

void GameScene::ResetGame()
{
    gener->Reset();
    generOtherItem->Reset();
}

void GameScene::advance(int step)
{
    if(!step) return;
}

void GameScene::keyPressEvent(QKeyEvent *keyEvent)
{
    this->player->KeyPressEvent_player(keyEvent);
    GameInfo::pressSpace = true;
    switch(keyEvent->key())
    {
        case Qt::Key_Space : {

        } break;
        case Qt::Key_Backspace : {
            GameInfo::InputText.chop(1);
        } break;
        default:{
            GameInfo::InputText.push_back(keyEvent->key());
        }
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *keyEvent)
{
    GameInfo::pressSpace = false;
    this->player->KeyReliseEvent_player(keyEvent);
    switch(keyEvent->key())
    {
#ifdef DEBUG_MODE
        case Qt::Key_Backspace: {
            this->StartGame();
        } break;

        case Qt::Key_Enter: {
            qDebug() << "enter";
            this->StopGame();
       } break;
    case Qt::Key_Shift : {
            qDebug() << "Key_Shift";
            this->StopGame();
        } break;
#endif
    default : {

        }
    }
}

void GameScene::Update()
{
    if(timeDifficult->elapsed() > 5000) {
        qDebug() << "Up difficult\n";
        timeDifficult->restart();
        GameInfo::UpDiffcult();
    }
}


