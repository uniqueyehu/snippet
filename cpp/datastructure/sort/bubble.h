#ifndef BUBBLE_H
#define BUBBLE_H
// 排序--内部排序--交换排序：冒泡排序
// 依次交换相邻的两个元素，一趟排序下来，最大的元素排在尾部
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)

void bubble_sort(int array[], int len)
{
    int i, j, temp;
    for (i = 0; i < len -1; ++i)
        for (j = 0; j < len - 1 - i; ++j)
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
}


#endif // BUBBLE_H
