#include "qgun.h"
#include<Windows.h>
#include "white.h"
int choose_g = 0;
QGun::QGun(const QString & fileName,QGraphicsScene *scene):QPixmapItem(fileName,scene)
{
   choose_g = 1;
}
void QGun::changegun()
{
    if(choose_g==2)
    {
        pixmap.load("://image/purple_gun.png");
        if(closelisten==0)
        {
            QSound *sound =new QSound(":/changegun.wav");
            sound->play();
        }
    }
    else
    {
        pixmap.load("://image/yellow_gun.png");
        if(closelisten==0)
        {
            QSound *sound =new QSound(":/changegun.wav");
            sound->play();
        }
    }
}
