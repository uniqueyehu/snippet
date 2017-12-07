#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
//-----------------------------------------------------------------
// ���д���
void test_find()
{
    vector<int> iv;
    for (size_t i = 0; i != 10; ++i)
        iv.push_back(i);

    int val = 4;
    // ����valԪ���Ƿ����
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
    // ͳ��val���ֵĴ���
    cout << "The times is : " << count(iv.cbegin(), iv.cend(), val) << endl;
}

void test_accumulate()
{
    vector<int> vec;
    for (size_t i = 1; i != 10; ++i)
        vec.push_back(i);

    int sum = accumulate(vec.cbegin(), vec.cend(), 0); // ���
    cout << "sum is : " << sum << endl;

    vector<string> str = {"I ", "am ", "an ", "iron ", "man"};
    string sumstr = accumulate(str.cbegin(), str.cend(), string("")); // �����ַ���
    cout << sumstr << endl;
}

//-----------------------------------------------------------------
// �κ���ϰ
void test_10_2()
{
    list<string> sl;
    string str;
    while (cin >> str)
        sl.push_back(str);

    string val = "hello";
    cout << "Hello is : "
         << count(sl.cbegin(), sl.cend(), val) // ͳ��val���ֵĴ���
         << " times" << endl;
}

void output_10_9(vector<string> &str)
{
    for (auto it = str.begin(); it != str.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// �Ƚϵ��ʳ���
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void test_10_9()
{
    vector<string> str = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    output_10_9(str);

    // ���ֵ�������
    sort(str.begin(), str.end());
    output_10_9(str);

    // ���ظ���Ԫ�ط���ĩβ
    auto end_unique = unique(str.begin(), str.end());
    output_10_9(str);

    // ɾ��β�����ظ�Ԫ��
    str.erase(end_unique, str.end());
    output_10_9(str);

    // �ȶ������㷨��ά�ֳ������Ԫ�ص�ԭ������
    stable_sort(str.begin(), str.end(), isShorter);
    output_10_9(str);
}

int main(int argc, char *argv[])
{
//    test_find();
//    test_count();
//    test_10_2();
//    test_accumulate();
    test_10_9();
    return 0;
}
