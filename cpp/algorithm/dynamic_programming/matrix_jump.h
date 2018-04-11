#ifndef MATRIX_JUMP_H
#define MATRIX_JUMP_H

#include "snippet.h"

class matrix_jump {
public:
    // 给定一个非负整数数组，最初你被放在数组的第一个元素上，数组的每个元素代表你能跳的最大的步数。
    // 你的目标是用最少的跳数抵达最后一个元素。
    // 例如，给定A = [2,3,1,1,4]，抵达终点的最小跳数是2（下标0->下标1->下标4）

    // table[i]表示从数组下标i的位置抵达最后一个位置的最少跳数
    // 对于在下标为i用1跳抵达的地方：table[i] = table[i+k] + 1，1≤k≤arr[i]
    // 对于i点，最近跳1，最远跳arr[i]，抵达i+k点，就离终点近了一步，故加一
    static int jump_1(int A[], int n)
    {
        int *table = new int[n];
        table[n-1] = 0; // 终点

        for (int i = n - 2; i >= 0; --i)
        {
            if (A[i] == 0)
                table[i] = INT_MAX; // 不能往前跳
            else if (A[i] >= n-1 - i)
                table[i] = 1; // 距离终点1步
            else
            {
                int min = INT_MAX;
                for (int k = i + 1; k < n && k <= A[i] + i; ++k)
                    if (min > table[k])
                        min = table[k]; // 选出从i跳到i+k的最小跳数
                if (min != INT_MAX)
                    table[i] = min + 1; // 从i跳到i+k点，求得table[i]
                else
                    table[i] = min;
            }
        }
        return table[0];
    }

    static void test()
    {
        int A[] = {2, 3, 1, 1, 4};
        int n = 5;
        int ret = jump_1(A, n);
        cout << ret << endl;
    }
};

#endif // MATRIX_JUMP_H
