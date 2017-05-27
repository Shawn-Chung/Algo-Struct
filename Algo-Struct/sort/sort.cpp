#include "sort.h"
#include "gloabl.h"
#include "easylogging++.h"


using namespace st;

int st::sortTest()
{
    //根据需要的算法选择构建相应的类
    CSort *sort = new CQuickSort(100);
//    sort->init();

    QList<int> result;
    sort->getData(result);
    LOG(INFO) << "The orignal data:" << result;

    sort->exec();
    sort->getData(result);
    LOG(INFO) << "The result  data:" << result;

    return 0;
}

int CSort::init()
{
    for (int i = 0; i < m_iSize; ++i)
    {
        m_lstData.append(random(1, m_iSize * 100));
    }

    return 0;
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

    return 0;
}

int CShellSort::exec()
{
    //输入数据处理
    int *data = new int(getSize());
    for(int i=0; i<getSize(); i++)
    {
        data[i] = m_lstData.value(i);
    }

    //具体的排序算法
    for(int d=getSize()/2; d>=1; d/=2)
    {
        for(int i=d; i<getSize(); i++)
        {
            int tmp = data[i];
            int j = i-d;
            for(; j>0 && data[j]>tmp; j-=d)
            {
                data[j+d] = data[j];
            }
            data[j+d] = tmp;
        }
    }

    //输出数据处理
    m_lstData.clear();
    for(int i=0; i<getSize(); i++)
    {
        m_lstData.push_back(data[i]);
    }
    delete data;

    return 0;
}


int BubbleSort::sort_normal(int *pData, int iSize)
{
    if(!pData)
    {
        LOG(ERROR)<< "invalid pointer";
        return -1;
    }

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

    return 0;
}

int BubbleSort::sort_optimize(int *pData, int iSize)
{
    if(!pData)
    {
        LOG(ERROR)<< "invalid pointer";
        return -1;
    }

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

    return 0;
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

    return 0;
}

int CSelectSort::exec()
{
    //输入数据处理
    int *data = new int(getSize());
    for(int i=0; i<getSize(); i++)
    {
        data[i] = m_lstData.value(i);
    }

    //具体的排序算法
    for(int i=0; i<getSize()-1; i++)
    {
        int index = i;
        for(int j=i+1; j<getSize(); j++)
        {
            if(data[j]<data[index])
            {
                index = j;
            }
        }

        if(index != i)
        {
            int tmp = data[i];
            data[i] = data[index];
            data[index] = tmp;
        }
    }

    //输出数据处理
    m_lstData.clear();
    for(int i=0; i<getSize(); i++)
    {
        m_lstData.push_back(data[i]);
    }
    delete data;

    return 0;
}

int CQuickSort::partition(int *pData, int first, int end)
{
    if(!pData)
    {
        LOG(ERROR)<< "invalid pointer";
        return -1;
    }
    int i = first;
    int j = end;
    while(i<j)
    {
        while((i<j) && pData[j]>=pData[i])
        {
            j--;
        }
        if(i<j)
        {
            int tmp = pData[i];
            pData[i] = pData[j];
            pData[j] = tmp;
            i++;
        }

        while ((i<j) && pData[j]>=pData[i])
        {
            i++;
        }
        if(i<j)
        {
            int tmp = pData[i];
            pData[i] = pData[j];
            pData[j] = tmp;
            j--;
        }
    }
    return i;
}

int CQuickSort::sort(int *pData, int first, int end)
{
    if(!pData)
    {
        LOG(ERROR)<< "invalid pointer";
        return -1;
    }
    if(first < end)
    {
        int index = partition(pData, first, end);
        sort(pData, first, index);
        sort(pData, index+1, end);
    }
    return 0;
}

int CQuickSort::exec()
{
    //输入数据处理
    int *data = new int(getSize());
    for(int i=0; i<getSize(); i++)
    {
        data[i] = m_lstData.value(i);
    }

    //具体的排序算法
    sort(data, 0, getSize()-1);

    //输出数据处理
    m_lstData.clear();
    for(int i=0; i<getSize(); i++)
    {
        m_lstData.push_back(data[i]);
    }
    delete data;

    return 0;
}
