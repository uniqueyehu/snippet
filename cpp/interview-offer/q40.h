#ifndef Q40_H
#define Q40_H

#include "snippet.h"

// 产生start--end之间的随机数
    int RandomInRange(int start, int end)
    {
        //srand(time(NULL));
        //return start + rand() % (end - start + 1);
        return start;
    }

    // 交换两个元素
    void Swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int Partion(vector<int> data, int start, int end)
    {
        int index = RandomInRange(start, end);
        Swap(&data[index], &data[end]);

        int small = start - 1;
        for (index = start; index < end; ++index)
        {
            if (data[index] < data[end])
            {
                ++small;
                if (small != index) // 说明此时small指向的是大元素，不然的话，small每次指向的是比end小的小元素
                    Swap(&data[small], &data[index]); // 把small处的大元素和index处的小元素交换
            }
        }
        ++small;
        Swap(&data[small], &data[end]);
        return small;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int start = 0;
        int end = input.size() - 1;
        int index = Partion(input, start, end);

        while (index != k - 1)
        {
            if (index > k - 1)
            {
                end = index - 1;
                index = Partion(input, start, end);
            }
            else
            {
                start = index + 1;
                index = Partion(input, start, end);
            }
        }

        vector<int> output;
        for (int i = 0; i < k; ++i)
            output.push_back(input[i]);
        return output;
    }

#endif // Q40_H
