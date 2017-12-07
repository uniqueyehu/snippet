#ifndef CHAPTER_7_H
#define CHAPTER_7_H

#include <iostream>
#include <string>

using namespace std;

/***********************************************************************/
/* Sale_data 类*/

class Sales_data {
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
public:
    // 成员函数
    Sales_data() = default;
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const string &s) : bookNo(s) { }
    Sales_data(istream&);
    //此处const修改this指针类型为指向常量的指针
    // const Sales_data * const this
    string isbn() const
    {
        return bookNo;
    }
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const
    {
        return units_sold ? revenue/units_sold : 0;
    }

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// 非成员函数
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

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

/***********************************************************************/




#endif // CHAPTER_7_H
