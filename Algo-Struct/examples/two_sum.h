#ifndef TWO_SUM_H
#define TWO_SUM_H


namespace ep {

/* 《给定一个数组，找出数组中和为一定值的两个数,返回这两个数的下标》
* 第一个思路，遍历数组中的某一个数，对于每个数再一次遍历数组中的所有数，找到满足条件的两个数。
* 这个算法的时间复杂度为O(n2)，空间复杂度为O(1)。
* 第二个思路，在前一个算法的基础上降低时间复杂度。我们可以将数组排序，
* 然后定义两个指针，一个指针从左向右，另一个从右向左，遍历直到找到满足条件的两个数。
* 由于排序的最佳时间复杂度为O(nlogn)，两个指针的遍历时间复杂度为O(n)。所以总的时间复杂度为O(nlogn)
* 第三个思路，我希望通过O(n)的时间复杂度完成要求。第一遍O(n)的算法将每个数据a对应的target-a建立查询的数据结构，
* 例如Hash表；第二遍遍历时，查询每个数是否在Hash表中，每次查询时间复杂度为O(1)，
* 总的时间复杂度是O(n)。但是Hash表将需要一定的存储空间，为了节省空间，我们可以采用bitmap的方法来最大化的压
* 缩空间复杂度。
*/
QVector<int> two_sum(QVector<int> input, int target);
int test_two_sum();












}





#endif // TWO_SUM_H
