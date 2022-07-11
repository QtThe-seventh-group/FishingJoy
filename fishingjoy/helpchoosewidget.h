#ifndef HELPCHOOSEWIDGET_H
#define HELPCHOOSEWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<helpwidget.h>
#include<helprulewidget.h>
#include<Windows.h>
class helpchoosewidget : public QWidget
{
    Q_OBJECT
public:
    explicit helpchoosewidget(QWidget *parent = nullptr);
    QPushButton *helpbtn1;//规则说明
    QPushButton *helpbtn2;//捕鱼分数
    QPushButton *helpbtn3;//返回上一页
    QVBoxLayout *box;
    helpwidget  helpscore;//分数表界面
    helprulewidget helprule;//规则界面
signals:

public slots:
    void showscore();
    void showrule();
};

#endif // HELPCHOOSEWIDGET_H
