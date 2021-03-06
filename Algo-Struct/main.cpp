#include <QCoreApplication>
#include "list/list.h"
#include "sort/sort.h"
#include "examples/two_sum.h"
#include "CAVLTree/CAVLTree.h"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

int main(int argc, char *argv[])
{
    START_EASYLOGGINGPP(argc, argv);
    el::Configurations cfg("test_conf.conf");
    el::Loggers::reconfigureAllLoggers(cfg);


    QCoreApplication a(argc, argv);

//    lt::TestList();
//    st::sortTest();
//    ep::test_two_sum();
//    tr::AVLtest();


    return a.exec();
}
