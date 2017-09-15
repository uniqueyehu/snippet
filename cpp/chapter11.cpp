#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// 顺序容器


// 关联容器
// 按关键字有序保存元素，头文件map和set
// map                   关联数组；保存（关键字-值）对
// set                   关键字即值，只保存关键字
// multimap              关键字可以重复出现的map
// multiset              关键字可以重复出现的set
//
// 无序集合，头文件unordered_map和unordered_set
// unordered_map         用hash函数组织的map
// unordered_set         用hash函数组织的set
// unordered_multimap    hash组织的map；关键字可以重复出现
// unordered_multiset    hash组织的set；关键字可以重复出现

// 统计每个单词在输入中出现的次数
void test_map()
{
    // map为有序的key-value，按key排序，可按key索引
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    // 从map中提取一个元素时，会得到一个pair类型对象
    // pair.first保存关键字
    // pair.second保存对应的值
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
}

// 统计每个单词在输入中出现的次数
// 只统计不在exclude中的单词
void test_set()
{
    // map为有序的key-value，按key排序，可按key索引
    // set为有序的key集合，按key索引
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                          "the", "but", "and", "or", "an", "a"};

    string word;
    while (cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
}

void test_define()
{
    // map<key, value> name;
    // set<key> name;
    map<string, size_t> word_count; // 空容器
    // 列表初始化
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    map<string, string> authors = { {"Joyce", "James"},
                                    {"Austen", "Jane"},
                                    {"Dickens", "Charles"} };

    // 初始化multimap或multiset
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i); // 每个数重复保存一次
    }
    // iset包含来自ivec的不重复的元素；miset包含所有20个元素
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}

// pair定义在头文件utility中
void test_pair()
{
    // 一个pair保存两个数据成员
    // 创建一个pair时，要提供两个类型名，可以不同类型
    // 默认初始化
    pair<string, string> anon;          // 保存两个string
    pair<string, size_t> word_count;    // 保存一个string和一个size_t
    pair<string, vector<int>> line;     // 保存string和vector<int>

    // 提供初始化器
    pair<string, string> author{"James", "Joyce"};
    // 两个成员分别为first和second
    cout << author.first << " - " << author.second << endl;
}

// 函数返回pair对象
pair<string, int> process(vector<string> &v)
{
    // 处理v，back()为vector中最后一个元素
    v.push_back("hello");
    if (!v.empty())
//        return {v.back(), v.back().size()}; // 列表初始化
//        return pair<string, int>(v.back(), v.back().size()); // 早期C++版本不允许用花括号来初始化
        return make_pair(v.back(), v.back().size()); // 使用make_pair来生成pair对象
    else
        return pair<string, int>(); // 隐式构造返回值
}

// key_type			容器类型的关键字类型
// mapped_type		每个关键字关联的类型；只适用于map
// value_type		对于set，与key_type相同
//					对于map，为pair<const key_type, mapped_type>
set<string>::value_type v1;			// v1是一个string
set<string>::key_type v2;			// v2是一个string
map<string, int>::value_type v3;	// v3是一个pair<const key_type, mapped_type>
map<string, int>::key_type v4;		// v4是一个string
map<string, int>::mapped_type v5;	// v5是一个int

// 关联容器迭代器
