#ifndef GOLDSHOPWIDGET_H
#define GOLDSHOPWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QBoxLayout>
#include<QHBoxLayout>
#include<QPixmap>
#include"helpchoosewidget.h"
class goldshopwidget : public QWidget
{
    Q_OBJECT
public:
    explicit goldshopwidget(QWidget *parent = nullptr);
    QLabel *lab1;
    QPushButton *bugbtn1;
    QPushButton *bugbtn2;
    QPushButton *bugbtn3;
    QPushButton *bugbtn4;
    QBoxLayout *box;
    QHBoxLayout *laybox;
signals:

public slots:

};

#endif // GOLDSHOPWIDGET_H
