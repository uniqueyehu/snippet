#ifndef CHAPTER_7_H
#define CHAPTER_7_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***********************************************************************/
/* Sale_data 类*/

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);

public:
    // 成员函数
    // 构造函数
    Sales_data() = default;
    // 建议使用如下形式初始化数据成员，相当于定义时立即初始化
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) { }
    // 此时如下代码也等价，但是当数据成员为const类型或引用时，只能在构造函数初始值列表初始化
    // 相当于先用默认初始化后，再赋值
//    Sales_data(const string &s, unsigned n, double p)
//    {
//        bookNo = s;
//        units_sold = n;
//        revenue = p * n;
//    }

    Sales_data(const string &s) : bookNo(s) { }
    // 委托构造函数，与上述函数等价
//    Sales_data(const string &s) : Sales_data(s, 0, 0) { }
    Sales_data(istream&);

    //此处const修改this指针类型为指向常量的指针
    // const Sales_data * const this
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const { return units_sold ? revenue/units_sold : 0; }

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 非成员函数，一般函数定义与类声明在一个文件内，此处简化处理了
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

// 成员函数类外定义
Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}
// 相当于+=操作
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

/***********************************************************************/
/* Screen 和 Window_mgr类 */
class Screen {
public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
        contents(ht * wd, c) { }

    // 读取cursor处字符，隐式内联
    char get() const { return contents[cursor]; }
    // 显式内联
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);

    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    // mutable变量即使为const类型也能修改值
    mutable size_t access_ctr = 0;
};

// 类外定义成员函数
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const
{
    ++access_ctr;
    cout << "access_ctr = " << access_ctr << endl;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // 设置cursor的新值
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch; // 设置给定位置的新值
    return *this;
}

/* Window_mgr类 */
class Window_mgr {
private:
    // 默认情况下包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif // CHAPTER_7_H
