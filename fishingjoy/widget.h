#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QIcon>
#include<QBrush>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include"easyview.h"
#include"helpchoosewidget.h"
#include<helprulewidget.h>
#include<helpwidget.h>
#include<choosewidget.h>
#include<Windows.h>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QSound>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Ui::Widget *ui;
    QLabel *label;
    QPushButton *btn1;//开始按钮
    QPushButton *btn2;//游戏设置按钮
    QPushButton *btn3;//帮助按钮
    QPushButton *btn4;//退出按钮
    QVBoxLayout *box;
    choosewidget game;
    helpchoosewidget help;
    Easyview *easyview;
public slots:
    void startclick();
    void helpclick();
    void finishclick();
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    //Ui::Widget *ui;
};

#endif // WIDGET_H
