#ifndef UIRECORDS_H
#define UIRECORDS_H

#include <QWidget>
#include <QPushButton>

#include "../gamescene.h"
#include "../finishgamescreen.h"
#include "uirecordscreen.h"


class UIRecords : public QObject
{
    Q_OBJECT
public:
    explicit UIRecords(QObject *parent);
    UIRecords(GameScene *_scene);

    GameScene * scene;
    UIRecordScreen * recordSreen;
    void Hide();
    void Show();

    void GetResultFromGlobalTable();
    static QPushButton *CreateBtn(QString textBtn, QString pathImg = NULL);
protected:

    QPushButton * btn_back;
    QVector< QString > records;

signals:
    void ChooseMaked(int choose);
public slots:

    void BackClick();
    void RecordsLoadFinish(QString result);
};

#endif // UIRECORDS_H
