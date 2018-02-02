#ifndef PICKTOOLS_H
#define PICKTOOLS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

#define K 250

using namespace std;

struct Record
{
    string name;
    int type;
};

// 非成员函数
ifstream &Read(ifstream &ifile, Record &item)
{
    ifile >> item.name >> item.type;
    return ifile;
}
ofstream &Write(ofstream &ofile, const Record &item)
{
    ofile << item.name << " " << item.type << endl;
    return ofile;
}

ofstream &Write_k(ofstream &ofile, const vector<Record> &item_set, int a[], int k)
{
    int cnt = 0, j = 0;
    for (auto it = item_set.begin(); it != item_set.end() && j < k; ++it, ++cnt)
    {
        if (cnt == a[j])
        {
            Write(ofile, *it);
            ++j;
        }
    }
//    cout << "Write_k\n" << endl;
    return ofile;
}

/**
 * @brief rand_k_in_n C语言实现
 * @param a 待选数组，生成的随机数，数组相应位置置1
 * @param n 从0 - n-1共n个数
 * @param k 要生成k个随机数
 * @param b 生成的k个随机数存放在b数组中
 */
/*
void rand_k_in_n(int a[], int n, int k, int b[])
{
    int i, j, rand_num;
    srand((int)time(0));
    for (j = 0; j < k; )
    {
        rand_num = rand() % n;
//        printf("rand_num = %d\n", rand_num);
        if (a[rand_num] == 0)
        {
            a[rand_num] = 1;
            ++j;
        }
        else
            continue;
    }
    for (i = 0, j = 0; j < n && i < k; ++j)
    {
        if (a[j] == 1)
        {
            b[i] = j;
            ++i;
        }
        else
            continue;
    }
}
*/

/**
 * @brief gen_k 正确实现，上面那个貌似有点不太对
 * @param n
 * @param k
 * @param b
 * 类似的问题还有很多，等概率选择k个数，洗牌算法等
 */
void gen_k(int n, int k, int b[])
{
    srand((int)time(0));
    int i, j = 0;
    for (i = 0; i < n; ++i)
    {
        if (rand() % (n - i) < k)
        {
            b[j] = i;
            --k;
            ++j;
        }
    }
}

void print_array(int a[], int n)
{
    int i;
    for (i = 0; i < n - 1; ++i)
        cout << a[i] << " ";
    cout << a[i] << endl;
}

#endif // PICKTOOLS_H
