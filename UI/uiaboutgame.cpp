#include "uiaboutgame.h"
#include "../gamemain.h"
#include "uirecords.h"

UIAboutGame::UIAboutGame(QObject *parent) : QObject(parent)
{

}

UIAboutGame::UIAboutGame(GameScene *_scene)
{
    scene = _scene;
    grIt = new AboutGameGrIt;
    scene->addItem(grIt);

    btn_back = UIRecords::CreateBtn("Back");
    QObject::connect( btn_back, SIGNAL(pressed()), this, SLOT(BackClick()) );
    btn_back->move(100, 500);
    scene->addWidget(btn_back);
}

void UIAboutGame::Hide()
{
    grIt->hide();
    btn_back->hide();
}

void UIAboutGame::Show()
{
    grIt->show();
    btn_back->show();
}

void UIAboutGame::BackClick()
{
    ChooseMaked(GameMain::GAME_STATE::MENU);
}

UIAboutGame::~UIAboutGame()
{

}
