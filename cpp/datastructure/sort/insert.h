#ifndef INSERT_H
#define INSERT_H
// 排序--内部排序--插入排序：直接插入排序
// 每趟从未排序的序列中选一个元素，插入到前面已经排好序的序列中
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)

void insert_sort(int array[], int len)
{
    int preIdx, current;
    for (int i = 1; i < len; ++i)
    {
        preIdx = i - 1;
        current = array[i];     // 保存要插入的元素，设置哨兵
        while (preIdx >= 0 && array[preIdx] > current)
        {
            array[preIdx+1] = array[preIdx];
            --preIdx;
        }
        array[preIdx+1] = current;
    }
}

#endif // INSERT_H
