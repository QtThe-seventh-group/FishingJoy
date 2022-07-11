#include "helprulewidget.h"
#include<QIcon>
#include<Windows.h>
helprulewidget::helprulewidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1527,1019);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/help2.png")));
    setPalette(palette);
}
