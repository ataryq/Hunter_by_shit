#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QPushButton>
#include "../gamescene.h"
#include "menugrit.h"

class Menu : public QObject
{
    Q_OBJECT
public:
    explicit Menu(QObject *parent = 0);

    void Hide();
    Menu(GameScene * _scene);
    void Show();
protected:
    GameScene * scene;

    QPushButton *CreateBtn(QString textBtn, QString pathImg = NULL);
private:
    QPushButton * btnStart;
    QPushButton * btnExit;
    QPushButton * records;
    QPushButton * aboutGame;
    MenuGrIt * menuGI;

signals:
    void ChooseMaked(int choose);
public slots:
    void PushBtnStart();
    void PushBtnExit();
    void PushBtnAboutGame();
    void PushBtnRecords();
};

#endif // MENU_H
