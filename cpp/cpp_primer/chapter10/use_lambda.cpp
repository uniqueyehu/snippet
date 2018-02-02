// 第10章 泛型算法
// 10.3 定制操作
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;
// _1, _2的命名空间
using namespace placeholders;

vector<string> words = {"the", "quick", "red", "fox", "jumps",
                      "over", "the", "slow", "red", "turtle"};

void output_yh(vector<string> &str)
{
    for (auto it = str.begin(); it != str.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void elimDups(vector<string> &str)
{
    // 按字典序排序str，以便查找重复单词
    sort(str.begin(), str.end());
    // unique重排输入范围，使得每个单词只出现一次
    // 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(str.begin(), str.end());
    // 使用向量操作erase删除重复单词
    str.erase(end_unique, str.end());
}

// 使用三个参数版本的sort函数
// sort函数的第三个参数是一个为谓词
// 一元谓词：单一参数；二元谓词：两个参数
// 将isShorter函数作为谓词传递给sort

// 比较函数，用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
    // 按长度由短至长排序words
//    sort(words.begin(), words.end(), isShorter);

// 可以向一个算法传递任何类别的可调用对象
// 一个对象或表达式e，如果可以使用调用运算符e(args)，则是可调用的
// lambda表达式，表示一个可调用的代码单元
// [捕获列表](参数列表) -> 返回值 { 函数体 }
// auto f = [] { return 42; };

// 只在一两个地方使用的简单操作，lambda表达式
// 很多地方使用相同操作，或者一个操作需要很多语句完成，函数
// lambda表达式捕获列表为空，通常可用函数代替

// 求大于等于一个给定长度的单词有多少
void biggies(vector<string> &str, vector<string>::size_type sz)
{
    elimDups(str);
    stable_sort(str.begin(), str.end(), isShorter);
    // 等价形式
    // 捕获列表为空表示不使用它所在函数中的任何局部变量
//    stable_sort(words.begin(), words.end(),
//                [](const string &a, const string &b)
//                  { return a.size() < b.size();});

    // 获取一个迭代器，指向第一个满足size() >= sz的元素
    // find_if接受一元谓词，使用lambda表达式可克服
    auto wc = find_if(str.begin(), str.end(),
                      [sz](const string &a)
                          { return a.size() >= sz; });
    // 计算满足size() >= sz的元素的数目
    auto count = str.end() - wc;
    cout << count << " of length " << sz << " or longer" << endl;
    // 打印长度大于sz的单词
    for_each(wc, str.end(),
             [](const string &s){cout << s << " ";});
    cout << endl;
}

// bind函数
// bind可看作一个通用的函数适配器
// 它接受一个可调用对象，生成一个新的可调用对象
// auto newCallable = bind(callable, arg_list);

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

// 为了解决向check_size传递一个长度参数的问题
// 可以替换lambda表达式
void test_bind()
{
    // check6是一个可调用对象，接受一个string类型的参数
    // 并用此string和值6来调用check_size
    auto check6 = bind(check_size, _1, 4);
    string s = "hello";
    bool b1 = check6(s);
    cout << b1 << endl;

    // g是一个有两个参数的可调用对象
    // f是一个接受5个参数的可调用对象
    // auto g = bind(f, a, b, _2, c, _1);
    // g(_1, _2);
    // 调用映射
    // g(X, Y);
    // f(a, b, Y, c, X);
    // 使用bind函数可以重排参数顺序
    // f(a, b);
    // auto g = bind(f, _2, _1);
    // 调用映射
    // g(X, Y);
    // f(Y, X);
}

int main(int argc, char *argv[])
{
    // 将words按字典序重排，并消除重复单词
//    elimDups(words);
//    output_yh(words);

    // 按长度重新排序，长度相同的单词维持字典序
//    stable_sort(words.begin(), words.end(), isShorter);
//    output_yh(words);

//    biggies(words, 5);
    test_bind();
    return 0;
}
