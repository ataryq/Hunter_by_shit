#ifndef UIRECORDSCREEN_H
#define UIRECORDSCREEN_H

#include <QGraphicsItem>
#include <QVector>
#include <QString>

class UIRecordScreen : public QGraphicsItem
{
public:
    UIRecordScreen();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QVector<QString> *draw_records;
};

#endif // UIRECORDSCREEN_H
