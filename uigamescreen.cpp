#include "uigamescreen.h"
#include <QGraphicsScene>

UIGameScreen::UIGameScreen(GameScene *_scene, QObject *parent) :
    QObject(parent), scene(_scene)
{
    health_bar = new UIHealthBar();
    scene->addItem(health_bar);
    health_bar->setPos(50, 630);
    health_bar->setZValue(-1);
    score_bar = new UIScore();
    scene->addItem(score_bar);
    score_bar->setZValue(-1);

    QObject::connect( scene, SIGNAL(HideScene()), this, SLOT(Hide()) );
    QObject::connect( scene, SIGNAL(ShowScene()), this, SLOT(Show()) );
}

void UIGameScreen::Hide()
{
    health_bar->hide();
    score_bar->hide();
}

void UIGameScreen::Show()
{
    health_bar->show();
    score_bar->show();
}
