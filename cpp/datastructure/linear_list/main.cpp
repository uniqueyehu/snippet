#include <iostream>
#include "linklist.h"

using namespace std;

int main(int argc, char *argv[])
{
    LinkList mylist;
    int i, j;
    int a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45};

    CreateList_L_Front(mylist, a, 10);
    cout << "Data in Link List :" << endl;
    ListTraverse_L(mylist);

    return 0;
}
