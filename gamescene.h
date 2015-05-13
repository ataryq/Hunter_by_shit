#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>

#include "player.h"
#include "jopa.h"
#include "ShitType/generateshit.h"
#include "Regs.h"
#include "OtherItem/generateotheritems.h"
#include <QTimer>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = 0);
    void drawBackground ( QPainter * painter, const QRectF & rect );
    void StopGame();
    void StartGame();
    void ResetGame();

    void Hide();
protected:
    void advance(int step);
    void keyPressEvent(QKeyEvent *keyEvent);

    void keyReleaseEvent(QKeyEvent *keyEvent);
private:
    Player * player;
    Jopa * jopa;
    GenerateShit * gener;
    GenerateOtherItems * generOtherItem;
    QPixmap imgSource;
    bool isActive;
    QTime * timeDifficult;
    bool isDrawBackground;

signals:
    void FinishGame();
    void HideScene();
    void ShowScene();
public slots:
    void Update();
};

#endif // GAMESCENE_H
