/****************************************************************************
 **
 ** This file is part of the cprimer_7 project.
 ** Copyright (C) 2017 yehu <yehuwuhan@gmail.com>.
 ** All rights reserved.
 **
 ** Author      : Ye Hu
 ** Version     : v1.0
 ** Description : 类的定义、类的成员函数、非成员函数、类的构造函数
 **               访问控制、友元、类的静态成员
 **
****************************************************************************/

#include "chapter_7.h"

using namespace std;

int main(int argc, char *argv[])
{
    Screen myscreen;
    char ch = myscreen.get();
    cout << ch << endl;
    ch = myscreen.get(0, 0);
    cout << ch << endl;
    // 光标移到(4,0)，设置该位置为#
    myscreen.move(4,0).set('#');
    cout << myscreen.get() << endl;

//    myscreen.some_member();
//    myscreen.some_member();

    return 0;
}
