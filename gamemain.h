#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "gamescene.h"
#include "myview.h"
#include "Regs.h"
#include "animationplayer.h"
#include "uigamescreen.h"
#include "finishgamescreen.h"
#include "UI/menu.h"
#include "UI/finishgame.h"
#include "UI/uirecords.h"
#include "UI/uiaboutgame.h"

class GameMain : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameMain(QWidget *parent = 0);

    struct GAME_STATE{
        enum _GAME_STATE{GAME, FINISH_GAME, MENU, RECORDS, ABOUT_GAME};
    };

    MyView      * view;
    GameScene   * scene;
    QTimer      * timer;
   UIGameScreen * uiGame;
    FinishGame  * finishGame;
    Menu        * menu;
    UIRecords   * records;
    UIAboutGame * aboutGame;
    int GameState;

signals:
    void UpdateSignal();

public slots:
    void Update();
    void SetStateGame(int new_state);
};

#endif // GAMEMAIN_H
