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

// �ǳ�Ա����
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
 * @brief rand_k_in_n C����ʵ��
 * @param a ��ѡ���飬���ɵ��������������Ӧλ����1
 * @param n ��0 - n-1��n����
 * @param k Ҫ����k�������
 * @param b ���ɵ�k������������b������
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
 * @brief gen_k ��ȷʵ�֣������Ǹ�ò���е㲻̫��
 * @param n
 * @param k
 * @param b
 * ���Ƶ����⻹�кܶ࣬�ȸ���ѡ��k������ϴ���㷨��
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
