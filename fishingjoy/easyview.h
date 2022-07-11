#ifndef EASYVIEW_H
#define EASYVIEW_H

#include<QGraphicsView>
#include <QWidget>
#include<QIcon>
#include<QBrush>
#include<QGraphicsScene>
#include<QResizeEvent>
#include"qgun.h"
#include"qfish.h"
#include<QTimer>
#include<QPixmap>
#include<QPoint>
#include<QLine>
#include<QLineF>
#include"qpixmap.h"
#include"qbullet.h"
#include<qpfish.h>
#include<qffish.h>
#include<Windows.h>
#include<QMessageBox>
#include"qbfish.h"
#include"qgfish.h"
#include"goldshopwidget.h"
#include<QLabel>
#include"helpchoosewidget.h"
#include"finishwidget.h"
#include<QPushButton>


class Easyview:public QGraphicsView
{
//     Q_OBJECT/*添加就会报错undefined reference to `vtable for easyview'*/
public:
    explicit Easyview(QWidget *parent=0);
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    static int choose1;
    static int choose2;
    void updata();
     int moneyscore;
     QPushButton *shop;
     QPushButton *level;
     QPushButton *quitev;
     int buymoney1=0;
     int buymoney2=0;
     int buymoney3=0;
     int buymoney4=0;
     int levelmoney=0;
     finishwidget finish;
     QGun *gun;
private:
    QGraphicsScene *scene;
    QLabel *lab;
    QGun *money;
    QFish *fish[4];
    QTimer *timer;
    QTimer *timerp2,*timerp1,*timerp3;
    qpfish *pfish[7],*pfish2[9],*pfish3[5];
    Qffish *ffish[4];
    QTimer *timerf1;
    qbfish *bfish[3];
    QTimer *timerb;
    qgfish *gfish[2];
    QTimer *timerg;
    goldshopwidget goldshop1;
};

#endif // EASYVIEW_H
