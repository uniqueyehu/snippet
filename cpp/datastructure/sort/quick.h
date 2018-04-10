#ifndef QUICK_H
#define QUICK_H
// 排序--内部排序--交换排序：快速排序
// 通过一趟排序将要排序的数据分割成独立的两部分
// 其中一部分的所有数据都比另外一部分的所有数据都要小
// 然后再按此方法对这两部分数据分别进行快速排序
// 整个排序过程可以递归进行，以此达到整个数据变成有序序列。
// 时间复杂度：O(n log2 n)
// 空间复杂度：O(log2 n)

void quick_sort(int a[], int low, int high)
{
    if (low >= high)    // 左边索引大于右边为结束条件
        return ;
    int first = low;
    int last = high;
    int key = a[first]; // 选取第一个数为哨兵

    while (first < last)    // 在组内寻找一遍
    {
        while (first < last && a[last] >= key)  // 从后往前
            --last;
        a[first] = a[last];

        while (first < last && a[first] <= key) // 从前往后
            ++first;
        a[last] = a[first];
    }
    a[first] = key; // 最终中间的位置为哨兵的值，左边小于哨兵，右边大于哨兵
    quick_sort(a, low, first - 1);  // 递归左边
    quick_sort(a, first + 1, high); // 递归右边
}

#endif // QUICK_H
