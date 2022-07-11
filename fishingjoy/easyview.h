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
#include<QLabel>
#include <QMessageBox>
#include<QSound>
class Easyview:public QGraphicsView
{
//     Q_OBJECT/*添加就会报错undefined reference to `vtable for easyview'*/
public:
    explicit Easyview(QWidget *parent=0);
    void resizeEvent(QResizeEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    static int changegun;
    static int choose1;
    static int choose2;
private:
    QGraphicsScene *scene;
    QGun *gun;
    QFish *fish[4];
    QTimer *timer;
    QTimer *timerp2,*timerp1,*timerp3;
    qpfish *pfish[7],*pfish2[9],*pfish3[5];
    Qffish *ffish[4],*ffish2[3];
    QTimer *timerf1,*timerf2;
};

#endif // EASYVIEW_H
