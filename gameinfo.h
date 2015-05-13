#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <QObject>
#include "Regs.h"
#include <QDebug>
#include <QtXml>
#include <QFile>
#include <QVector>

#include "Regs.h"


class TYPE_STRATEGY {
public:
    enum _TYPE_STRATEGY{BEGIN};
};

class BD {
public:
    static QString Adress;
    static QString AdressScriptGet;
    static QString AdressScriptSet;
};



class TYPE_OBJECT {
public:
    enum _TYPE_OBJECT{OTHER_OBJECT, HEALTH_POINT};
};

class XmlInfo : public QObject
{
    Q_OBJECT
public:
    XmlInfo();

    QVector<QString> GetPathImgs(int _typeItem, int _typeAnim, int &speed);
    int GetSpeed();

private:
    QDomDocument domDoc;
    QFile * file;

signals:
public slots:
};

class GameInfo : public QObject
{
    Q_OBJECT
public:
    explicit GameInfo(QObject *parent = 0);

    static qreal GetHealth() {return health;}
    static void SetHealth(qreal _health){health = _health;}
    static void SubstractHealth(qreal _health);
    static qreal GetWeightShits() {return weight_shits;}
    static void SetWeightShits(qreal _weight_shits){weight_shits = _weight_shits;}
    static void AddWeightShits(qreal _weight_shits){
        qDebug() << "AddWeightShits " << _weight_shits;
        weight_shits += _weight_shits;
    }
    static void UpDiffcult(){
        static qreal ddif = 0.2;
        difficult += ddif;
    }
    static void ResetDiffcult(){difficult = 0.0;}
    static qreal GetDifficult(){return difficult;}
    static int GetStrategy(){return strategy;}
    static void SetStrategy(int _strategy){strategy = _strategy;}

    static void Reset() {
#ifdef DEBUG_MODE
        health = 1000;
#else
        health = 100;
#endif
        weight_shits = 0;
        difficult = 1.0;
        strategy = TYPE_STRATEGY::BEGIN;
    }

    static XmlInfo * xmlInfo;
    static bool pressSpace;
    static QString InputText;

    static void SendResultInGlobalTable(QString name, int score, QString other_info);
private:
    static qreal health;
    static qreal weight_shits;
    static qreal difficult;
    static int strategy;

signals:
public slots:

};

#endif // GAMEINFO_H
