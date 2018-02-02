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
//HasPtr& HasPtr::operator=(const HasPtr &rhs)
//{
//    auto newp = new string(*rhs.ps);
//    delete ps; // 释放旧内存
//    ps = newp;
//    i = rhs.i;
//    return *this;
//}
// 用swap来定义赋值运算符，拷贝并交换
// rhs是按值传递的，不是传递的引用
// 拷贝构造函数起作用，将右侧运算对象的参数拷贝到rhs中
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // 交换左侧运算对象和局部变量rhs的内容
    swap(*this, rhs);   // rhs现在指向本对象曾经使用的内存
    return *this;       // rhs被销毁，从而delete了rhs中的指针
}


// 类值的类在使用系统默认swap函数时，会导致多处赋值
// 自定义的swap只交换指针，更加高效
// 而类指针的类，调用系统默认swap时，就是在交换指针
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);   // 交换指针，而不是string数据
    swap(lhs.i, rhs.i);     // 调用内置swap函数，若有其他类类型，则调用类类型的swap函数，故不加std::限定
}

#endif // CHAPTER13_2_H
