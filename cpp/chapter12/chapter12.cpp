#include <iostream>
#include <memory>
#include <list>
#include <vector>

using namespace std;

// 动态内存
// 除了静态内存和栈内存，每个程序还拥有一个内存池
// 称为自由空间或堆，程序用堆来存储动态分配的对象
// 动态内存的管理通过new和delete来完成
// new在动态内存中为对象分配空间，并返回指向该对象的指针
// delete销毁该对象，并释放与之关联的内存（销毁+释放）
//
// 问题
// new之后忘记释放内存，会产生内存泄漏
// 指针有引用时就释放了，会产生应用非法内存的指针

// 智能指针，定义在memory头文件中
// shared_ptr
// 允许多个指针指向同一个对象
// shared_ptr<T> sp;    空智能指针，可以指向类型为T的对象
// p                        将p用作一个条件判断，若p指向一个对象，则为true
// *p                       解引用p，获得它指向的对象
// p->mem / (*p).mem        访问p所指向对象的成员
// p.get()                  返回p中保存的指针，返回一个内置指针
// swap(p, q) / p.swap(q)   交换p和q中指针

// make_shared<T>(args)     返回一个shared_ptr，指向一个动态分配的类型为T的对象。使用args初始化
// shared_ptr<T>p(q)        p是shared_ptr q的拷贝；此操作会递增q的计数器。q中的指针必须能转换成T*
// p = q                    p和q都是shared_ptr，所保存的指针必须能相互转换。
//                          此操作会递减p的引用计数，递增q中的引用计数；若p的引用计数变为0，则将其管理的原内存释放
// p.unique()               若p.use_count()为1，返回true；否则返回false
// p.use_count()            返回与p共享的智能指针数量；可能很慢，主要用于调试


void test_share_ptr()
{
    // 定义智能指针
    // shared_ptr<T> sp;
    shared_ptr<string> p1;      // 可以指向string
    shared_ptr<list<int>> p2;   // 可以指向int的list

    // 若p1不为空，检查它是否指向一个空string
    if (p1 && p1->empty())
        *p1 = "hi"; // 若p1指向一个空string，解引用p1，将一个新值赋予string

    // 指向一个值为42的int的shared_ptr
    shared_ptr<int> p3 = make_shared<int>(42);
    // 指向一个值为“9999999999”的string
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    // 指向一个值初始化的int，即，值为0
    shared_ptr<int> p5 = make_shared<int>();

    cout << *p3 << endl;
    cout << *p4 << endl;
    cout << *p5 << endl;

    // shared_ptr的拷贝和赋值
    auto p = make_shared<int>(42); // p指向的对象只有p一个引用者
    auto q(p); // p和q指向相同对象

    // 递增
    // 用一个shared_ptr初始化另一个shared_ptr时
    // 将它作为参数传递给一个函数
    // 作为函数的的返回值
    // 递减
    // 给shared_ptr赋予新值
    // shared_ptr被销毁

    auto r = make_shared<int>(33);
    r = q; // 递增q指向的对象的引用计数
           // 递减r原来指向的对象的引用计数
           // r原来指向的对象已经没有引用者，会自动释放

    // 析构函数来销毁shared_ptr所指向的对象，释放它们所占用的内存

    // 若将shared_ptr存放于一个容器中，而后不再需要全部元素，只使用
    // 其中一部分，要记得用erase删除不再需要的元素

    // new
    // 分配内存；并指向该对象
    // 用new分配的内存是无名的
    int *pi = new int; // pi指向一个动态分配的、未初始化的无名对象
    int *pi2 = new int(); // 值初始化为0
    string *ps1 = new string(); // 默认初始化为空string
    // 默认情况下，动态分配的对象是默认初始化的
    // 内置类型或者组合类型的对象的值是未定义的
    // 类类型对象将用默认构造函数进行值初始化

    // 若提供括号包围的初始化器，可以使用auto
    int obj = 42;
    auto p6 = new auto(obj); // p指向一个与obj类型相同的对象
    //int a, b, c;
    //auto p7 = new auto{a, b, c}; // 错误：括号中只能有单个初始化器

    // 动态分配const对象
    const int *pci = new const int(1024);

    // 使用定位new，如果分配失败，new返回一个空指针
    int *p8 = new (nothrow) int;

    // delete
    // 销毁给定的指针所指向的对象；释放对应的内存
    // 传递给delete的指针必须指向动态分配的内存，或者是一个空指针
    // 释放一个const对象
    delete pci;

    // 由内置指针（而不是智能指针）管理的动态内存在被显式释放前一直都会存在

    // 不能将一个内置指针隐式转换为一个智能指针，必须使用直接初始化形式
    //shared_ptr<int> p9 = new int(1024); // 错误
    shared_ptr<int> p10(new int(1024)); // 正确
    /*
    // 错误
    shared_ptr<int> clone(int p) {
        return new int(p);
    }

    // 正确
    shared_ptr<int> clone(int p) {
        return shared_ptr<int>(new int(p));
    }
    */

    // get函数返回一个内置指针，指向智能指针管理的对象
    // 当我们需要向不能使用智能指针的代码中传递一个内置指针时，使用get
    // 使用get返回的指针的代码不能delete此指针
    // 不要使用get初始化另一个智能指针或为智能指针赋值

    // reset
    shared_ptr<int> p11;
    //p = new int(1024); // 错误：不能将一个指针赋予shared_ptr
    p11.reset(new int(1024)); // 正确：p指向一个新对象

    // 在资源分配和释放之间发生了异常，程序也会发生内存泄漏
    // 创建一个shared_ptr时，可以传递一个指向删除器函数的参数
    // p将使用可调用对象d来代替delete
    // shared_ptr<T> p(q, d);

    // 使用规范
    // 不使用相同的内置指针 值初始化（或reset）多个智能指针
    // 不delete get()返回的指针
    // 不使用get()初始化或reset另一个智能指针
    // 当使用get()返回的指针，记住当最后一个对应的智能指针销毁后，指针就变为无效了
    // 如果使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器
}


// unique_ptr
// 独占所指的对象
// 某个时刻只能有一个unique_ptr指向一个给定的对象
void test_unique_ptr()
{
    // 没有类似make_shared的操作
    // 需要将其绑定到一个new返回的指针上
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));

    //unique_ptr<int> p3(p2); // 错误：unique_ptr不支持拷贝
    unique_ptr<int> p4;
    //p4 = p2; // 错误：unique_ptr不支持赋值

    // 支持的操作
    // 空unique_ptr，可以指向类型为T的对象，使用delete
    // unique_ptr<T> u1
    // 使用D的可调用对象来释放它的指针
    // unique_ptr<T, D> u2
    // u放弃对指针的控制权，返回指针，并将u置为空
    // u.release()
    // 释放u指向的对象，若提供了内置指针q，令u指向这个对象；否则将u置为空
    // u.reset()
    // u.reset(q)

    // 将所有权从p2转移给p5，release将p2置为空
    unique_ptr<int> p5(p2.release());
    cout << "p5 = " << *p5 << endl;
    unique_ptr<int> p6(new int(24));
    // 将所有权从p6转移给p5，reset释放了p5原来指向的内存
    p5.reset(p6.release());
    cout << "p5' = " << *p5 << endl;
    // release会切断unique_ptr和它原来管理的对象间的联系
    // release返回的指针通常被用来初始化另一个智能指针
    // 或者给另一个智能指针赋值
    //p5.release(); // 错误：p2不会释放内存，而且我们丢失了指针
    auto p = p5.release(); // 正确，但我们必须记得delete(p)
}

// weak_ptr
// 指向由一个shared_ptr管理的对象
// 将weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数
// 当最后一个指向对象的shared_ptr被销毁，对象就会被释放，即使有weak_ptr指向对象

// w.use_count()    返回与w共享对象的shared_ptr的数量
// w.expired()      若use_count为0，返回true，否则返回false
// w.lock()         若expired为true，返回一个空shared_ptr；否则返回一个指向w的对象的shared_ptr
// 由于对象可能不存在，我们不能用weak_ptr直接访问对象，必须调用lock
void test_weak_ptr()
{
    // weak_ptr像是shared_ptr的助手，没有重载operator *和->
    // 它的最大作用在于协助shared_ptr工作，像一个观测者
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);
//    cout << "wp = " << *wp << endl; // 不能这样用

    if (shared_ptr<int> np = wp.lock())
    {
        // 在if中，np与p共享对象
        cout << "np = " << *np << endl;
        cout << "p = " << *p << endl;
    }
}

// 动态数组
void test_array()
{
    int n = 10;
    int *pia = new int[n]; // 10个未初始化的int
    int *pia2 = new int[10](); // 10个值初始化为0的int
    cout << "pia2 : " <<pia2[0] << endl;
    delete [] pia;
    delete [] pia2;

    string *psa = new string[10]; // 10个空string
    string *psa2 = new string[10](); // 10个空string
    cout << "psa2 : " << psa2[0] << endl;
    delete [] psa;
    delete [] psa2;

    // 10个int分配用列表中对应的初始化器初始化
    int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    // 10个string，前4个用给定的初始化器初始化，剩余的进行值初始化
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};
    cout << "pia3 : " << pia3[5] << endl;
    cout << "psa3 : " << psa3[0] << ", "
         << psa3[3] << ", " << psa3[5] << "." << endl;
    delete [] pia3;
    delete [] psa3;

    // 动态分配一个空数组是合法的
    // 对于长度为0的数组来说，此时p相当于尾后指针
    size_t n1 = 0;
    int *p = new int[n1];
    for (int *q = p; q != p + n; ++q)
        *q = 1;
    cout << "p : " << p << endl;
    delete [] p;

    // up指向一个包含10个未初始化int的数组
    unique_ptr<int[]> up(new int[10]);
    up.release(); // 自动用delete[]销毁其指针

    // 为了使用shared_ptr，必须提供一个删除器
    shared_ptr<int> sp(new int[10], [](int *p) { delete [] p; });
    sp.reset(); //使用我们提供的lambda释放数组，它使用delete[]
}

// allocator类
// 将内存分配和对象构造分离开
void test_allocator()
{
    int n = 5;
    // 创建一大块内存，为可分配string的allocator对象
    allocator<string> alloc;
    // 分配了n个未初始化的string
    auto const p = alloc.allocate(n);

    // a.construct(p, args)
    // 在p指向的内存中构造一个对象
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");

    cout << p[3] << endl;

    // a.destroy(p)
    // 对p指向的对象执行析构函数
    while (q != p)
        alloc.destroy(--q);

    // a.deallocate(p, n)
    // 释放从p开始的内存，n与allocate创建时大小相同
    alloc.deallocate(p, n);

    // 拷贝和填充未初始化内存的算法
    //
    // 从b到e范围中拷贝元素到b2开始的内存中，返回一个指针指向下一个内存地址
    // uninitialized_copy(b, e, b2)
    // 从b指向的元素开始，拷贝n个元素到b2开始的内存中，返回一个指针指向下一个内存地址
    // uninitialized_copy_n(b, n, b2)
    // 从b到e范围的元素，创建对象，对象的值均为t的拷贝
    // uninitialized_fill(b, e, t)
    // 从b指向的元素开始，拷贝n个值为t的对象到未构造的内存中
    // uninitialized_file_n(b, n, t)
    vector<int> v;
    for (size_t i = 0; i != 10; ++i)
        v.push_back(i);
    allocator<int> alloc2;

    // 分配比v中元素所占用空间大一倍的动态内存
    auto pv = alloc2.allocate(v.size() * 2);
    // 通过拷贝v中的元素来构造从pv开始的元素
    auto qv = uninitialized_copy(v.begin(), v.end(), pv);
    // 将剩余元素初始化为42
    auto endp = uninitialized_fill_n(qv, v.size(), 42);

    for (auto it = pv; it != (pv + v.size() * 2); ++it)
        cout << *it << " " << endl;

    while (endp != pv)
        alloc2.destroy(--endp);
//    for (auto it = pv; it != (pv + v.size() * 2); ++it)
//        alloc2.destroy(it);
    alloc2.deallocate(pv, v.size() * 2);
}


int main(int argc, char *argv[])
{
//    test_share_ptr();
//    test_unique_ptr();
//    test_weak_ptr();
//    test_array();
    test_allocator();
    return 0;
}
