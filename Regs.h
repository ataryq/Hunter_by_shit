#ifndef REGS_H
#define REGS_H

#include <QDebug>
#include <Qt>
#include <qmath.h>

//#define DEBUG_MODE

const int SCENE_W = 800;
const int SCENE_H = 700;

const int P_X = 150;
const int P_Y = 500;
const int P_W = 50;
const int P_H = 50;

const int J_X = 150;
const int J_Y = -25;

const int BORDER_LEFT = 50;
const int BORDER_RIGHT = SCENE_W - 200;

struct ANIM {
    enum ANIM_ALL {MOVE, EAT, STOP, IDLE};
    enum _ANIM_TYPE {FALLING, FELL_OFF};
};

struct TYPE_ENEMY {
    enum _TYPE_ENEMY {SIMPLE_SHIT, DIARRHEA, SPOON, HEALTH_POINT};
};

struct Circle {
    Circle(qreal _r, qreal _x, qreal _y) : r(_r), x(_x), y(_y){}
    Circle(){}
    qreal r;
    qreal x;
    qreal y;
};

#endif // REGS_H
