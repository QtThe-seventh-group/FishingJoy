#ifndef QFFISH_H
#define QFFISH_H

#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include <synchapi.h>
#include<Windows.h>
class Qffish:public QPixmapItem
{
public:
    Qffish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // QFFISH_H
