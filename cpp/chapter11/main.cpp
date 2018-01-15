#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <unordered_map>

#include "word_transform.h"

using namespace std;
//-----------------------------------------------------------------
// 文中代码
void test_map()
{
    // 统计每个单词在输入中出现的次数
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

    cin.clear(); // 这里cin需要复位才能进行下一次的使用，否则就直接判断无效然后退出咯
    unordered_map<string, size_t> word_count_unorder;
    string word2;
    while (cin >> word2)
        ++word_count_unorder[word2];
    for (const auto &w2 : word_count_unorder)
        cout << w2.first << " occurs " << w2.second
             << ((w2.second > 1) ? " times" : " time") << endl;
}

void test_set()
{
    // 统计每个单词在输入中出现的次数
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
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i); // 每个数重复保存一次
    }
    // iset包含来自ivec的不重复的元素；miset包含所有20个元素
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;    // 20
    cout << iset.size() << endl;    // 10
    cout << miset.size() << endl;   // 20
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

// set的迭代器是const的
void test_set_iterator()
{
    // 关联容器初始化时，自动按关键字升序排列
    set<int> iset = {0,1,7,3,4,9,6,2,8,5};
    set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end())
    {
//        *set_it = 42; // 错误：关键字是const的
        cout << *set_it << endl; // 正确：可以通过迭代器读取元素
    }

    // 遍历关联容器
    auto s_it = iset.cbegin();
    while (s_it != iset.cend()) {
        cout << *s_it << ",";
        ++s_it;
    }
    cout << endl;
}

// 添加元素
void test_insert()
{
    vector<int> ivec = {2,4,6,8,2,4,6,8};       // ivec有8个元素
    set<int> set2;                              // 空集合
    // insert有两个版本，分别接受一对迭代器，或是一个初始化列表
    set2.insert(ivec.cbegin(), ivec.cend());    // set2有4个元素，去除重复
    set2.insert({1,3,5,7,1,3,5,7});             // set2现在有8个元素，加入了1，3，5，7

    // 向map添加元素
    map<string, size_t> word_count;
    string word;
    // 4种方法
    word_count.insert({word, 1}); // 新标准下最简单的方法
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
}

void test_insert2()
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word) {
        // insert返回一个pair
        // pair<map<string, size_t>::iterator, bool>
        // pair的first成员是一个迭代器，指向具体有给定关键字的元素，如map中的元素
        // second成员是一个bool值，指出元素是否插入成功还是已经存在于容器中
        // 若已在容器中，则insert什么也不做，返回值中的bool为false
        // 若关键字不存在，元素将被插入容器中，bool值为true
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
}

// 删除元素
void test_delete()
{
    map<string, size_t> c;
    string k;
    auto p = c.begin();
    auto b = c.begin();
    auto e = c.end();

    // 从c中删除每个关键字为k的元素
    // 返回一个size_type值，指出删除的元素数量
    // 对于不重复关键字的容器，返回值为0或者1
    // 对于可重复关键字的容器，返回值可能大于1
    c.erase(k);
    // 从c中删除迭代器p指定的元素
    // p必须指向c中一个真实的元素，不能等于c.end()
    // 返回一个指向p之后元素的迭代器
    c.erase(p);
    //删除迭代器对(b, e)所表示的范围中的元素，返回e
    c.erase(b, e);
}

// map的下标操作
// map和unordered_map容器提供了下标运算符和一个对应的at函数
void test_at()
{
    map<string, size_t> word_count;
    word_count["Anna"] = 1;
    // 执行如下操作
    // 在word_count中搜索关键字为Anna的元素，未找到
    // 将一个新关键字-值对插入到word_count中，关键字是一个const string，保存Anna
    // 值进行初始化，为0
    // 提取出新插入的元素，并将值1赋予它

    // 由于下标运算符可能插入一个新的元素，我们只可对非const的map使用下标

    string k;
    // 返回关键字为k的元素对应的值；若k不在map中，添加一个关键字为k的元素，并对其进行值初始化
    word_count[k];
    // 访问关键字为k的元素，带参数检查；若k不在map中，抛出一个out_of_range异常
    word_count.at(k);
}

// 访问元素
void test_find()
{
    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    int k = 1, m = 11;
    // find返回一个迭代器，指向第一个关键字为k的元素
    // 若k不在容器中，返回尾后迭代器
    cout << *iset.find(k) << endl;
    cout << (iset.find(m) == iset.end()) << endl;
    // count返回关键字等于k的元素的数量
    // 对于不允许重复关键字的容器，返回值永远是0或1
    cout << iset.count(k) << endl;
    cout << iset.count(m) << endl;
    // lower_bound(k);返回一个迭代器，指向第一个关键字不小于k的元素
    // upper_bound(k);返回一个迭代器，指向第一个关键字大于k的元素
    // equal_range(k);返回一个迭代器pair，表示关键字等于k的元素的范围
    // 若k不存在，pair上两个成员均等于c.end()

    // 对map使用find代替下标操作
    // 有时我们只是想知道一个给定的关键字是否在map中，并不想改变map
    // 此时当关键字不存在时，使用下标运算会插入一个新元素
}

// 无序容器
// 若关键字类型固有就是无序的，或者性能测试发现问题可以用hash技术解决，可以使用无序容器
// 无序容器在储存组织上为一个组桶
// 使用一个哈希函数将元素映射到桶
// 容器将具有一个特定哈希值的所有元素都保存在相同的桶中
// 当一个桶保存多个元素时，需要顺序搜索这些元素来查找我们想要的那个
void test_unordered_map()
{
    test_map();
}


//-----------------------------------------------------------------
// 课后练习

int main(int argc, char *argv[])
{
//    cout << "Input words!" << endl;
//    test_map();

//    test_set();

//    test_define();

//    test_pair();

//    vector<string> svec;
//    auto ret = process(svec);
//    cout << ret.first << " : " << ret.second << endl;

//    test_set_iterator();

//    test_find();

//    run_transform();

    test_unordered_map();
    return 0;
}
