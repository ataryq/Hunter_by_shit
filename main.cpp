#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMainWindow>

#include "gamescene.h"
#include "myview.h"
#include "Regs.h"
#include "animationplayer.h"
#include "gamemain.h"
#include "gameinfo.h"


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     GameMain game;
     game.show();


     return app.exec();
}
