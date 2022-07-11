#ifndef QNET_H
#define QNET_H
#include"qpixmapitem.h"
#include "qfish.h"
#include<Windows.h>
class QNet:public QPixmapItem
{
public:
    QNet(const QString & fileName,QGraphicsScene *scene);
    void advance(int phase);
};

#endif // QNET_H
