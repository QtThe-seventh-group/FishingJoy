#ifndef QBFISH_H
#define QBFISH_H


#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include <synchapi.h>
#include<Windows.h>
#include"qfish.h"
class qbfish:public QFish
{
public:
    qbfish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void fish_death();
//signals:
//    void death();
};

#endif // QBFISH_H
