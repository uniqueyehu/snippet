/****************************************************************************
 **
 ** This file is part of the chapter14 project.
 ** Copyright (C) 2017 yehu <yehuwuhan@gmail.com>.
 ** All rights reserved.
 **
 ** Author      : Ye Hu
 ** Version     : v1.0
 ** Description : 运算符的重载：输入输出、算术运算、关系运算、赋值运算
 **               下标运算、递增递减、成员访问运算
 **               函数调用运算
 **
****************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include <map>

using namespace std;

/*************************************************/
// 函数对象：行为像函数一样的 类的对象
struct absInt {
    int operator()(int val) const
    {
        return val < 0 ? -val : val;
    }
};

class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' ') :
        os(o), sep(c) { }
    void operator()(const string &s) const
    { os << s << sep; }

private:
    ostream &os;
    char sep;
};

class ShorterString{
public:
    bool operator()(const string &s1, const string &s2)
    { return s1.size() < s2.size(); }
};

/*************************************************/
// 标准库中的函数对象
void test()
{
    plus<int> intAdd;       // 执行加法的函数对象
    negate<int> intNegate;  // 执行取反的函数对象
    int sum = intAdd(10, 20);
    cout << "1. sum = " << sum << endl;
    sum = intNegate(intAdd(10, 20));
    cout << "2. sum = " << sum << endl;
    sum = intAdd(10, intNegate(10));
    cout << "3. sum = " << sum << endl;
}

/*************************************************/
int add(int i, int j)
{
    return i + j;
}
auto mod = [](int i, int j) { return i % j; };
struct divide {
    int operator()(int i, int j)
    {
        return i / j;
    }
};

void test_2()
{
    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = [](int i, int j){ return i * j; };

    cout << f1(4,2) << endl;
    cout << f2(4,2) << endl;
    cout << f3(4,2) << endl;


    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) {return i * j; }},
        {"%", mod} };

    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;
}

/*************************************************/
class SmallInt {
public:
    SmallInt(int i = 0): val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad SmallInt value");
    }
    // 类型转换运算符
    // operator type() const;
    // 隐式执行
//    operator int() const { return val; }

    // 显式执行
    explicit operator int() const { return val; }

private:
    std::size_t val;
};

void test_3()
{
    SmallInt si;
    si = 4; // 将4隐式转换成SmallInt，然后调用SmallInt::operator=
//    cout << "si + 3 = " << si + 3 << endl; // 将si隐式地转换成int，然后执行整数的加法
    cout << "si + 3 = " << static_cast<int>(si) + 3 << endl; // 显式地请求类型转换
}

int main(int argc, char *argv[])
{
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    cout << "ui = " << ui << endl;

    string s = "hello, world";
    PrintString printer;
    printer(s);
    PrintString errors(cerr, '\n');
    errors(s);

    string s1 = "abc";
    string s2 = "ab";
    ShorterString ss;
    if (ss(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    /*************************************************/
    test();

    /*************************************************/
    test_2();

    /*************************************************/
    test_3();
    return 0;
}
