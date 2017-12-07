/****************************************************************************
 **
 ** This file is part of the chapter13 project.
 ** Copyright (C) 2017 yehu <yehuwuhan@gmail.com>.
 ** All rights reserved.
 **
 ** Author      : Ye Hu
 ** Version     : v1.0
 ** Description :
 **
****************************************************************************/

#include <iostream>
#include <string>

using namespace std;


/**********************************************************/
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
    HasPtr & operator=(const HasPtr &h)
    {
        ps = new string(*(h.ps));
        i = h.i;
        return *this;
    }

    // 析构函数
    ~HasPtr()
    {
        delete ps;
    }

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

int main(int argc, char *argv[])
{
    // 验证一下HasPtr类的拷贝构造、拷贝赋值和析构函数
    HasPtr p("some values");
    cout << "1 " << *(p.ps) << p.i << endl;
    f(p);
    cout << "2 " << *(p.ps) << p.i << endl;
    HasPtr q(p);
    p.i = 1;
    cout << "3 " << *(p.ps) << p.i << endl;
    cout << "q " << *(q.ps) << q.i << endl;
    return 0;
}
