#ifndef QGFISH_H
#define QGFISH_H


#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include <synchapi.h>
#include<Windows.h>
#include"qfish.h"
class qgfish:public QFish
{
public:
    qgfish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void fish_death();
//signals:
//    void death();
};

#endif // QGFISH_H
