#include "uirecords.h"
#include <QDebug>
#include <QSize>
#include <QSizePolicy>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QWidget>
#include <QFont>

#include "qgraphicsscene.h"
#include "../gamemain.h"
#include "../httprequest.h"

UIRecords::UIRecords(QObject *parent) :
    QObject(parent)
{
}

UIRecords::UIRecords(GameScene *_scene)
{
    scene = _scene;
    recordSreen = new UIRecordScreen();
    scene->addItem(recordSreen);
    recordSreen->draw_records = &records;

    btn_back = CreateBtn("Back");
    QObject::connect( btn_back, SIGNAL(pressed()), this, SLOT(BackClick()) );
    btn_back->move(100, 500);
    scene->addWidget(btn_back);

    GetResultFromGlobalTable();

    Hide();
}

QPushButton *UIRecords::CreateBtn(QString textBtn, QString pathImg)
{
    QPushButton * btn = new QPushButton;

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

void UIRecords::Hide() {
    recordSreen->hide();
    btn_back->hide();
}

void UIRecords::Show() {
    recordSreen->show();
    btn_back->show();
    GetResultFromGlobalTable();
}

void UIRecords::BackClick()
{
    ChooseMaked(GameMain::GAME_STATE::MENU);
}

void UIRecords::GetResultFromGlobalTable() {
    qDebug() << "try getting result glob table \n";
    static HttpRequest * getReq = new HttpRequest;
    QObject::connect( getReq, SIGNAL(finishLoading(QString)),
                      this, SLOT(RecordsLoadFinish(QString)) );
    getReq->processRequest("http://atary2sa.bget.ru/get_records.php");
}

void UIRecords::RecordsLoadFinish(QString result) {
    qDebug() << "RecordsLoadFinish " << result;
    QStringList list = result.split("|");
    records.clear();
    for(int i = 0; i < list.size(); i++) {
        if(i == 0) continue;
        records.push_back(list.at(i));
    }
}
