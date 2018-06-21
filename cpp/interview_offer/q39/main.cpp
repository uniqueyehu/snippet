#include <iostream>
#include <vector>

using namespace std;

/*
 * 数组中出现次数超过一半的数字
 * 超过一半的数字的次数总和必定大于其他数字次数总和
 */

// 检查输入的合法性
bool g_bInputInvalid = false;

bool CheckInvalidArray(vector<int> numbers, int length)
{
    g_bInputInvalid = false;
    if (length <= 0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

bool CheckMoreThanHalf(vector<int> numbers, int length, int number)
{
    int times = 0;
    for (int i = 0; i < length; ++i)
    {
        if (numbers[i] == number)
            times++;    // 统计number的出现次数
    }

    bool isMoreThanHalf = true;
    if (times * 2 < length) // 不过半则结果非法
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

int MoreThanHalfNum_Solution(vector<int> numbers)
{
    int length = numbers.size();
    if (CheckInvalidArray(numbers, length)) // length <= 0 即为非法
        return 0;

    int result = numbers[0];
    int times = 1;  // 初始情况取第一个元素，times初始位1

    for (int i = 1; i < length; ++i)    // 与接下来一个元素相比
    {
        if (times == 0) // times减为0时，换个数字保存
        {
            result = numbers[i];
            times = 1;
        }
        else if (numbers[i] == result)  // 如果相等，times加一
            times++;
        else
            times--;    // 不相等，times减一
    }

    if (!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}


int main(int argc, char *argv[])
{
    vector<int> numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int result = MoreThanHalfNum_Solution(numbers);
    cout << result << endl;
    return 0;
}
