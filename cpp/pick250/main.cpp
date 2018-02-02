#include "picktools.h"

using namespace std;

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 * ��train.txt�ļ���0-999�����ͣ�ÿ��������ɸѡ��250��������Ŀ
 */
int main(int argc, char *argv[])
{
    string ifile = "E:\\workspace\\yehu\\algorithm\\pick250\\train.txt";
    string ofile = "E:\\workspace\\yehu\\algorithm\\pick250\\result.txt";
    int count = 0;
    ifstream in(ifile);
    ofstream out(ofile);

    if (in)
    {
        Record item;
        vector<Record> item_set;
        int k_item[K] = {0};

        while (Read(in, item))
        {
            if (item.type == count)
                item_set.push_back(item);
            else
            {
                int n = item_set.size();
                gen_k(n, K, k_item);
                Write_k(out, item_set, k_item, K);

                item_set.clear();
                ++count;
            }
        }
        // �������һ��
        int n = item_set.size();
        gen_k(n, K, k_item);
        Write_k(out, item_set, k_item, K);

        item_set.clear();
        ++count;
        cout << "write success !" << endl;
    }
    else
        cout << "can't open : " + ifile << endl;

/*
    if (in)
    {
        Record item;
        vector<Record> item_set;
        int k = K;
        int k_item[K] = {0};

        while(Read(in, item))
        {
            if (item.type == count)
            {
//                cout << item.name << " " << item.type << endl;
                item_set.push_back(item);
            }
            else
            {
                int n = item_set.size();
//                cout << "n = " << n << endl;
                int *a = new int[n]();
                rand_k_in_n(a, n, k, k_item);
//                print_array(k_item, k);
                Write_k(out, item_set, k_item, k);

                delete [] a;
                item_set.clear();
                ++count;
            }
        }
        // �������һ��
        int n = item_set.size();
//        cout << "n = " << n << endl;
        int *a = new int[n]();
        rand_k_in_n(a, n, k, k_item);
//        print_array(k_item, k);
        Write_k(out, item_set, k_item, k);

        delete [] a;
        item_set.clear();
        cout << "write success !" << endl;
    }
    else
        cout << "can't open : " + ifile << endl;
*/
    return 0;
}
