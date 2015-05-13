#include "myview.h"
#include <QKeyEvent>
#include <QEvent>
#include <QDebug>

MyView::MyView(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{

}
