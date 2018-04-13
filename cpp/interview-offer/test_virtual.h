#ifndef TEST_VIRTUAL_H
#define TEST_VIRTUAL_H

#include "snippet.h"

class Base {
public:
    virtual void f1()
    {
        cout << "Base::f1()" << endl;
    }
};
class Base1 : virtual public Base {
public:
    virtual void f1()
    {
        cout << "Base1::f1()" << endl;
    }
};
class Base2 : virtual public Base {
public:
    virtual void f1()
    {
        cout << "Base2::f1()" << endl;
    }
};
class Dervie : public Base1, public Base2 {
public:
    virtual void f1() // 若不覆盖f1，编译报错
    {
        cout << "Dervie::f1()" << endl;
    }
};

void test_virtual()
{
    Dervie d;
    d.f1();
}

#endif // TEST_VIRTUAL_H
