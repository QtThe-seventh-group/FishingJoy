#include "easyview.h"
#include<Windows.h>
using namespace std;

Easyview::Easyview(QWidget *parent)
    :QGraphicsView(parent)
{
//    this->resize(932,580);
    this->setFixedSize(1920,1000);//使窗口大小固定
    this->setWindowTitle("捕鱼达人");
//    this->setAutoFillBackground(true);
    this->setWindowIcon(QIcon("://image/topic_p.png"));//设置窗口的图标
    this->setMouseTracking(true);
    this -> setBackgroundBrush(QBrush(QPixmap("://image/background")));
    scene = new QGraphicsScene;
    scene -> setSceneRect(0,0,this->width()-2,this->height()-2);
    this -> setScene(scene);

    //大炮
    gun = new QGun("://image/yellow_gun",scene);
    gun -> setPos(this->width()/2,this->height());
    //scene ->addItem(gun);

    //鱼
    //鲨鱼
    int set_b = qrand() % 20;
    for(int i=0;i<4;i++)
    {
        fish[i] = new  QFish("://image/fish/b_shark1",scene);
        fish[i] -> setPos(- set_b * 10,260+100*i);
    }
    //定时器
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer -> start(100);


    //小紫鱼
    //1群
    int set_p = qrand() % 10;
    for(int i=0;i<7;i++)
    {
        pfish[i] = new  qpfish("://image/fish/p_fish1.png",scene);
        pfish[i] -> setPos(0,set_p *30+i*10);
    }
    timerp1 = new QTimer;
    connect(timerp1,SIGNAL(timeout()),scene,SLOT(advance()));
    timerp1 -> start(100);
    //2群
    int set_p2 = qrand() % 10;
    for(int i=0;i<9;i++)
    {
        pfish2[i] = new  qpfish("://image/fish/p_fish1.png",scene);
        pfish2[i] -> setPos(-1000,set_p2 *30+i*10);
    }
    timerp2 = new QTimer;
    connect(timerp2,SIGNAL(timeout()),scene,SLOT(advance()));
    timerp2 -> start(100);
    //3群
    int set_p3 = qrand() % 10;
    for(int i=0;i<5;i++)
    {
        pfish3[i] = new  qpfish("://image/fish/p_fish1.png",scene);
        pfish3[i] -> setPos(-2000,set_p3 *30+i*10);
    }
    timerp3 = new QTimer;
    connect(timerp3,SIGNAL(timeout()),scene,SLOT(advance()));
    timerp3 -> start(100);


    //飞鱼
    int set_f1 = qrand() % 10;
    for(int i=0;i<7;i++)
    {
        ffish[i] = new  Qffish("://image/fish/ffish1.png",scene);
        ffish[i] -> setPos(0,set_f1 *42+i*10);
    }
    timerf1 = new QTimer;
    connect(timerf1,SIGNAL(timeout()),scene,SLOT(advance()));
    timerf1 -> start(100);
    //定时器
//    timer = new QTimer;
//    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
//    timer -> start(100);

}
int Easyview::changegun=0;
int Easyview::choose1=0;
int Easyview::choose2=0;
void Easyview::resizeEvent(QResizeEvent *event)
{
//    this -> setBackgroundBrush(QBrush(QPixmap("://image/background.png").scaled(event->size())));
    this->setBackgroundBrush(QBrush(QPixmap("://image/background.png").scaled(event->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    gun -> setPos(this->width()/2,this->height());//自动调整炮的位置

}

void Easyview::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p;
    p=event->pos();

    //画线
    QLine line(this->width()/2,this->height(),p.x(),p.y());
    QLineF linef(line);
    gun->setRotation(-(linef.angle()-90));

//    qDebug("angle:%f\n",-(linef.angle()-90));
    if(1/*金币达到一定值*/)
    {
        if(choose1==0)
        {
            if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否花费xx金币购买炮台？购买后可以在两种炮台间切换"),QMessageBox::Yes|QMessageBox::No))
            {
                choose2=1;
            }
            choose1=1;
        }
    }
}

void Easyview::mousePressEvent(QMouseEvent *event)
{
    QPoint p=event->pos();
    QLineF linef(this->width()/2,this->height(),p.x(),p.y());
if(changegun==0)
{
    QBullet *bullet=new QBullet("://image/bullet1.png",scene,linef.angle());
}
else
{
    QBullet *bullet=new QBullet("://image/bullet2.png",scene,linef.angle());
}
}

void Easyview::keyPressEvent(QKeyEvent *event)
 {
    if(choose2==1)
    {
        QPointF p(0,0);
          switch (event->key())
            {
            case Qt::Key_G:
          changegun++;
              if(changegun==2)
              {
                  changegun=0;
              }
              gun->changegun();
              break;
            default:
              break;
            }
    }
 }
