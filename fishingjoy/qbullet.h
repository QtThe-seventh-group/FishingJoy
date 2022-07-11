#ifndef QBULLET_H
#define QBULLET_H
#include "qpixmapitem.h"
#include<QtGui>
#include<QDebug>
#include"qnet.h"
#include<QGraphicsScene>
#include<Windows.h>
#include<QSound>
class QBullet:public QPixmapItem
{
    int debuf = -1;
public:
    QBullet(const QString & fileName,QGraphicsScene *scene,qreal angle);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void docolliding();
private:
    QGraphicsScene *scene;
};

#endif // QBULLET_H
