#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>

using namespace std;
//-----------------------------------------------------------------
// ���д���
void test_map()
{
    // ͳ��ÿ�������������г��ֵĴ���
    // mapΪ�����key-value����key���򣬿ɰ�key����
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    // ��map����ȡһ��Ԫ��ʱ����õ�һ��pair���Ͷ���
    // pair.first����ؼ���
    // pair.second�����Ӧ��ֵ
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
}

void test_set()
{
    // ͳ��ÿ�������������г��ֵĴ���
    // mapΪ�����key-value����key���򣬿ɰ�key����
    // setΪ�����key���ϣ���key����
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
    map<string, size_t> word_count; // ������
    // �б��ʼ��
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    map<string, string> authors = { {"Joyce", "James"},
                                    {"Austen", "Jane"},
                                    {"Dickens", "Charles"} };

    // ��ʼ��multimap��multiset
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
    {
        ivec.push_back(i);
        ivec.push_back(i); // ÿ�����ظ�����һ��
    }
    // iset��������ivec�Ĳ��ظ���Ԫ�أ�miset��������20��Ԫ��
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;
}

// pair������ͷ�ļ�utility��
void test_pair()
{
    // һ��pair�����������ݳ�Ա
    // ����һ��pairʱ��Ҫ�ṩ���������������Բ�ͬ����
    // Ĭ�ϳ�ʼ��
    pair<string, string> anon;          // ��������string
    pair<string, size_t> word_count;    // ����һ��string��һ��size_t
    pair<string, vector<int>> line;     // ����string��vector<int>

    // �ṩ��ʼ����
    pair<string, string> author{"James", "Joyce"};
    // ������Ա�ֱ�Ϊfirst��second
    cout << author.first << " - " << author.second << endl;
}

// ��������pair����
pair<string, int> process(vector<string> &v)
{
    // ����v��back()Ϊvector�����һ��Ԫ��
    v.push_back("hello");
    if (!v.empty())
//        return {v.back(), v.back().size()}; // �б��ʼ��
//        return pair<string, int>(v.back(), v.back().size()); // ����C++�汾�������û���������ʼ��
        return make_pair(v.back(), v.back().size()); // ʹ��make_pair������pair����
    else
        return pair<string, int>(); // ��ʽ���췵��ֵ
}

// set�ĵ�������const��
void test_set_iterator()
{
    // ����������ʼ��ʱ���Զ����ؼ�����������
    set<int> iset = {0,1,7,3,4,9,6,2,8,5};
    set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end())
    {
//        *set_it = 42; // ���󣺹ؼ�����const��
        cout << *set_it << endl; // ��ȷ������ͨ���������ı�Ԫ��
    }

    // ������������
    auto s_it = iset.cbegin();
    while (s_it != iset.cend())
    {
        cout << *s_it << ",";
        ++s_it;
    }
    cout << endl;
}

// ���Ԫ��
void test_insert()
{
    vector<int> ivec = {2,4,6,8,2,4,6,8};       // ivec��8��Ԫ��
    set<int> set2;                              // �ռ���
    // insert�������汾���ֱ����һ�Ե�����������һ����ʼ���б�
    set2.insert(ivec.cbegin(), ivec.cend());    // set2��4��Ԫ�أ�ȥ���ظ�
    set2.insert({1,3,5,7,1,3,5,7});             // set2������8��Ԫ�أ�������1��3��5��7

    // ��map���Ԫ��
    map<string, size_t> word_count;
    string word;
    // 4�ַ���
    word_count.insert({word, 1}); // �±�׼����򵥵ķ���
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
}

void test_insert2()
{
    map<string, size_t> word_count;
    string word;

    while (cin >> word)
    {
        // insert����һ��pair
        // pair<map<string, size_t>::iterator, bool>
        // pair��first��Ա��һ����������ָ������и����ؼ��ֵ�Ԫ�أ���map�е�Ԫ��
        // second��Ա��һ��boolֵ��ָ��Ԫ���Ƿ����ɹ������Ѿ�������������
        // �����������У���insertʲôҲ����������ֵ�е�boolΪfalse
        // ���ؼ��ֲ����ڣ�Ԫ�ؽ������������У�boolֵΪtrue
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
}

// ɾ��Ԫ��
void test_delete()
{
    map<string, size_t> c;
    string k;
    auto p = c.begin();
    auto b = c.begin();
    auto e = c.end();

    // ��c��ɾ��ÿ���ؼ���Ϊk��Ԫ��
    // ����һ��size_typeֵ��ָ��ɾ����Ԫ������
    // ���ڲ��ظ��ؼ��ֵ�����������ֵΪ0����1
    // ���ڿ��ظ��ؼ��ֵ�����������ֵ���ܴ���1
    c.erase(k);
    // ��c��ɾ��������pָ����Ԫ��
    // p����ָ��c��һ����ʵ��Ԫ�أ����ܵ���c.end()
    // ����һ��ָ��p֮��Ԫ�صĵ�����
    c.erase(p);
    //ɾ����������(b, e)����ʾ�ķ�Χ�е�Ԫ�أ�����e
    c.erase(b, e);
}

// map���±����
// map��unordered_map�����ṩ���±��������һ����Ӧ��at����
void test_at()
{
    map<string, size_t> word_count;
    word_count["Anna"] = 1;
    // ִ�����²���
    // ��word_count�������ؼ���ΪAnna��Ԫ�أ�δ�ҵ�
    // ��һ���¹ؼ���-ֵ�Բ��뵽word_count�У��ؼ�����һ��const string������Anna
    // ֵ���г�ʼ����Ϊ0
    // ��ȡ���²����Ԫ�أ�����ֵ1������

    // �����±���������ܲ���һ���µ�Ԫ�أ�����ֻ�ɶԷ�const��mapʹ���±�

    string k;
    // ���عؼ���Ϊk��Ԫ�ض�Ӧ��ֵ����k����map�У����һ���ؼ���Ϊk��Ԫ�أ����������ֵ��ʼ��
    word_count[k];
    // ���ʹؼ���Ϊk��Ԫ�أ���������飻��k����map�У��׳�һ��out_of_range�쳣
    word_count.at(k);
}

// ����Ԫ��
void test_find()
{
    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    int k = 1, m = 11;
    // find����һ����������ָ���һ���ؼ���Ϊk��Ԫ��
    // ��k���������У�����β�������
    cout << *iset.find(k) << endl;
    cout << (iset.find(m) == iset.end()) << endl;
    // count���عؼ��ֵ���k��Ԫ�ص�����
    // ���ڲ������ظ��ؼ��ֵ�����������ֵ��Զ��0��1
    cout << iset.count(k) << endl;
    cout << iset.count(m) << endl;
    // lower_bound(k);����һ����������ָ���һ���ؼ��ֲ�С��k��Ԫ��
    // upper_bound(k);����һ����������ָ���һ���ؼ��ִ���k��Ԫ��
    // equal_range(k);����һ��������pair����ʾ�ؼ��ֵ���k��Ԫ�صķ�Χ
    // ��k�����ڣ�pair��������Ա������c.end()

    // ��mapʹ��find�����±����
    // ��ʱ����ֻ����֪��һ�������Ĺؼ����Ƿ���map�У�������ı�map
    // ��ʱ���ؼ��ֲ�����ʱ��ʹ���±���������һ����Ԫ��
}

// ��������
// ���ؼ������͹��о�������ģ��������ܲ��Է������������hash�������������ʹ����������
// ���������ڴ�����֯��Ϊһ����Ͱ
// ʹ��һ����ϣ������Ԫ��ӳ�䵽Ͱ
// ����������һ���ض���ϣֵ������Ԫ�ض���������ͬ��Ͱ��
// ��һ��Ͱ������Ԫ��ʱ����Ҫ˳��������ЩԪ��������������Ҫ���Ǹ�

//-----------------------------------------------------------------
// �κ���ϰ

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

    test_find();
    return 0;
}
