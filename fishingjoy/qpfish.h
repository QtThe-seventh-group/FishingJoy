#ifndef QPFISH_H
#define QPFISH_H

#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include <synchapi.h>
#include<Windows.h>
#include"qfish.h"
class qpfish:public QFish
{
public:
    qpfish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void fish_death();
//signals:
//    void death();
};

#endif // QPFISH_H
