#include <QApplication>
#include "rpnwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RPNWidget w;
    w.show();
    
    return a.exec();
}
