#include "widget.h"
#include "ui_widget.h"
#include<helpchoosewidget.h>
#include<QMessageBox>
#include<QPushButton>
#include<QIcon>
#include<QVBoxLayout>
#include"choosewidget.h"
#include<Windows.h>
#include<QSound>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"voice.h"
#include"qfish.h"
#include "white.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QMediaPlaylist *musicList = new QMediaPlaylist(this);
    musicList->addMedia(QUrl("qrc:/backmusic.mp3"));
    QMediaPlayer *soundplayer =new QMediaPlayer(this);
    soundplayer->setPlaylist(musicList);
    soundplayer->play();
    musicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);
    //finish1=new finishwidget;
    label=new QLabel(this);
    label->setPixmap(QPixmap(":/label.png"));//标题窗口
    btn1=new QPushButton(this);
    btn1->setIcon(QIcon(":/secondbtn.png"));
    btn1->setIconSize(QSize(192,37));
    btn1->setFlat(true);
    btn1->setFocusPolicy(Qt::NoFocus);
    btn2=new QPushButton(this);
    btn2->setIcon(QIcon(":/secondbtn8.png"));
    btn2->setIconSize(QSize(192,37));
    btn2->setFlat(true);
    btn2->setFocusPolicy(Qt::NoFocus);
    btn3=new QPushButton(this);
    btn3->setIcon(QIcon(":/secondbtn7.png"));
    btn3->setIconSize(QSize(192,37));
    btn3->setFlat(true);
    btn3->setFocusPolicy(Qt::NoFocus);
    btn4=new QPushButton(this);
    btn4->setIcon(QIcon(":/secondbtn9.png"));
    btn4->setIconSize(QSize(192,37));
    btn4->setFlat(true);
    btn4->setFocusPolicy(Qt::NoFocus);
    box=new QVBoxLayout(this);
    box->addWidget(label);
    box->addWidget(btn1);
    box->addWidget(btn2);
    box->addWidget(btn3);
    box->addWidget(btn4);
    box->setAlignment(Qt::AlignCenter);
    //connect(btn1,SIGNAL(clicked()),this,SLOT(hide()));
    connect(btn1,SIGNAL(clicked()),this,SLOT(startclick()));
    connect(btn2,SIGNAL(clicked()),this,SLOT(helpclick()));
    connect(btn3,SIGNAL(clicked()),this,SLOT(listenclick()));
    connect(btn4,SIGNAL(clicked()),this,SLOT(finishclick()));
    connect(help.helpbtn3,SIGNAL(clicked()),this,SLOT(show()));
    connect(lis.openbutton,&QPushButton::clicked,this,[=](){
        soundplayer->play();
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("音效已开启！"),QMessageBox::Yes))
        {
            closelisten=0;
            lis.close();
        }
    });
    connect(lis.closebutton,&QPushButton::clicked,this,[=](){
        soundplayer->stop();
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("音效已关闭！"),QMessageBox::Yes))
        {
            lis.close();
            closelisten=1;
        }
    });
    connect(lis.closebutton1,&QPushButton::clicked,this,[=](){
        soundplayer->stop();
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("背景音效已关闭！"),QMessageBox::Yes))
        {
            lis.close();
        }
    });
}
void Widget::startclick()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    this -> hide();
    easyview = new Easyview;
    connect(easyview->shop,SIGNAL(clicked()),this,SLOT(shopclick()));//
    connect(easyview->level,SIGNAL(clicked()),this,SLOT(improvelevel()));
    connect(easyview->quitev,SIGNAL(clicked()),this,SLOT(show()));
    easyview -> show();
}
void Widget::helpclick()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    this->hide();
    help.show();
}
void Widget::finishclick()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
   if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否退出游戏？"),QMessageBox::Yes|QMessageBox::No))
   {
       this->close();
   }
}
void Widget::improvelevel()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    if(this->easyview->levelmoney==0)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否确认升级? "),QMessageBox::Yes|QMessageBox::No))
        {
            if(nowmoney>=5000)
            {
                QMessageBox::question(this,tr("提示 "),tr("升级成功!"),QMessageBox::Yes);
//               easyview->moneyscore=easyview->moneyscore-5000;
                nowmoney=nowmoney-5000;
                this->easyview->updata();
                this->easyview->choose2=1;
                choose_g=2;
                this->easyview->gun->pixmap.load("://image/purple_gun.png");
                this->easyview->levelmoney=1;
            }
            else
                QMessageBox::question(this,tr("提示 "),tr("金币不足 "),QMessageBox::Yes);
        }
    }
    else
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("您已升至最高等级！"),QMessageBox::Yes|QMessageBox::No))
        {

        }
    }
}
void Widget::bugclick()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    if(this->easyview->buymoney1==0)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否确认购买? "),QMessageBox::Yes|QMessageBox::No))
        {
            if(nowmoney>=5000)
            {
                QMessageBox::question(this,tr("提示 "),tr("购买成功! "),QMessageBox::Yes);
                //easyview->moneyscore=easyview->moneyscore-5000;
                nowmoney=nowmoney-5000;
                easyview->gun->pixmap.load(":/lgun2.png");
                easyview->updata();
                this->easyview->buymoney1=1;
            }
            else
                QMessageBox::question(this,tr("提示 "),tr("金币不足 "),QMessageBox::Yes);
        }
    }
    else
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("您已购买，是否应用？ "),QMessageBox::Yes|QMessageBox::No))
        {
            easyview->gun->pixmap.load(":/lgun2.png");
        }
    }

}
void Widget::bugclick1()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    if(this->easyview->buymoney2==0)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否确认购买? "),QMessageBox::Yes|QMessageBox::No))
        {
            if(nowmoney>=8000)
            {
                QMessageBox::question(this,tr("提示 "),tr("购买成功! "),QMessageBox::Yes);
                //easyview->moneyscore=easyview->moneyscore-8000;
                 nowmoney=nowmoney-8000;
                easyview->gun->pixmap.load(":/lgun5.png");
                easyview->updata();
                this->easyview->buymoney2=1;
            }
            else
                QMessageBox::question(this,tr("提示 "),tr("金币不足 "),QMessageBox::Yes);
        }
    }
    else
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("您已购买，是否应用？ "),QMessageBox::Yes|QMessageBox::No))
        {
            easyview->gun->pixmap.load(":/lgun5.png");
        }
    }

}
void Widget::bugclick2()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    if(this->easyview->buymoney3==0)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否确认购买? "),QMessageBox::Yes|QMessageBox::No))
        {
            if(nowmoney>=15000)
            {
                QMessageBox::question(this,tr("提示 "),tr("购买成功! "),QMessageBox::Yes);
                //easyview->moneyscore=easyview->moneyscore-15000;
                nowmoney=nowmoney-15000;
                easyview->gun->pixmap.load(":/lgun4.png");
                easyview->updata();
                this->easyview->buymoney3=1;
            }
            else
                QMessageBox::question(this,tr("提示 "),tr("金币不足 "),QMessageBox::Yes);
        }
    }
    else
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("您已购买，是否应用？ "),QMessageBox::Yes|QMessageBox::No))
        {
            easyview->gun->pixmap.load(":/lgun4.png");
        }
    }
}
void Widget::bugclick3()
{
//    if(QMessageBox::Yes==QMessageBox::question(this,tr(" 提示 "),tr(" 是否确认购买？"),QMessageBox::Yes|QMessageBox::No))
//    {
//       QMessageBox::question(this,tr(" 提示 "),tr(" 购买成功 "),QMessageBox::Yes);
//    }
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    if(this->easyview->buymoney4==0)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否确认购买? "),QMessageBox::Yes|QMessageBox::No))
        {
            if(nowmoney>=20000)
            {
                QMessageBox::question(this,tr("提示 "),tr("购买成功! "),QMessageBox::Yes);
                //easyview->moneyscore=easyview->moneyscore-20000;
                nowmoney=nowmoney-20000;
                easyview->gun->pixmap.load(":/lgun1.png");
                easyview->updata();
                this->easyview->buymoney4=1;
            }
            else
                QMessageBox::question(this,tr("提示 "),tr("金币不足 "),QMessageBox::Yes);
        }
    }
    else
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("您已购买，是否应用？ "),QMessageBox::Yes|QMessageBox::No))
        {
            easyview->gun->pixmap.load(":/lgun1.png");
        }
    }

}
void Widget::shopclick()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
        goldshop=new goldshopwidget;
        goldshop->show();
        connect(goldshop->bugbtn1,SIGNAL(clicked()),this,SLOT(bugclick()));
        connect(goldshop->bugbtn2,SIGNAL(clicked()),this,SLOT(bugclick1()));
        connect(goldshop->bugbtn3,SIGNAL(clicked()),this,SLOT(bugclick2()));
        connect(goldshop->bugbtn4,SIGNAL(clicked()),this,SLOT(bugclick3()));
}
void Widget::listenclick()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    lis.show();
}

Widget::~Widget()
{
    delete ui;
}
