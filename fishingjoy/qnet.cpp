#include "qnet.h"
#include<Windows.h>
QNet::QNet(const QString & fileName,QGraphicsScene *scene):QPixmapItem(fileName,scene)
{

}
 void QNet::advance(int phase)
 {
     if(this->collidingItems().count()>0)
     {
         QList<QGraphicsItem*>list=this->collidingItems();
         QList<QGraphicsItem*>::Iterator i;
         QFish *fish;
         i=list.begin();
         while(i!=list.end())
         {
             fish=(QFish*)(*i);
             fish->fish_death();
             i++;
         }
     }
     this->hide();
     delete this;
 }
