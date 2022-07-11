#include "qpfish.h"
#include<Windows.h>
qpfish::qpfish(const QString & fileName,QGraphicsScene *scene):QPixmapItem(fileName,scene)
{

}
void qpfish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    char filename[50]="0";
    static int i=2;
    if(i == 12)
    {
        i = 1;
    }
    sprintf(filename,"://image/fish/p_fish%d.png",i++);
    pixmap.load(filename);
    painter ->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
void qpfish::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=1920||mapToScene(0,0).y()>=1000)
    {
        setPos(-130,180+qrand()%30);
    }
    int speed = qrand()%3;
    int angle = qrand()%2+2;
    if(angle % 2 == 0)
    {
        angle = -angle;
    }
    this -> setPos(mapToScene(speed+4,angle));
}
