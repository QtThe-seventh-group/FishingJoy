#include "widget.h"
#include <QApplication>
#include<QTextCodec>
#include<Windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
