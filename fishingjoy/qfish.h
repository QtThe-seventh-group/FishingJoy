#ifndef QFISH_H
#define QFISH_H

#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include<Windows.h>
extern int nowmoney;

class QFish:public QPixmapItem
{

public:
    QFish(const QString & fileName,QGraphicsScene *scene);
    virtual void advance(int phase);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void fish_death();
    int blood;
    int mark;

};

#endif // QFISH_H
