/****************************************************************************
 **
 ** This file is part of the chapter13 project.
 ** Copyright (C) 2017 yehu <yehuwuhan@gmail.com>.
 ** All rights reserved.
 **
 ** Author      : Ye Hu
 ** Version     : v1.0
 ** Description : 1. 拷贝构造函数、拷贝赋值运算、析构函数（三/五法则中的三）
 **               2. 行为像值的类、行为像指针的类
 **               3. 交换操作：类值的类可用交换操作来优化
 **               4. 对象移动：移动构造函数、移动赋值运算符
 **
****************************************************************************/

#include "chapter13_1.h"
//#include "chapter13_2.h"
//#include "chapter13_3.h"

void test_1()
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
}

void test_2()
{
    int i = 42;
    int &r = i;
//    int &&rr = i;         // 不能将右值引用绑定到左值上
//    int &r2 = i * 42;     // 不能将左值引用绑定到右值上
    const int &r3 = i * 42; // 可以将const引用绑定到右值上
    int &&rr2 = i * 42;

    int &&rr3 = 42;
//    int &&rr4 = rr3;      // 变量是左值，表达式rr3是左值！
    int &&rr4 = std::move(rr3);

}

class Foo {
public:
    Foo &operator=(const Foo&) &;
};
Foo &Foo::operator=(const Foo &rhs) &
{
    return *this;
}
void test_3()
{
    Foo &retFoo();  // 返回左值引用
    Foo retVal();   // 返回右值引用
    Foo i, j;
    i = j;
//    retFoo() = j; // 正确
//    retVal() = j; // 错误
//    i = retVal(); // 正确
}

int main(int argc, char *argv[])
{
    test_3();
    return 0;
}
