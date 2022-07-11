#include "easyview.h"
#include<Windows.h>
#include"white.h"
Easyview::Easyview(QWidget *parent)
    :QGraphicsView(parent)
{
    //moneyscore=20000;
    //nowmoney=20000;
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
    money = new QGun("://gold2.png",scene);
    gun -> setPos(this->width()/2,this->height());
    money->setPos(this->width()/2+200,this->height()-20);
    //scene ->addItem(gun);
    shop=new QPushButton(this);
    shop->setIcon(QIcon(":/shop3.png"));
    shop->setIconSize(QSize(120,120));
    shop->setFlat(true);
    shop->setFocusPolicy(Qt::NoFocus);
    shop->move(100,850);
    level=new QPushButton(this);
    level->setIcon(QIcon(":/ogun3.png"));
    level->setIconSize(QSize(120,120));
    level->setFlat(true);
    level->setFocusPolicy(Qt::NoFocus);
    level->move(300,850);
    quitev=new QPushButton(this);
    quitev->setIcon(QIcon(":/secondbtn9.png"));
    quitev->setIconSize(QSize(197,46));
    quitev->setFlat(true);
    quitev->setFocusPolicy(Qt::NoFocus);
    quitev->move(1700,900);
    //connect(shop,SIGNAL(clicked()),this,SLOT(hide()));
    connect(shop,SIGNAL(clicked()),this,SLOT(shopclick1()));
    connect(finish.finishbtn2,SIGNAL(clicked()),this,SLOT(show()));
    connect(finish.finishbtn2,SIGNAL(clicked()),&finish,SLOT(hide()));
     connect(quitev,SIGNAL(clicked()),this,SLOT(hide()));

    //scene ->addItem(gun);
    QString str=QString::number(nowmoney,10);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    setStyleSheet("color:yellow;");
    lab=new QLabel("4000                  ",this);
    lab->setPalette(pa);
    QFont ft;
    ft.setFamily("Consolas");
    ft.setBold(true);
    ft.setPointSize(20);
    lab->setContentsMargins(30,0,0,0);
    lab->setFont(ft);
    lab->move(1170,940);
    //鱼
    //鲨鱼
    int set_b = qrand() % 20;
    for(int i=0;i<4;i++)
    {
        fish[i] = new  QFish("://image/fish/b_shark1",scene);
        fish[i] -> setPos(- set_b * 10,260+100*i);
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
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
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
    timerp1 = new QTimer;
    connect(timerp1,SIGNAL(timeout()),scene,SLOT(advance()));
    timerp1 -> start(100);
    //2群
    int set_p2 = qrand() % 10;
    for(int i=0;i<9;i++)
    {
        pfish2[i] = new  qpfish("://image/fish/p_fish1.png",scene);
        pfish2[i] -> setPos(-1000,set_p2 *30+i*10);
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
    timerp2 = new QTimer;
    connect(timerp2,SIGNAL(timeout()),scene,SLOT(advance()));
    timerp2 -> start(100);
    //3群
    int set_p3 = qrand() % 10;
    for(int i=0;i<5;i++)
    {
        pfish3[i] = new  qpfish("://image/fish/p_fish1.png",scene);
        pfish3[i] -> setPos(-2000,set_p3 *30+i*10);
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
    timerp3 = new QTimer;
    connect(timerp3,SIGNAL(timeout()),scene,SLOT(advance()));
    timerp3 -> start(100);


    //飞鱼
    int set_f1 = qrand() % 10;
    for(int i=0;i<4;i++)
    {
        ffish[i] = new  Qffish("://image/fish/ffish1.png",scene);
        ffish[i] -> setPos(0,set_f1 *42+i*10);
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
    timerf1 = new QTimer;
    connect(timerf1,SIGNAL(timeout()),scene,SLOT(advance()));
    timerf1 -> start(100);

    //小蓝鱼
    int set_b1 = qrand() % 15;
    for(int i=0;i<3;i++)
    {
        bfish[i] = new  qbfish("://image/fish/d0001.png",scene);
        bfish[i] -> setPos(0,set_b1 *50+i*10);
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
    timerb = new QTimer;
    connect(timerb,SIGNAL(timeout()),scene,SLOT(advance()));
    timerb -> start(100);
    //金鲨鱼
    int set_g = qrand() % 10;
    for(int i=0;i<2;i++)
    {
        gfish[i] = new  qgfish("://image/fish/fish28_0001.png",scene);
        gfish[i] -> setPos(-1000,set_g *30+i*10);
        //moneyscore=nowmoney;
        //updata();
    }
    //updata();
    timerg = new QTimer;
    connect(timerg,SIGNAL(timeout()),scene,SLOT(advance()));
    timerg -> start(100);

}
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

    qDebug("angle:%f\n",-(linef.angle()-90));
//    if(1)
//    {
//        if(choose1==0)
//        {
//            if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否花费xx金币购买炮台？购买后可以在两种炮台间切换"),QMessageBox::Yes|QMessageBox::No))
//            {
//                choose2=1;
//            }
//            choose1=1;
//        }
//    }
}
void Easyview::updata()
{
    QString str=QString::number(nowmoney,10);
    this->lab->setText(str);
}
void Easyview::mousePressEvent(QMouseEvent *event)
{
    QPoint p=event->pos();
    QLineF linef(this->width()/2,this->height(),p.x(),p.y());

    if(choose_g==1)
    {
        QBullet *bullet=new QBullet("://image/bullet1.png",scene,linef.angle());
    }
    else
    {
        QBullet *bullet=new QBullet("://image/bullet2.png",scene,linef.angle());
    }
    if(choose2==1)
    {
        nowmoney=nowmoney-100;
    }
    else
    {
        nowmoney=nowmoney-50;
    }
    this->updata();
    if(nowmoney<0)
    {
        this->hide();
        finish.show();
        //this->moneyscore=this->moneyscore+2050;
        nowmoney=4000;
        this->updata();
        this->buymoney1=0;
        this->buymoney2=0;
        this->buymoney3=0;
        this->buymoney4=0;
        this->levelmoney=0;
        this->gun->pixmap.load("://image/yellow_gun.png");
        choose_g=1;
        choose2=0;
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
          choose_g++;
              if(choose_g==3)
              {
                  choose_g=1;
              }
              gun->changegun();
              break;
            default:
              break;
            }
    }
 }
