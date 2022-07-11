#include "helprulewidget.h"
#include<QIcon>
#include<Windows.h>
helprulewidget::helprulewidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);
}
