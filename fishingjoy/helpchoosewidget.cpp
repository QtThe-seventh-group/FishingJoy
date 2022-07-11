#include "helpchoosewidget.h"
#include<QVBoxLayout>
#include<widget.h>
#include<Windows.h>
#include"white.h"
helpchoosewidget::helpchoosewidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);
    helpbtn1=new QPushButton(this);
    helpbtn1->setIcon(QIcon(":/helpbtn1.png"));
    helpbtn1->setIconSize(QSize(192,37));
    helpbtn1->setFlat(true);
    helpbtn1->setFocusPolicy(Qt::NoFocus);
    helpbtn2=new QPushButton(this);
    helpbtn2->setIcon(QIcon(":/helpbtn2.png"));
    helpbtn2->setIconSize(QSize(192,37));
    helpbtn2->setFlat(true);
    helpbtn2->setFocusPolicy(Qt::NoFocus);
    helpbtn3=new QPushButton(this);
    helpbtn3->setIcon(QIcon(":/helpbtn3.png"));
    helpbtn3->setIconSize(QSize(192,37));
    helpbtn3->setFlat(true);
    helpbtn3->setFocusPolicy(Qt::NoFocus);
    box=new QVBoxLayout(this);
    box->addWidget(helpbtn1);
    box->addWidget(helpbtn2);
    box->addWidget(helpbtn3);
    connect(helpbtn1,SIGNAL(clicked()),this,SLOT(showscore()));\
    connect(helpbtn2,SIGNAL(clicked()),this,SLOT(showrule()));
    connect(helpbtn3,SIGNAL(clicked()),this,SLOT(hide()));

}
void helpchoosewidget::showscore()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    helpscore.show();
}
void helpchoosewidget::showrule()
{
    if(closelisten==0)
    {
        QSound *sound =new QSound(":/pushbutton.wav");
        sound->play();
    }
    helprule.show();
}
