#ifndef QFFISH_H
#define QFFISH_H

#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include <synchapi.h>
#include<Windows.h>
#include"qfish.h"
class Qffish:public QFish
{
public:
    Qffish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void fish_death();
//signals:
//    void death();
};


#endif // QFFISH_H
