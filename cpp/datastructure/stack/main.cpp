#include <iostream>

using namespace std;

// 通常栈与递归的实现相关联
// 递归问题通常也能转化为使用栈来实现

// 汉诺塔问题（递归）
// X Y Z三根柱子
int count = 0;
// 将编号为n的盘子从x移到z
void move(char x, int n, char z)
{
    ++count;
    cout << x << "--" << n << "-->" << z << endl;
}

// 将n个盘子借助y，从x移动z，编号小的需要在编号大的上面
void hanoi(int n, char x, char y, char z)
{
    if (n == 1)
        move(x, 1, z);
    else
    {
        hanoi(n-1, x, z, y);
        move(x, n, z);
        hanoi(n-1, y, x, z);
    }
}

int main(int argc, char *argv[])
{
    hanoi(3, 'X', 'Y', 'Z');
    cout << "use " << count << " times to finish !" << endl;
    return 0;
}
