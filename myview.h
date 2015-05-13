#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MyView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyView(QGraphicsScene *scene, QWidget *parent);
//    bool event(QEvent *event);
signals:
    void KeyPressed_atary(int keyCode);
public slots:

};

#endif // MYVIEW_H
