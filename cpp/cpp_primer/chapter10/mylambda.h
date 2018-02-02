#ifndef MYLAMBDA_H
#define MYLAMBDA_H

#include <iostream>

using namespace std;

// lambda表达式的形式，捕获列表和函数体必须存在，其他可忽略
// 捕获列表 表示使用它所在函数中的局部变量，可以直接使用定义在当前函数之外的名字
// [捕获列表](形参列表) -> 返回类型 { 函数体 }

// 只使用一两次的时候，使用lambda表达式
// 多次使用，或者操作需要很多语句时，通常使用函数

// 当lambda表达式捕获列表为空时，可以用函数来替代它

// 当泛型算法需要一元谓词时，具有两个参数的函数就不妥了，使用lambda表达式，捕获一个参数，只是用一个参数

void test_lambda()
{
    auto f = [] { return 42; };
    cout << f() << endl;    // 打印42

    size_t v1 =42;
    auto f1 = [v1] () mutable { return ++v1; };     // 加上mutable之后，v1值才能被修改
    v1 = 0;
    auto j = f1();      // j = 43
    cout << "j = " << j << endl;

    size_t v2 = 42;
    auto f2 = [&v2] { return ++v2; };
    v2 = 0;
    auto k = f2();
    cout << "k = " << k << endl;
}

#endif // MYLAMBDA_H
