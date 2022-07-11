#include "qfish.h"
#include<Windows.h>
QFish::QFish(const QString & fileName,QGraphicsScene *scene):QPixmapItem(fileName,scene)
{

}
void QFish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    char filename[50]="0";
    static int i=2;
    if(i == 12)
    {
        i = 1;
    }
    sprintf(filename,"://image/fish/b_shark%d.png",i++);
    pixmap.load(filename);
    painter ->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
void QFish::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=1920||mapToScene(0,0).y()>=1000)
    {
        setPos(-130-qrand()%1000,280+qrand()%300);
    }
    int speed = qrand()%6;
    int angle = qrand()%5;
    int angle_ = qrand()%5;
    this -> setPos(mapToScene(speed-1,angle - angle_));
//    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=932)
//    {
//        setPos(-130,100+qrand()%320);
//    }
//    int speed = qrand()%20;
//    int angle = -qrand()%4;
//    if(angle % 2 == 0)
//    {
//        angle = -angle;
//    }
//    this -> setPos(mapToScene(speed,angle));
}

void QFish::fish_death()
{
    setPos(-130,200+qrand()%300);
}
