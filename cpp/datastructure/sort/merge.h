#ifndef MERGE_H
#define MERGE_H

void merge(int array[], int temp[], int startIdx, int midIdx, int endIdx)
{
    int i = startIdx, j = midIdx + 1, k = startIdx;
    while (i != midIdx + 1 && j != endIdx + 1)  // i <= midIdx && j <= endIdx
    {
        if (array[i] > array[j])
            temp[k++] = array[j++];
        else
            temp[k++] = array[i++];
    }
    while (i != midIdx + 1)     // i <= midIdx
        temp[k++] = array[i++];
    while (j != endIdx + 1)     // j <= endIdx
        temp[k++] = array[j++];
    for (i = startIdx; i <= endIdx; ++i)
        array[i] = temp[i];

}

void merge_sort(int array[], int temp[], int startIdx, int endIdx)
{
    int midIdx;
    if (startIdx < endIdx)
    {
        midIdx = (startIdx + endIdx) / 2;
        merge_sort(array, temp, startIdx, midIdx);
        merge_sort(array, temp, midIdx + 1, endIdx);
        merge(array, temp, startIdx, midIdx, endIdx);
    }
}

#endif // MERGE_H
