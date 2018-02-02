#include <iostream>
#include <string>

using namespace std;

// ����
class Quote {
public:
    Quote() = default; // Ĭ�Ϲ��캯��

    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
    { return n * price; }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

// �������
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0; // ���麯��������˳������
    std::pair<size_t, double> discount_policy() const
    { return {quantity, discount};}
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

// ������
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;

    // ÿ����������Լ��ĳ�Ա��ʼ������
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
        Disc_quote(book, p, qty, disc) { }

    // ���ǻ���ĺ�������Ҫ���壬��Ȼ�ᱨ��
    double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t) const
{
    cout << "net_price()" << endl;
}

// С����
struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};
struct D1 : B {
    void f1(int) const override;
//    void f2(int) override;
//    void f3() override;
//    void f4() override;
};
struct D2 : B {
    void f1(int) const final;
};
struct D3 : D2 {
    void f2();
//    void f1(int) const;
};

class Base {
    friend class Pal;
protected:
    int prot_mem;
};
class Sneaky : public Base {
    friend void clobber(Sneaky&);
    friend void clobber(Base&);
    int j;
};
void clobber(Sneaky &s)
{
    s.j = s.prot_mem = 0;
}
// ����ͨ����������������protected��Ԫ�أ�����Sneaky������
//void clobber(Base &b)
//{
//    b.prot_mem = 0;
//}
class Pal {
public:
    int f(Base b)
    {
        return b.prot_mem;
    }
//    int f2(Sneaky s)
//    {
//        return s.j;
//    }
    int f3(Sneaky s)
    {
        return s.prot_mem;
    }
};

int main(int argc, char *argv[])
{
//    Disc_quote discounted; // ������಻��ֱ�Ӷ������
    Bulk_quote bulk; // ���ڴ��麯��Ҫ�������壬��������ᱨ��
    Bulk_quote *bulkP = &bulk;
    Quote *itemP = &bulk;
    bulkP->discount_policy();
//    itemP->discount_policy();

    return 0;
}
