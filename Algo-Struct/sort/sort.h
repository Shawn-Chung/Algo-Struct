#ifndef SORT_H
#define SORT_H
#include <QList>
namespace st {

int sortTest();

class CSort
{
public:
    CSort(int count) {m_iSize = count; init();}
    CSort(QList<int> initData){m_lstData = initData; m_iSize = initData.size();}

    virtual int exec(){}
    int getData(QList<int> &out){out = m_lstData;}
    int getSize(){return m_iSize;}
    int init();

private:
    int m_iSize;

protected:
    QList<int> m_lstData;
};

//插入排序
class CInsortSort: public CSort
{
public:
    CInsortSort(int count):CSort(count) {}
    CInsortSort(QList<int> initData):CSort(initData){}


    virtual int exec();
};
//冒泡排序
class BubbleSort: public CSort
{
public:
    BubbleSort(int count):CSort(count) {}
    BubbleSort(QList<int> initData):CSort(initData){}

    //按照常规思想实现
    int sort_normal(int *pData, int iSize);
    //优化，减少遍历次数
    int sort_optimize(int *pData, int iSize);

    virtual int exec();
};










}















#endif // SORT_H
