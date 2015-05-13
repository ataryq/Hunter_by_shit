#include "gameinfo.h"
#include "httprequest.h"

GameInfo::GameInfo(QObject *parent) :
    QObject(parent)
{
}

qreal GameInfo::health = 100;
qreal GameInfo::weight_shits = 0;
qreal GameInfo::difficult = 1.0;
bool GameInfo::pressSpace = false;
QString GameInfo::InputText;
int GameInfo::strategy = TYPE_STRATEGY::BEGIN;
XmlInfo * GameInfo::xmlInfo = new XmlInfo();
QString BD::Adress          = "http://atary2sa.bget.ru/";
QString BD::AdressScriptGet = "get_records.php";
QString BD::AdressScriptSet = "set_records.php";

void GameInfo::SubstractHealth(qreal _health){
    if((health - _health) >= 0 &&
#ifdef DEBUG_MODE
            (health - _health) <= 1000)
#else
            (health - _health) <= 100)
#endif
        health -= _health;
    else {
        if( (health - _health) < 0 ) health = 0;
        else health = 100;
    }
}

void GameInfo::SendResultInGlobalTable(QString name, int score, QString other_info) {

    static HttpRequest * getSeq = new HttpRequest;
    qDebug() << "send result";
    getSeq->processRequest(BD::Adress + BD::AdressScriptSet +
                       "?name=" + name + "&score=" +
                       QString::number(score) + "&other_info=" +
                       ((other_info == NULL) ? "" : other_info) );
}

XmlInfo::XmlInfo()
{
    file = new QFile(":/immage/img/img.xml");

    if(file->open(QIODevice::ReadOnly)) {
        if(!domDoc.setContent(file))
            qDebug() << "file was not parse! \n";
        else qDebug() << "parse OK!";
    } else {
        file->close();
        if(file->open(QIODevice::ReadOnly)) {
            if(!domDoc.setContent(file))
                qDebug() << "file was not parse! \n";
        } else qDebug() << "file was not open! \n";
    }
}

QVector<QString> XmlInfo::GetPathImgs(int _typeItem, int _typeAnim, int &speed)
{
    QDomNode domNode = domDoc.firstChild().firstChild();

    QVector<QString> pathImgs;

    QString typeItem;
    QString typeAnim;

    QString str_speed;

    switch(_typeItem)
    {
        case TYPE_ENEMY::SIMPLE_SHIT  : typeItem = "SIMPLE_SHIT";  break;
        case TYPE_ENEMY::DIARRHEA     : typeItem = "DIARRHEA";     break;
        case TYPE_ENEMY::SPOON        : typeItem = "SPOON";        break;
        case TYPE_ENEMY::HEALTH_POINT : typeItem = "HEALTH_POINT"; break;
    }

    switch(_typeAnim)
    {
        case ANIM::FALLING  : typeAnim = "FALLING";  break;
        case ANIM::FELL_OFF : typeAnim = "FELL_OFF"; break;
    }

    while(!domNode.isNull())
    {
        if(domNode.nodeName() == typeItem)
        {
            QDomNode child_1 = domNode.firstChild();
            while(!child_1.isNull())
            {
                if(child_1.nodeName() == typeAnim)
                {
                    str_speed = child_1.toElement().attribute("speed");
                    if(str_speed != "") speed = str_speed.toInt();
                    QDomNode child_2 = child_1.firstChild();
                    while (!child_2.isNull())
                    {
                        pathImgs.push_back(child_2.toElement().attribute("path"));
                        child_2 = child_2.nextSibling();
                    }
                }
                child_1 = child_1.nextSibling();
            }
        }
        domNode = domNode.nextSibling();
    }

    return pathImgs;
}

