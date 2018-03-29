#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
题目描述： 输出两个不超过100位的大整数的乘积。
输入： 输入两个大整数，如1234567 和 123
输出： 输出乘积，如：151851741
*/


/*
 * 大数相乘 - 模拟乘法累加，不进位，最后进位

        9  8
×       2  1
-------------
       (9)(8)  <---- 第1趟: 98×1的每一位结果
  (18)(16)     <---- 第2趟: 98×2的每一位结果
-------------
  (18)(25)(8)  <---- 这里就是相对位的和，还没有累加进位

 */
vector<int> bigNumMultiple1(vector<int>  num1, vector<int> num2)
{
    // 两数相乘最大位数不会超过两数位数之和
    vector<int> ret(num1.size()+num2.size(), 0);

    for (int i = 0; i < num1.size(); ++i)
    {
        for (int j = 0; j < num2.size(); ++j)
            ret[i+j+1] += num1[i] * num2[j];    // 进位时最高位才会被用到
    }

    // 处理进位
    for (int k = ret.size() - 1; k > 0; --k)
    {
        if (ret[k] > 10)
        {
            ret[k - 1] += ret[k] / 10;
            ret[k] %= 10;
        }
    }
    return ret;
}

int main(int argc, char *argv[])
{
//    string a = "1234567891011121314151617181920";
//    string b = "2019181716151413121110987654321";

    string a = "24566";
    string b = "452053";

//    string a;
//    string b;
//    cin >> a >> b;

    // 字符转化为int数组
    vector<int> num1;
    vector<int> num2;
    for (int i = 0; i < a.size(); ++i)
        num1.push_back(a[i] - '0');
    for (int i = 0; i < b.size(); ++i)
        num2.push_back(b[i] - '0');

    // 开始计算
    vector<int> ret = bigNumMultiple1(num1, num2);
    for (auto it = ret.cbegin(); it != ret.cend(); ++it)
        cout << *it;
    cout << endl;

    return 0;
}
