#include "finishgame.h"

#include <QDebug>
#include <QSize>
#include <QSizePolicy>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QWidget>
#include <QFont>
#include <qdialog.h>
#include <QTextBlock>
#include <QLabel>


#include "qgraphicsscene.h"
//#include "httprequest.h"
#include "../gamemain.h"

FinishGame::FinishGame(GameScene *_scene)
{
    scene = _scene;
    finishSreen = new FinishGameScreen();
    scene->addItem(finishSreen);

    btn_back = CreateBtn("Back");
    QObject::connect( btn_back, SIGNAL(pressed()), this, SLOT(BackClick()) );
    btn_back->move(100, 300);

    btn_repeat = CreateBtn("Repeat");
    QObject::connect( btn_repeat, SIGNAL(pressed()), this, SLOT(RepeatClick()) );
    btn_repeat->move(100, 450);

    btn_send_result = CreateBtn("Send Record");
    QObject::connect( btn_send_result, SIGNAL(pressed()), this, SLOT(SendResult()) );
    btn_send_result->move(100, 150);

    field_name = new QLineEdit;
    field_name->move(450, 200);
    field_name->setFont(QFont("Arial", 20));

    scene->addWidget(field_name);

    timer = new QTimer;
    timer->setInterval(50);
    QObject::connect( timer, SIGNAL(timeout()), this, SLOT(InputText()) );
    timer->start();

    is_saved_result = false;

    Hide();
}

void FinishGame::Show()
{
    btn_back->show();
    btn_repeat->show();
    finishSreen->show();
    timer->start();
    btn_send_result->show();
    field_name->show();
    is_saved_result = false;

    GameInfo::InputText.clear();
}

void FinishGame::Hide()
{
    btn_back->hide();
    btn_repeat->hide();
    finishSreen->hide();
    timer->stop();
    btn_send_result->hide();
    field_name->hide();
    GameInfo::InputText.clear();
}

void FinishGame::SendResult()
{
    if(is_saved_result) {
        qDebug() << "result was saved";
        return;
    }
    is_saved_result = true;
    if(field_name->text().size() > 8) field_name->text().chop(field_name->text().size() - 8);
    GameInfo::SendResultInGlobalTable(field_name->text(), GameInfo::GetWeightShits(), "non");
}

void FinishGame::BackClick()
{
    qDebug() << "BackClick ";
    ChooseMaked(GameMain::GAME_STATE::MENU);
}

void FinishGame::RepeatClick()
{
    qDebug() << "RepeatClick ";
    ChooseMaked(GameMain::GAME_STATE::GAME);
}

QPushButton *FinishGame::CreateBtn(QString textBtn, QString pathImg)
{
    QPushButton * btn = new QPushButton;
    scene->addWidget(btn);
    btn->setIconSize(QSize(150, 150));
    btn->setText(textBtn);
    QFont font;
    font.setPointSize(24);
    btn->setFont(font);

    btn->setMinimumSize(300, 100);
    btn->setMaximumSize(301, 101);
    if(pathImg != NULL) btn->setIcon(QIcon(pathImg));
    return btn;
}

void FinishGame::InputText()
{
    qDebug() << GameInfo::InputText;
    if(GameInfo::InputText.size() > 8) return;
    field_name->setText(GameInfo::InputText);
}
