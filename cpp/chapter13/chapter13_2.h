#ifndef CHAPTER13_2_H
#define CHAPTER13_2_H

#include <iostream>
#include <string>

using namespace std;

/**********************************************************/
/* HasPtr类，其行为像一个值 */
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0) { }
    // 对ps指向的string，每个HasPtr对象都有自己的拷贝
    HasPtr(const HasPtr &p) :
        ps(new string(*p.ps)), i(p.i) { }
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }

private:
    std::string *ps;
    int i;
};

// 需要注意自己赋值给自己的情况
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps; // 释放旧内存
    ps = newp;
    i = rhs.i;
    return *this;
}

// 类值的类在使用系统默认swap函数时，会导致多处赋值
// 自定义的swap只交换指针，更加高效
// 而类指针的类，调用系统默认swap时，就是在交换指针
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // 交换指针，而不是string数据
    swap(lhs.i, rhs.i);
}

#endif // CHAPTER13_2_H
