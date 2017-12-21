#ifndef CHAPTER13_3_H
#define CHAPTER13_3_H

#include <iostream>
#include <string>

using namespace std;

/**********************************************************/
/* HasPtr类，其行为像一个指针*/
/* 不使用shared_ptr来管理类中的资源，使用引用计数 */
class HasPtr {
public:
    // 构造函数分配新的string和新的计数器
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0), use(new size_t(1)) { }
    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &p) :
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use; // 引用计数指针
};

HasPtr::~HasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // 递增右侧运算对象的引用计数，类似拷贝构造函数工作
    if (--*use == 0) { // 递减本对象的引用计数，类似析构函数工作
        delete ps;
        delete use;
    }
    // 将数据从rhs拷贝到本对象
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}


#endif // CHAPTER13_3_H
