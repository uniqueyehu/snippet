# C++ Primer notes
The notes of some chapters in `C++ Primer`

## 1. chapter1

## 7. chapter7
类的定义：类的成员函数、非成员函数、构造函数、析构函数、访问控制、友元、类的静态成员。

其他：类类型、委托构造函数、聚合类

## 8. chapter8
IO类：istream、ostream、iostream（头文件iostream）

文件输入输出类：ifstream、ofstream、fstream（头文件fstream）

string流：istringstream、ostringstream、stringstream（头文件sstream）

## 9. chapter9
容器库：迭代器、容器类型成员、begin和end成员、

容器操作：

container.insert(p, t);在p指向的元素之前创建一个值为t的元素，返回指向新添加的元素的迭代器。

container.erase(p);删除p所指向的元素，返回一个指向被删元素之后元素的迭代器。

顺序容器：vector、deque、list、forward_list、array、string

容器适配器：stack、queue、priority_queue。基于某个容器实现，使其行为像另一个容器。本质上，一个适配器是一种机制，能使某种行为看起来像另一种事物一样。

## 10. chapter10
泛型算法：

只读：find、accumulate、equal、count

写容器：fill、fill_n、copy、replace、replace_copy

重排容器元素：sort、unique

定制操作：lambda表达式、参数绑定bind

插入迭代器（迭代器适配器）：back_inserter(vec)，返回一个与该容器绑定的插入迭代器，当我们通过此迭代器赋值时，赋值运算会调用push_back将一个具有给定值的元素添加到容器中。front_inserter、inserter

iostream迭代器

反向迭代器

## 11. chapter11
关联容器：map、set

以及它们的变种：multimap、multiset（多关键字）；unordered_map、unorder_set（无序，用哈希函数组织）；unordered_multimap、unorder_multiset（无序，用哈希函数组织，关键字可重复）

关联容器操作：定义、迭代器、添加元素、删除元素、访问元素

无序容器：用哈希技术来存储和访问元素。

## 12. chapter12
动态内存：从堆上分配，使用new和delete来管理

智能指针：shared_ptr、unique_ptr、weak_ptr

动态数组：
```
int *p = new int[42];
delete [] p;
```

## 13. chapter13
拷贝构造函数、拷贝赋值运算符、析构函数（三）

三/五法则

交换操作：一般类值的类可用交换操作进行优化

右值引用

移动构造函数、移动赋值运算符（五）

## 14. chapter14
不建议重载的运算符：逗号、取地址、逻辑与、逻辑或运算符

定义为成员函数：赋值（=）、下标（[]）、调用（()）、成员访问箭头（->）、复合运算符、改变对象状态的运算符

输入输出运算符重载：`<<`、`>>`通常定义为非成员函数，输入通常要检测可能失败的情况

算术和关系运算符重载：`+`的重载通常用`+=`来实现，`!=`通常用`==`来实现。

赋值运算符：拷贝赋值运算、移动赋值运算、接受花括号内的元素列表作为参数的赋值运算符

下标运算符：`[]`应该定义为成员函数，通常定义`常量版本`和`非常量版本`

递增和递减运算符：`++`、`--`建议定义为成员函数，通常有前置和后置两个版本：前置版本：`Type operator++();`；后置版本：`Type operator++(int)`，编译器为int形参提供值为0的形参，但我们不使用。

成员访问运算符：箭头运算符（->）必须是类的成员，解引用运算符（*）通常也是类的成员

函数调用运算符：函数调用运算符（()）必须是成员函数

类型转换运算符：必须是成员函数，不能声明返回类型，形参列表必须为空，通常是const。类型转换运算符形式：operator type() const;

## 15. chapter15
基类和派生类：引用或指针由派生类向基类转换，反之不行。静态成员只有唯一实例。

虚函数：基类希望其派生类进行覆盖的函数，使用指针或引用调用虚函数时，该调用被动态绑定。（多态）

抽象基类：含有纯虚函数的类是抽象基类，纯虚函数用“=0”表示，表明当前的虚函数没有实际意义，纯虚函数无需定义。我们不能创建抽象基类的对象。

访问控制：public、protect（派生类和友元能访问）、private（仅类自己能访问）

## 16. chapter16
函数模板：

类模板：
