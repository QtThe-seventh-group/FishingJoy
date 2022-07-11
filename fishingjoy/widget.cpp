#include "widget.h"
#include "ui_widget.h"
#include<helpchoosewidget.h>
#include<QMessageBox>
#include<QPushButton>
#include<QIcon>
#include<QVBoxLayout>
#include"choosewidget.h"
#include<Windows.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);
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
    connect(btn4,SIGNAL(clicked()),this,SLOT(finishclick()));
    connect(help.helpbtn3,SIGNAL(clicked()),this,SLOT(show()));
}
void Widget::startclick()
{
    this -> hide();
    easyview = new Easyview;
    easyview -> show();
}
void Widget::helpclick()
{
    this->hide();
    help.show();
}
void Widget::finishclick()
{
   if(QMessageBox::Yes==QMessageBox::question(this,tr("提示 "),tr("是否退出游戏？"),QMessageBox::Yes|QMessageBox::No))
   {
       this->close();
   }
}
Widget::~Widget()
{
    delete ui;
}
