#ifndef MYVECTOR_H
#define MYVECTOR_H
// 主要是一些vector的基本用法
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void test()
{
    // 定义
    vector<int> iv;

    // 添加元素
    int val1 = 20;
    int val2 = 30;
    iv.push_back(10);
    iv.push_back(val1);
    iv.insert(iv.begin(), val2);    // 在头部插入val2

    // 元素分布：30, 10, 20
    // 访问元素
    if (!iv.empty()) {
        auto last = iv.end();
        cout << iv.front() << endl;     // 相当于begin()
        cout << iv[1] << " equal to " << iv.at(1) << endl;
        cout << *(--last) << endl;      // 相当于back()
    }

    // 删除元素
    iv.pop_back();
    cout << "size = " << iv.size() << endl;
    auto iter = iv.begin();
    iter = iv.erase(iter);     // erase后，返回iter指向后面一个位置，原来iter的值失效了，再使用的话结果未定义
    cout << "size = " << iv.size() << " iter = " << *iter << endl;
    iv.clear();
    cout << "size = " << iv.size() << endl;

}

#endif // MYVECTOR_H
