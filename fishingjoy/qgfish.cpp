#include "qgfish.h"
qgfish::qgfish(const QString & fileName,QGraphicsScene *scene):QFish(fileName,scene)
{
   blood = 8;
   mark = 500;
}
void qgfish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    char filename[50]="0";
    static int i=2;
    if(i == 12)
    {
        i = 1;
    }
    if(i <= 9)
    {sprintf(filename,"://image/fish/fish28_000%d.png",i++);}
    else
    {sprintf(filename,"://image/fish/fish28_00%d.png",i++);}
    pixmap.load(filename);
    painter ->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
void qgfish::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=1920||mapToScene(0,0).y()>=1000)
    {
        setPos(-1000-qrand()%1000,270+qrand()%300);
        blood = 8;
    }
    int speed = qrand()%6;
    int angle = qrand()%7;
    int angle_ = qrand()%7;
    this -> setPos(mapToScene(speed-2,angle - angle_));
}
void qgfish::fish_death()
{
    blood = 8;
    nowmoney=nowmoney+500;
    setPos(-1000+qrand()%2000,200+qrand()%300);
}

