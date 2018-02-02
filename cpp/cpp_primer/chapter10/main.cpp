#include <iostream>
#include <vector>
#include <algorithm>    // 泛型算法
#include <numeric>      // 某些算法定义在此头文件中
#include <string>
#include <list>
#include <iterator>     // 迭代器头文件

#include "mylambda.h"

using namespace std;
//-----------------------------------------------------------------
// 文中代码
void test_find()
{
    vector<int> iv;
    for (size_t i = 0; i != 10; ++i)
        iv.push_back(i);

    int val = 4;
    // 查找val元素是否存在
    auto result = find(iv.cbegin(), iv.cend(), val);
    cout << "The value " << val
         << (result == iv.cend()
             ? " is not present" : " is present") << endl;
}

void test_count()
{
    vector<int> iv;
    for (size_t i = 0; i != 10; ++i)
        iv.push_back(i);
    iv.push_back(5);

    int val = 5;
    // 统计val出现的次数
    cout << "The times is : " << count(iv.cbegin(), iv.cend(), val) << endl;
}

void test_accumulate()
{
    vector<int> vec;
    for (size_t i = 1; i != 10; ++i)
        vec.push_back(i);

    int sum = accumulate(vec.cbegin(), vec.cend(), 0); // 求和
    cout << "sum is : " << sum << endl;

    vector<string> str = {"I ", "am ", "an ", "iron ", "man"};
    string sumstr = accumulate(str.cbegin(), str.cend(), string("")); // 连接字符串
    cout << sumstr << endl;
}

// iostream迭代器
void test_iostream_iterator()
{
    vector<int> vec;
//    istream_iterator<int> in_iter(cin);      // 从cin读取int
//    istream_iterator<int> eof;               // istream尾后迭代器
//    while (in_iter != eof)
//        vec.push_back(*in_iter++);

//    for (auto i = vec.begin(); i != vec.end(); ++i)
//        cout << *i << endl;

    istream_iterator<int> in2(cin), eof2;
    cout << accumulate(in2, eof2, 0) << endl;
}

//-----------------------------------------------------------------
// 课后练习
void test_10_2()
{
    list<string> sl;
    string str;
    while (cin >> str)
        sl.push_back(str);

    string val = "hello";
    cout << "Hello is : "
         << count(sl.cbegin(), sl.cend(), val) // 统计val出现的次数
         << " times" << endl;
}

void output_10_9(vector<string> &str)
{
    for (auto it = str.begin(); it != str.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// 比较单词长度
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void test_10_9()
{
    vector<string> str = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    output_10_9(str);

    // 按字典序排序
    sort(str.begin(), str.end());
    output_10_9(str);

    // 将重复的元素放在末尾
    auto end_unique = unique(str.begin(), str.end());
    output_10_9(str);

    // 删除尾部的重复元素
    str.erase(end_unique, str.end());
    output_10_9(str);

    // 稳定排序算法，维持长度相等元素的原有序列
    stable_sort(str.begin(), str.end(), isShorter);
    output_10_9(str);
}

int main(int argc, char *argv[])
{
//    test_find();
//    test_count();
//    test_10_2();
//    test_accumulate();
//    test_10_9();
//    test_lambda();
    test_iostream_iterator();
    return 0;
}
