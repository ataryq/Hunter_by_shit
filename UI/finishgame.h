#ifndef FINISHGAME_H
#define FINISHGAME_H

#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>


#include "../gamescene.h"
#include "../finishgamescreen.h"
//#include "../httprequest.h"

class FinishGame : public QObject
{
    Q_OBJECT
public:
    FinishGame(GameScene * _scene);

    void Show();
    void Hide();


protected:
    GameScene * scene;
    FinishGameScreen * finishSreen;

    QPushButton *CreateBtn(QString textBtn, QString pathImg = NULL);

    QPushButton * btn_back;
    QPushButton * btn_repeat;
    QPushButton * btn_send_result;
    QLineEdit   * field_name;
    QTimer * timer;
    bool is_saved_result;

signals:
     void ChooseMaked(int choose);
protected slots:
     void InputText();
     void SendResult();
    void BackClick();
    void RepeatClick();
};

#endif // FINISHGAME_H
