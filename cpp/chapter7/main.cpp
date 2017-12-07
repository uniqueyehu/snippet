#include "chapter_7.h"

using namespace std;

/**********************************************************/
int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

void test_1()
{
    int j = fact(5);
    cout << "5! is " << j << endl;
}

//使用指针形参交换两个整数的值
//指针形参为值传递，能改变指针所指向的值，但无法改变指针的值
void switch_value(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    a = 0;//这里改变传入的指针的值，只改变了a的局部拷贝，实参本身并没有被改变
}

void test_2()
{
    int a = 1, b = 2;
    switch_value(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//i是传给reset函数的对象的另一个名字
//采用引用传值：
//1、避免拷贝
//2、返回额外信息
void reset(int &i)
{
    i = 0;
}


void test_3()
{
    int i = 3;
    reset(i);
    cout << "i = " << i << endl;
}
/**********************************************************/



int main(int argc, char *argv[])
{
//    test_3();
    return 0;
}
