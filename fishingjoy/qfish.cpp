#include "qfish.h"
#include<Windows.h>
int nowmoney=4000;
int closelisten=0;
QFish::QFish(const QString & fileName,QGraphicsScene *scene):QPixmapItem(fileName,scene)
{
     nowmoney=4000;
     int closelisten=0;
     blood = 5;
     mark = 100;
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
        blood = 5;
    }
    int speed = qrand()%6;
    int angle = qrand()%5;
    int angle_ = qrand()%5;
    this -> setPos(mapToScene(speed-1,angle - angle_));
}

void QFish::fish_death()
{
    blood = 5;
    nowmoney=nowmoney+100;
    setPos(-230,200+qrand()%300);
}

