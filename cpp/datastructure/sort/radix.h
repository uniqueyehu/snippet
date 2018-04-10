#ifndef RADIX_H
#define RADIX_H
// 排序--内部排序--基数排序
// 从最低位开始排序，再逐渐往高位排，低位优先，位数为d，基数的范围为r，个数为n
// 时间复杂度：O(d * (r + n))
// 空间复杂度：O(r + n)

int maxbit(int data[], int n)
{// 求数据的最大位数
    int d = 1;
    int p = 10;
    for (int i = 0; i < n; ++i)
    {
        while (data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}

void radix_sort(int array[], int len)
{
    int d = maxbit(array, len);
    int *temp = new int[len];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;

    for (i = 1; i <= d; ++i)
    {
        for (j = 0; j < 10; ++j)
            count[j] = 0;

        for (j = 0; j < len; ++j)
        {
            k = (array[j]/radix) % 10; // 依次取最低位
            count[k]++;
        }

        for (j = 1; j < 10; ++j)
            count[j] = count[j - 1] + count[j]; // 此时count的值为0-j所有元素的个数了

        for (j = len - 1; j >= 0; --j)
        {
            k = (array[j]/radix) % 10;
            temp[count[k] - 1] = array[j]; // 将同一位相同的数相邻放在temp中
            count[k]--;
        }

        for (j = 0; j < len; ++j)
            array[j] = temp[j];
        radix *= 10;
    }
    delete []temp;
    delete []count;
}

#endif // RADIX_H
