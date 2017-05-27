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
/*排序过程中数组分为两部分，前面部分为排好序的，后面部分是乱序的。
 * 排序过程中每次取乱序部分中的第一个元素与排好序部分一一比较，寻找插入位置*/
class CInsortSort: public CSort
{
public:
    CInsortSort(int count):CSort(count) {}
    CInsortSort(QList<int> initData):CSort(initData){}


    virtual int exec();
};

//希尔排序
/*分组 进行 插入排序*/
class CShellSort: public CSort
{
public:
    CShellSort(int count):CSort(count) {}
    CShellSort(QList<int> initData):CSort(initData){}

    virtual int exec();
};

//冒泡排序
/*从第 0 个元素开始，往后轮训，相邻的两两比较，如果前面的比后面的大，则交换位置，
 * 一次遍历则吧数组中最大的元素交换到了最后的位置*/
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

//选择排序
/*从第 0 个元素开始，在它后面的所有元素里面找到最小的元素且比当前元素小的与其交换位置*/
class CSelectSort: public CSort
{
public:
    CSelectSort(int count):CSort(count) {}
    CSelectSort(QList<int> initData):CSort(initData) {}

    virtual int exec();
};

//快速排序
/*递归地将数组分为左右两部分，使其左边部分的全部元素都小于右边的全部元素*/
class CQuickSort: public CSort
{
public:
    CQuickSort(int count):CSort(count) {}
    CQuickSort(QList<int> initData):CSort(initData) {}

    virtual int exec();

private:
    int partition(int *pData, int first, int end);
    int sort(int *pData, int first, int end);
};









}















#endif // SORT_H
