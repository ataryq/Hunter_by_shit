#include "menu.h"
#include <QDebug>
#include <QSize>
#include <QSizePolicy>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QWidget>
#include <QFont>
#include <QIcon>

#include "qgraphicsscene.h"
#include "../gamemain.h"

Menu::Menu(QObject *parent) :
    QObject(parent)
{
}

void Menu::Hide()
{
    btnStart->hide();
    btnExit->hide();
    menuGI->Hide();
    records->hide();
    aboutGame->hide();
}

void Menu::Show()
{
    btnStart->show();
    btnExit->show();
    menuGI->Show();
    records->show();
    aboutGame->show();
}

Menu::Menu(GameScene *_scene)
{
    scene = _scene;

    menuGI = new MenuGrIt();
    scene->addItem(menuGI);

    btnStart = CreateBtn("Start Game");
//    btnStart->setGeometry(100, 100, 100, 300);
    btnStart->move(100, 100);
    QObject::connect( btnStart, SIGNAL(pressed()), this, SLOT(PushBtnStart()) );

    records = CreateBtn("Records", ":/immage/img/KAKAShKA.png");
    records->move(100, 250);
//    records->setGeometry(100, 250, 100, 300);
    QObject::connect( records, SIGNAL(pressed()), this, SLOT(PushBtnRecords()) );

    aboutGame = CreateBtn("About Game");
    aboutGame->move(100, 400);
//    aboutGame->setGeometry(100, 400, 100, 300);
    QObject::connect( aboutGame, SIGNAL(pressed()), this, SLOT(PushBtnAboutGame()) );

    btnExit = CreateBtn("Exit", ":/immage/img/KAKAShKA.png");
    btnExit->move(100, 550);
//    btnExit->setGeometry(100, 550, 100, 300);
    QObject::connect( btnExit, SIGNAL(pressed()), this, SLOT(PushBtnExit()) );
}

QPushButton * Menu::CreateBtn(QString textBtn, QString pathImg)
{
    QPushButton * btn = new QPushButton;
    scene->addWidget(btn);
    btn->setIconSize(QSize(150, 150));
    btn->setText(textBtn);
    QFont font;
    font.setPointSize(24);
    btn->setFont(font);
    btn->setMinimumSize(300, 100);
//    btn->setMaximumSize(301, 101);
    if(pathImg != NULL) btn->setIcon(QIcon(pathImg));
    return btn;
}

void Menu::PushBtnRecords()
{
    qDebug() << "btn Records press";
    ChooseMaked(GameMain::GAME_STATE::RECORDS);
}

void Menu::PushBtnStart()
{
    qDebug() << "btn press";
    ChooseMaked(GameMain::GAME_STATE::GAME);
}

void Menu::PushBtnExit()
{
    QApplication::exit(0);
}

void Menu::PushBtnAboutGame()
{
    qDebug() << "PushBtnAboutGame press";
    ChooseMaked(GameMain::GAME_STATE::ABOUT_GAME);
}
