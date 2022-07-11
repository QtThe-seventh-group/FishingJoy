#ifndef QPFISH_H
#define QPFISH_H

#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include <synchapi.h>
#include<Windows.h>
class qpfish:public QPixmapItem
{
public:
    qpfish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // QPFISH_H
