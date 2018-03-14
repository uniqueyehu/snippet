/*
 * 10大排序算法
 */
#include <iostream>
#include "bubble.h"
#include "select.h"
#include "insert.h"
#include "shell.h"
#include "merge.h"
#include "quick.h"
#include "heap.h"
#include "radix.h"

using namespace std;

void print_array(int array[], int len)
{
    int i;
    for(i = 0; i < len - 1; ++i)
        cout << array[i] << " ";
    cout << array[i] << endl;
}

int main(int argc, char *argv[])
{
    int array[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int temp[11];
    int len = (int) sizeof(array) / sizeof(*array);

    cout << "Before Sort :" << endl;
    print_array(array, len);

//    cout << "Bubble Sort :" << endl;
//    bubble_sort(array, len);

//    cout << "Simple Select Sort :" << endl;
//    select_sort(array, len);

//    cout << "Simple Insert Sort :" << endl;
//    insert_sort(array, len);

//    cout << "Shell Sort :" << endl;
//    shell_sort(array, len);

//    cout << "Merge Sort :" << endl;
//    merge_sort(array, temp, 0, len-1);

//    cout << "Quick Sort :" << endl;
//    quick_sort(array, 0, len - 1);

//    cout << "Heap Sort :" << endl;
//    heap_sort(len, array);

    cout << "Radix Sort :" << endl;
    radix_sort(array, len);

    print_array(array, len);

    return 0;
}
