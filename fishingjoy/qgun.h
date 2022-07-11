#ifndef QGUN_H
#define QGUN_H

#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include"qpixmapitem.h"
#include<QString>
#include<QGraphicsScene>
#include<Windows.h>
#include<QSound>
 extern int choose_g;
class QGun:public QPixmapItem
{
public:
    QGun(const QString & fileName,QGraphicsScene *scene);
    void changegun();
};

#endif // QGUN_H
