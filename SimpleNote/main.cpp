#include "widget/SimpleNote.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleNote w;
    w.show();
    return a.exec();
}
