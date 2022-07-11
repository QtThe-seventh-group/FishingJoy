#ifndef QFISH_H
#define QFISH_H

#include"qpixmapitem.h"
#include<QString>
#include<QTimer>
#include<QGraphicsScene>
#include<Windows.h>
class QFish:public QPixmapItem
{
public:
    QFish(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void fish_death();
};

#endif // QFISH_H
