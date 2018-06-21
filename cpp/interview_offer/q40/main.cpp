#include <iostream>
#include <vector>
#include <time.h>   // time()

using namespace std;

/*
 * 最小的k个数
 * 使用partion函数，使得其返回值等于k值，则前k个数即为最小的k个数
 */

// 产生每次partion的起始index值，介于start和end之间
int RandomInRange(int start, int end)
{
    srand((unsigned)time(NULL));    // srand() rand() in stdlib.h
    return start + rand() % (end - start + 1);
//    return start;
}

// 交换两个元素
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// data需要引用类型！！！
int Partion(vector<int> & data, int start, int end)
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
                Swap(&data[small], &data[index]);   // 把small处的大元素和index处的小元素交换
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

// data需要引用类型！！！
//void QuickSort(vector<int> & data, int start, int end)
//{
//    if (start == end)
//        return;
//    int index = Partion(data, start, end);
//    if (index > start)
//        QuickSort(data, start, index - 1);
//    if (index < end)
//        QuickSort(data, index + 1, end);
//}

vector<int> GetLeastNumber_Solution(vector<int> input, int k)
{
    int start = 0;
    int len = input.size();
    int end = len - 1;

    if (k == len)
        return input;
    if (k <= 0 || k > len || len == 0)
        return vector<int>();

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

int main(int argc, char *argv[])
{
    vector<int> data = {1, 3, 6, 2, 9, 7, 4, 8, 5};
    vector<int> output;
//    QuickSort(data, 0, 8);
    output = GetLeastNumber_Solution(data, 3);
    for (int i = 0; i < 3; ++i)
        cout << output[i] << " ";
    return 0;
}
