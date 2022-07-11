#ifndef QPIXMAPITEM_H
#define QPIXMAPITEM_H

#include<QGraphicsItem>
#include<QPixmap>
#include<QPainter>
#include<QRect>
#include<QRectF>
#include<QString>
#include<QGraphicsScene>
#include<Windows.h>
#include<QResizeEvent>
class QPixmapItem:public QGraphicsItem
{
public:
    QPixmap pixmap;
    QPixmapItem(const QString & fileName,QGraphicsScene *scene);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    static int p;
};

#endif // QPIXMAPITEM_H
