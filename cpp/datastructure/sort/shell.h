#ifndef SHELL_H
#define SHELL_H
// 排序--内部排序--插入排序：希尔排序
// 先选取一个增量，将待排序元素分组，分别使用直接插入排序；逐渐缩小增量，再分组排序，直至增量为1
// 时间复杂度：
// 空间复杂度：

void shell_sort(int array[], int len)
{
    int i, j, gap;
    for (gap = len / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < len; ++i) // 自己在纸上举个例子看看即可
        {
            for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap)
            {
                int temp = array[j];
                array[j] = array[j + gap];
                array[j + gap] = temp;
            }
        }
    }
}

#endif // SHELL_H
