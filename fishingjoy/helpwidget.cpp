#include "helpwidget.h"
#include<QIcon>
#include<Windows.h>
helpwidget::helpwidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(671,740);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/score.png")));
    setPalette(palette);
}
