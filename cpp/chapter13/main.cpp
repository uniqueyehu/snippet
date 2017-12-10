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
 **               3. 交换操作
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

int main(int argc, char *argv[])
{
    test_1();
    return 0;
}
