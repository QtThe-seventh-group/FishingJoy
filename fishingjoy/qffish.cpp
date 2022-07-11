#include "qffish.h"
#include<Windows.h>
Qffish::Qffish(const QString & fileName,QGraphicsScene *scene):QFish(fileName,scene)
{
   blood = 2;
   mark = 30;
}
void Qffish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    char filename[50]="0";
    static int i=2;
    if(i == 6)
    {
        i = 1;
    }
    sprintf(filename,"://image/fish/ffish%d.png",i++);
    pixmap.load(filename);
    painter ->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
void Qffish::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=1920||mapToScene(0,0).y()>=1000)
    {
        setPos(-130-qrand()%1000,270+qrand()%300);
        blood = 2;
    }
    int speed = qrand()%6;
    int angle = qrand()%7;
    int angle_ = qrand()%7;
    this -> setPos(mapToScene(speed+1,angle - angle_));
}
void Qffish::fish_death()
{
    blood = 2;
    nowmoney=nowmoney+30;
    setPos(-130,200+qrand()%300);
}

