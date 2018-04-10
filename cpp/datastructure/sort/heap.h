#ifndef HEAP_H
#define HEAP_H
// 排序--内部排序--选择排序：堆排序
// 每次从大顶堆中选择堆顶，放在尾部，再将前面序列调整为大顶堆，再选堆顶
// 时间复杂度：O(nlog2 n)
// 空间复杂度：O(1)

/*
void adjustMaxHeap(int i, int len, int array[])
{
    int temp = array[i];
    for (int k = i*2 + 1; k < len; k = k*2 + 1)
    {
        if (k + 1 < len && array[k] < array[k + 1])
            ++k;
        if (array[k] > temp)
        {
            array[i] = array[k];
            i = k;
        }
        else
            break;
    }
    array[i] = temp;
}*/

void adjustMaxHeap(int i, int len, int array[])
{
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;
    int largestIndex = i;

    if (leftchild < len && array[leftchild] > array[largestIndex])
        largestIndex = leftchild;
    if (rightchild < len && array[rightchild] > array[largestIndex])
        largestIndex = rightchild;

    if (largestIndex != i)
    {
        int temp = array[i];
        array[i] = array[largestIndex];
        array[largestIndex] = temp;
        adjustMaxHeap(largestIndex, len, array);
    }
}

void heap_sort(int len, int array[])
{
    // 从最后一个结点的 父节点开始，往前
    for (int i = len/2 - 1; i >= 0; --i)
        adjustMaxHeap(i, len, array);

    // 从大顶堆中选出顶，放在最后，再将剩下的排成大顶堆，再选
    for (int j = len - 1; j > 0; --j)
    {
        int temp = array[0];
        array[0] = array[j];
        array[j] = temp;

        adjustMaxHeap(0, j, array);
    }
}

#endif // HEAP_H
