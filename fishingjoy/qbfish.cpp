#include "qbfish.h"
#include<Windows.h>
qbfish::qbfish(const QString & fileName,QGraphicsScene *scene):QFish(fileName,scene)
{
   blood = 3;
   mark = 50;
}
void qbfish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    char filename[50]="0";
    static int i=2;
    if(i == 6)
    {
        i = 1;
    }
    sprintf(filename,"://image/fish/d000%d.png",i++);
    pixmap.load(filename);
    painter ->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
void qbfish::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=1920||mapToScene(0,0).y()>=1000)
    {
        setPos(-130-qrand()%100,270+qrand()%300);
        blood = 3;
    }
    int speed = qrand()%6;
    int angle = qrand()%7;
    int angle_ = qrand()%7;
    this -> setPos(mapToScene(speed,angle - angle_));
}
void qbfish::fish_death()
{
    blood = 3;
    nowmoney=nowmoney+50;
    setPos(-130,200+qrand()%300);
}

