#ifndef UIABOUTGAME_H
#define UIABOUTGAME_H

#include <QObject>
#include <QPushButton>

#include "../gamescene.h"
#include "aboutgamegrit.h"
#include "../gameinfo.h"

class UIAboutGame : public QObject
{
    Q_OBJECT
public:
    explicit UIAboutGame(QObject *parent = 0);
    UIAboutGame(GameScene *_scene);
    ~UIAboutGame();
    void Hide();
    void Show();
protected:
    AboutGameGrIt * grIt;
    GameScene *scene;
    QPushButton * btn_back;

signals:
    void ChooseMaked(int choose);

public slots:
    void BackClick();
};

#endif // UIABOUTGAME_H
