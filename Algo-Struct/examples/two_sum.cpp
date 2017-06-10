#include "easylogging++.h"
#include "two_sum.h"



namespace ep {


QVector<int> two_sum(QVector<int> input, int target)
{
    QVector<int> index;
    QHash<int, int> table;
    for(int i=0; i<input.size(); ++i)
    {
        table.insert(input.at(i), i);
    }

    LOG(INFO) << "has table:" << table;

    for(int i=0; i<input.size(); ++i)
    {
        if(input.at(i) <= target)
        {
            int tmp = target - input.at(i);
            if(table.contains(tmp))
            {
                index.push_back(i);
                index.push_back(table.value(tmp));
            }
        }
    }
    return index;
}

int test_two_sum()
{
    QVector<int> num;
    for(int i=0; i<10; ++i)
    {
        num.push_back(i+1);
    }

    LOG(INFO) << "the input is: " << num;

    QVector<int> result = two_sum(num, 10);

    LOG(INFO) << "the indexs are: " << result;

    return 0;
}





}
