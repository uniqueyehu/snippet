#ifndef SELECT_H
#define SELECT_H
// 排序--内部排序--选择排序：直接选择排序
// 依次从未排序的序列中选择最小（大）元素，放入有序序列尾部
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)

void select_sort(int array[], int len)
{
    int minIdx, temp;
    for (int i = 0; i < len - 1; ++i)
    {
        minIdx = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (array[j] < array[minIdx])   // 寻找最小索引
                minIdx = j;
        }
        temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
    }
}

#endif // SELECT_H
