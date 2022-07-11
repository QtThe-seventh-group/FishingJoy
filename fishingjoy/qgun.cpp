#include "qgun.h"
#include"easyview.h"
#include<Windows.h>
QGun::QGun(const QString & fileName,QGraphicsScene *scene):QPixmapItem(fileName,scene)
{

}
void QGun::changegun()
{
    if(Easyview::changegun==1)
    {
        pixmap.load("://image/purple_gun.png");
        QSound *sound =new QSound(":/changegun.wav");
        sound->play();
    }
    else
    {
        pixmap.load("://image/yellow_gun.png");
        QSound *sound =new QSound(":/changegun.wav");
        sound->play();
    }
}
