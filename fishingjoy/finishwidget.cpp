#include "finishwidget.h"
#include<QVBoxLayout>
#include<QMessageBox>
#include<QPushButton>
#include<Windows.h>
#include<QSound>
#include"qfish.h"
finishwidget::finishwidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);
    finishbtn1=new QPushButton(this);
    finishbtn1->setIcon(QIcon(":/finishbtn1.png"));
    finishbtn1->setIconSize(QSize(308,77));
    finishbtn1->setFlat(true);
    finishbtn1->setFocusPolicy(Qt::NoFocus);
    finishbtn2=new QPushButton(this);
    finishbtn2->setIcon(QIcon(":/finishbtn5.png"));
    finishbtn2->setIconSize(QSize(192,41));
    finishbtn2->setFlat(true);
    finishbtn2->setFocusPolicy(Qt::NoFocus);
    finishbtn3=new QPushButton(this);
    finishbtn3->setIcon(QIcon(":/secondbtn9.png"));
    finishbtn3->setIconSize(QSize(192,37));
    finishbtn3->setFlat(true);
    finishbtn3->setFocusPolicy(Qt::NoFocus);
    box=new QVBoxLayout(this);
    box->addWidget(finishbtn1);
    box->addWidget(finishbtn2);
    box->addWidget(finishbtn3);
    connect(finishbtn3,SIGNAL(clicked()),this,SLOT(finishclick()));
}
void finishwidget::finishclick()
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
