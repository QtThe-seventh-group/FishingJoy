#include "goldshopwidget.h"
#include<QPushButton>
#include<QBrush>
#include<QPixmap>
goldshopwidget::goldshopwidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1026,752);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/shopback.png")));
    setPalette(palette);
    bugbtn1=new QPushButton(this);
    bugbtn1->setIcon(QIcon(":/ogun1.png"));
    bugbtn1->setIconSize(QSize(700,350));
    bugbtn1->setFlat(true);
    bugbtn1->setFocusPolicy(Qt::NoFocus);
    bugbtn2=new QPushButton(this);
    bugbtn2->setIcon(QIcon(":/ogun2.png"));
    bugbtn2->setIconSize(QSize(700,350));
    bugbtn2->setFlat(true);
    bugbtn2->setFocusPolicy(Qt::NoFocus);
    bugbtn3=new QPushButton(this);
    bugbtn3->setIcon(QIcon(":/ogun4.png"));
    bugbtn3->setIconSize(QSize(700,350));
    bugbtn3->setFlat(true);
    bugbtn3->setFocusPolicy(Qt::NoFocus);
    bugbtn4=new QPushButton(this);
    bugbtn4->setIcon(QIcon(":/ogun5.png"));
    bugbtn4->setIconSize(QSize(700,350));
    bugbtn4->setFlat(true);
    bugbtn4->setFocusPolicy(Qt::NoFocus);
    laybox=new QHBoxLayout(this);
    laybox->addWidget(bugbtn1);
    laybox->addWidget(bugbtn2);
    laybox->addWidget(bugbtn3);
    laybox->addWidget(bugbtn4);
}
