#include "choosewidget.h"
#include<QIcon>
#include<Windows.h>
choosewidget::choosewidget(QWidget *parent) : QWidget(parent)
{
    //ui->setupUi(this);
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);//游戏窗口接口
}

