#include <iostream>
#include <vector>
// 使用vector需包含相应头文件

using namespace std;

// vector是类模板，由vector生成的类型必须包含vector中元素类型，如vector<int>
// 早期版本c++编译器在右边尖括号需要加空格，如vector<vector<int> >
int main(int argc, char *argv[])
{
    // 定义和初始化
    // 常见用法是定义一个空vector，然后逐一添加元素
    vector<string> svec; // 默认初始化，svec不包含任何元素

    // 其他初始化方法
    vector<int> ivec;
    vector<int> ivec2(ivec); // 把ivec的元素拷贝给ivec2

    vector<string> v1 = {"a", "an", "the"};
    vector<string> v2{"a", "an", "the"}; // 列表初始化，两种形式等价

    vector<int> v3(10, -1); // 10个int类型的元素，每个都被初始化为-1
    vector<int> v4(10); // 10个元素，每个都被默认初始化为0
    vector<int> v5{10}; // 1个元素，值为10
    vector<int> v6{10, -1}; // 2个元素，值为10和-1，容易与上面的混淆


    // 向vector中添加元素
    // 从标准输入中读取单词，将其作为vector对象元素存储
    string word;
    vector<string> text;
    while(cin >> word)
    {
        text.push_back(word);
    }

    // 若text为空，返回真；否则返回假
    text.empty();
    // 返回text中元素的个数，为vector<string>::size_type类型
    // 也可用decltype(text.size())类型自动转换
    vector<string>::size_type tsize = text.size();
    decltype(text.size()) tsize1;
    // 类似数组下标引用
    string str = text[1];


    // 迭代器
    // begin成员返回指向第一个元素的迭代器
    // end成员返回指向容器尾元素的下一个位置（尾后）
    // *iter 返回迭代器所指的元素的引用
    // iter->mem / (*iter).mem 等价，解引用iter并获取该元素的名为mem的成员
    // ++iter/--iter 指向下一个/上一个元素
    // iter1 == iter2 判断两个迭代器是否指向同一元素
    string s("some thing");
    for (auto it = s.begin(); it != s.end(); ++it)
        *it = toupper(*it); // 将当前字符改为大写形式

    // 迭代器类型
    vector<int> v;
    const vector<int> cv;
    // it1的类型为vector<int>::iterator
    // 可读写vector<int>中元素
    auto it1 = v.begin();
    // it2的类型为vector<int>::const_iterator
    // 只能读元素，不能写元素
    auto it2 = cv.begin();

    return 0;
}
