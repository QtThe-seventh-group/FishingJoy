#ifndef VOICE_H
#define VOICE_H

#include <QWidget>
#include<QPushButton>
#include<QBoxLayout>
class voice : public QWidget
{
    Q_OBJECT
public:
    explicit voice(QWidget *parent = nullptr);
    QPushButton *openbutton;
    QPushButton *closebutton;
    QPushButton *closebutton1;
    QVBoxLayout *box;

signals:

public slots:
};

#endif // VOICE_H
