#include "voice.h"

voice::voice(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,580);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/label1.png"));
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png")));
    setPalette(palette);
    openbutton=new QPushButton(this);
    openbutton->setIcon(QIcon(":/finish3.png"));
    openbutton->setIconSize(QSize(192,37));
    openbutton->setFlat(true);
    openbutton->setFocusPolicy(Qt::NoFocus);
    closebutton=new QPushButton(this);
    closebutton->setIcon(QIcon(":/finish6.png"));
    closebutton->setIconSize(QSize(192,37));
    closebutton->setFlat(true);
    closebutton->setFocusPolicy(Qt::NoFocus);
    closebutton1=new QPushButton(this);
    closebutton1->setIcon(QIcon(":/finish4.png"));
    closebutton1->setIconSize(QSize(192,37));
    closebutton1->setFlat(true);
    closebutton1->setFocusPolicy(Qt::NoFocus);
    box=new QVBoxLayout(this);
    box->addWidget(openbutton);
    box->addWidget(closebutton);
    box->addWidget(closebutton1);
}
