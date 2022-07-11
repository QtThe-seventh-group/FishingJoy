#ifndef FINISHWIDGET_H
#define FINISHWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QBoxLayout>
#include<Windows.h>
#include"white.h"
class finishwidget : public QWidget
{
    Q_OBJECT
public:
    explicit finishwidget(QWidget *parent = nullptr);
    QPushButton *finishbtn1;
    QPushButton *finishbtn2;
    QPushButton *finishbtn3;
    QBoxLayout *box;
signals:

public slots:
    void finishclick();
};

#endif // FINISHWIDGET_H
