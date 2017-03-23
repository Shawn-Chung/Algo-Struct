#include <QCoreApplication>
#include "list/list.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    lt::TestList();
    return a.exec();
}
