#include "gamemain.h"
#include "gameinfo.h"
#include <QLabel>
#include <QLineEdit>

GameMain::GameMain(QWidget *parent) :
    QMainWindow(parent)
{
    GameState = GAME_STATE::GAME;

    timer = new QTimer();

    scene = new GameScene(timer);
    scene->setSceneRect(0, 0, SCENE_W, SCENE_H);

    view = new MyView(scene, 0);
//    view->showFullScreen();
    view->setMinimumSize(SCENE_W, SCENE_H);
    setCentralWidget(view);
//    this->showFullScreen();

    QObject::connect( this, SIGNAL(UpdateSignal()), scene, SLOT(advance()) );
    QObject::connect( this, SIGNAL(UpdateSignal()), scene, SLOT(Update()) );
    QObject::connect( timer, SIGNAL(timeout()), this, SLOT(Update()) );
    timer->start(1000 / 45);

    uiGame = new UIGameScreen(scene);
    uiGame->Hide();

    finishGame = new FinishGame(scene);
    QObject::connect( finishGame, SIGNAL(ChooseMaked(int)), this, SLOT(SetStateGame(int)) );
    finishGame->Hide();

    menu = new Menu(scene);
    QObject::connect( menu, SIGNAL(ChooseMaked(int)), this, SLOT(SetStateGame(int)) );
    menu->Hide();

    records = new UIRecords(scene);
    QObject::connect( records, SIGNAL(ChooseMaked(int)), this, SLOT(SetStateGame(int)) );
    records->Hide();

    aboutGame = new UIAboutGame(scene);
    QObject::connect( aboutGame, SIGNAL(ChooseMaked(int)), this, SLOT(SetStateGame(int)) );
    aboutGame->Hide();

    SetStateGame(GAME_STATE::MENU);
}

void GameMain::Update()
{
    emit UpdateSignal();
    switch(GameState)
    {
    case GAME_STATE::GAME : {
        if( GameInfo::GetHealth() <= 0 ) {
            SetStateGame(GAME_STATE::FINISH_GAME);
        }
    } break;
    case GAME_STATE::FINISH_GAME : {

    } break;
    case GAME_STATE::MENU : {

    } break;
    case GAME_STATE::ABOUT_GAME : {

    } break;
    }
}

void GameMain::SetStateGame(int new_state)
{
    //reset cur stae
    switch(GameState)
    {
    case GAME_STATE::FINISH_GAME : {
        finishGame->Hide();
    } break;
    case GAME_STATE::GAME : {
        scene->StopGame();
        scene->ResetGame();
        scene->Hide();
    } break;
    case GAME_STATE::MENU : {
        menu->Hide();
    } break;
    case GAME_STATE::RECORDS : {
        records->Hide();
    }break;
    case GAME_STATE::ABOUT_GAME : {
        aboutGame->Hide();
    } break;
    }

    qDebug() << "Set New State";
    //set new state
    switch(new_state)
    {
    case GAME_STATE::FINISH_GAME : {
        GameState = GAME_STATE::FINISH_GAME;
        finishGame->Show();
    } break;
    case GAME_STATE::GAME : {
        GameState = GAME_STATE::GAME;
        scene->ResetGame();
        GameInfo::Reset();
        scene->StartGame();
    } break;
    case GAME_STATE::MENU : {
        menu->Show();
        GameState = GAME_STATE::MENU;
    } break;
    case GAME_STATE::RECORDS : {
        GameState = GAME_STATE::RECORDS;
        records->Show();
    }break;
    case GAME_STATE::ABOUT_GAME : {
        GameState = GAME_STATE::ABOUT_GAME;
        aboutGame->Show();
    } break;
    }
}

