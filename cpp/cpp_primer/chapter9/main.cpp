#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
// 适配器adaptor
#include <stack>
#include <queue>


#include "myvector.h"

using namespace std;

// 文中代码
void test_string()
{
    int i = 42;
    string s = to_string(i);    // 将整数转换为字符形式
    double d = stod(s);         // 将字符串s转换为浮点数
    cout << s << " " << d << endl;

    string s2 = "pi = 3.14";
    d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
    cout << "d = " << d << endl;
}

void test_stack()
{
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix);
    while (!intStack.empty()) {
        int value = intStack.top();
        cout << value << " ";
        intStack.pop();
    }
}

void test_queue()
{
    queue<int> intQueue;
    for (size_t ix = 0; ix != 10; ++ix)
        intQueue.push(ix);
    cout << "1111 size is : " << intQueue.size() << endl;
    int value = intQueue.front();
    cout << "front is : " << value << endl;
    cout << "2222 size is : " << intQueue.size() << endl;
    intQueue.pop();
    cout << "3333 size is : " << intQueue.size() << endl;
    value = intQueue.back();
    cout << "back is : " << value << endl;
}

//------------------------------------------------------------------------------------------
// 课后练习

vector<int> iv = {1, 3, 5, 7, 2, 9, 13, 6};

bool test_9_4(vector<int>::iterator b, vector<int>::iterator e, int t)
{
    for (; b != e; ++b) {
        if(*b == t)
            return true;
    }
    return false;
}

vector<int>::iterator test_9_5(vector<int>::iterator b, vector<int>::iterator e, int t)
{
    for (; b != e; ++b) {
        if(*b == t)
            return b;
    }
    return e;
}

void test_9_18()
{
    deque<string> destr;
    string str;

    while (cin >> str)
        destr.push_front(str);
//        destr.push_back(str);

    for (auto iter = destr.begin(); iter != destr.end(); ++iter)
        cout << *iter << endl;
}

void test_9_19()
{
    list<string> sl;
    string str;

    while (cin >> str)
        sl.push_back(str);

    for (auto iter = sl.cbegin(); iter != sl.cend(); ++iter)
        cout << *iter << endl;
}

void test_9_20()
{
    list<int> il;
    deque<int> id1, id2;

    for(int i = 1; i <= 10; ++i)
        il.push_back(i);

    for(auto it = il.cbegin(); it != il.cend(); ++it)
    {
        if(*it % 2)
            id1.push_back(*it);
        else
            id2.push_back(*it);
    }

    for(auto it = id1.cbegin(); it != id1.cend(); ++it)
        cout << *it << endl;
    cout << "break line ---------" << endl;
    for(auto it = id2.cbegin(); it != id2.cend(); ++it)
        cout << *it << endl;
}



int main(int argc, char *argv[])
{
//    int r = test_9_4(iv.begin(), iv.end(), 2);
//    cout << "find 2 result is " << r << endl;
//    int r2 = test_9_4(iv.begin(), iv.end(), 4);
//    cout << "find 4 result is " << r2 << endl;

    // 返回相应的迭代器，未找到时返回end
//    cout << test_9_5(iv.begin(), iv.end(), 2) - iv.begin() << endl;
//    cout << test_9_5(iv.begin(), iv.end(), 4) - iv.begin() << endl;

//    test_9_20();
//    test_stack();
    test_queue();
//    test_string();
//    test();
    return 0;
}
