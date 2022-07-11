#include "qbullet.h"
#include<Windows.h>
#include"white.h"
QBullet::QBullet(const QString & fileName,QGraphicsScene *scene,qreal angle):QPixmapItem(fileName,scene)
{
    this->scene=scene;
    qreal dx,dy;

    qreal rad;
    rad=angle*3.14/180;
    dx=195*cos(rad);
    dy=195*sin(rad);//需要比190稍微大一些

    this->setPos(scene->width()/2+dx,scene->height()-dy);
    this->setRotation(90-angle);
}

void QBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter ->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
    if(closelisten==0)
    {
        QSound::play(":/bulletmusic .wav");
    }
    if(this->collidingItems().count()>0)
        {
            docolliding();
        }
}
void QBullet::advance(int phase)
{
    if(mapToScene(0,0).x()<=0||mapToScene(0,0).x()>=1920||mapToScene(0,0).y()<=0)//1920是窗口宽度
    {
        delete this;
    }
    else
    {
        this->setPos(mapToScene(0,-20));
    }
}

void QBullet::docolliding()
{
    if(choose_g==1)
    {
        QNet *net=new QNet("://image/yellow_net.png",this->scene);
        net->setPos(mapToScene(0,0));
        delete this;
    }
    else
    {
        QNet *net=new QNet("://image/purple_net.png",this->scene);
        net->setPos(mapToScene(0,0));
        delete this;
    }

}
