#ifndef UIGAMESCREEN_H
#define UIGAMESCREEN_H

#include <QObject>
#include "gamescene.h"
#include "UI/uihealthbar.h"
#include "UI/uiscore.h"

class UIGameScreen : public QObject
{
    Q_OBJECT
public:
    explicit UIGameScreen(GameScene * _scene, QObject *parent = 0);

    GameScene * scene;
    UIHealthBar * health_bar;
    UIScore * score_bar;


signals:

public slots:
    void Hide();
    void Show();
};

#endif // UIGAMESCREEN_H
