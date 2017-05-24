#include "sort.h"
#include "gloabl.h"
#include "easylogging++.h"


using namespace st;

int st::sortTest()
{
    //根据需要的算法选择构建相应的类
    CSort *sort = new BubbleSort(15);
//    sort->init();

    QList<int> result;
    sort->getData(result);
    LOG(INFO) << "The orignal data:" << result;

    sort->exec();
    sort->getData(result);
    LOG(INFO) << "The result  data:" << result;
}

int CSort::init()
{
    for (int i = 0; i < m_iSize; ++i)
    {
        m_lstData.append(random(1, m_iSize * 100));
    }
}

int CInsortSort::exec()
{
    //输入数据处理
    int *data = new int(getSize());
    for(int i=0; i<getSize(); i++)
    {
        data[i] = m_lstData.value(i);
    }

    //具体的排序算法
    for(int j=1; j<getSize(); j++)
    {
        int tmp = data[j];
        //寻找插入的位置，同时移动数据
        int i = j-1;
        for(; tmp<data[i]; i--)
        {
            data[i+1] = data[i];
        }
        data[i+1] = tmp;
    }

    //输出数据处理
    m_lstData.clear();
    for(int i=0; i<getSize(); i++)
    {
        m_lstData.push_back(data[i]);
    }
    delete data;
}


int BubbleSort::sort_normal(int *pData, int iSize)
{
    for(int j=iSize-1; j>0; j--)
    {
        for(int i=0; i<j; i++)
        {
            if(pData[i] > pData[i+1])
            {
                int tmp = pData[i];
                pData[i] = pData[i+1];
                pData[i+1] = tmp;
            }
        }
    }
}

int BubbleSort::sort_optimize(int *pData, int iSize)
{
    //用于指示是否需要排序
    int iExchange = getSize()-1;
    //如果此次遍历未进行交换(iExchange)，则直接退出，排序完成
    while (iExchange)
    {
        int iIndex = iExchange;//记录未排序的数据最大坐标
        iExchange = 0;

        for(int i=0; i<iIndex; i++)
        {
            if(pData[i] > pData[i+1])
            {
                int tmp = pData[i];
                pData[i] = pData[i+1];
                pData[i+1] = tmp;
                iExchange = i; //需要继续排序，记录下未排序的最大坐标，供下一次遍历使用
            }
        }
    }
}

int BubbleSort::exec()
{
    //输入数据处理
    int *data = new int(getSize());
    for(int i=0; i<getSize(); i++)
    {
        data[i] = m_lstData.value(i);
    }

    //具体的排序算法
    sort_optimize(data, getSize());
    sort_normal(data, getSize());

    //输出数据处理
    m_lstData.clear();
    for(int i=0; i<getSize(); i++)
    {
        m_lstData.push_back(data[i]);
    }
    delete data;
}
