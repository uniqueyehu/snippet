#ifndef CHAPTER13_1_H
#define CHAPTER13_1_H

#include <iostream>
#include <string>

using namespace std;

/**********************************************************/
/* HasPtr类 */
class HasPtr {
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0) { }

    // 拷贝构造函数
//    HasPtr(const HasPtr &orig) :
//        ps(new string(*(orig.ps))), i(orig.i) { }
    // 感觉应该是等价的
    HasPtr(const HasPtr &hp)
    {
        ps = new string(*hp.ps);
        i = hp.i;
    }

    // 拷贝赋值运算符
    HasPtr& operator=(const HasPtr &h)
    {
        auto newps = new string(*(h.ps));
        delete ps; // 这里需要释放掉原来的内存
        ps = newps;
        i = h.i;
        return *this;
    }

    // 析构函数
    // 先执行函数体，再自动销毁变量
    ~HasPtr()
    {
        delete ps;
    }

    // 为了方便验证才去掉private
//private:
    string *ps;
    int i;
};

HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;
    ret.i = 5;
    return ret;
}

/**********************************************************/
/* NoCopy类 */
// c++ 11新标准
struct NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;             // 阻止拷贝
    NoCopy &operator=(const NoCopy&) = delete;  // 阻止赋值
    ~NoCopy() = default;
};

/**********************************************************/
/* PrivateCopy类 */
// 拷贝控制成员是private的，普通用户代码无法访问，达到阻止拷贝效果
class PrivateCopy {
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy();
};

#endif // CHAPTER13_1_H
