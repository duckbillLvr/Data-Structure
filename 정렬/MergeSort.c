//합병 정렬
//성능 평가: Big(nlogn)
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
void MergeTwoArea(Data *arr, int left, int mid, int right);
void MergeSort(Data *arr, int left, int right);
int main()
{
    Data arr[12] = {3, 2, 4, 1, 7, 6, 5, 10, 2, 3, 8, 13};

    MergeSort(arr, 0, sizeof(arr) / sizeof(Data) - 1);

    for (int i = 0; i < sizeof(arr) / sizeof(Data); i++)
        printf("%d ", arr[i]);

    return 0;
}
void MergeTwoArea(Data *arr, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int sIdx = left;

    Data *sortArr = (Data *)malloc(sizeof(Data) * (right + 1));
    //****** 정렬 기준 ******
    while (fIdx <= mid && rIdx <= right)
    {
        if (arr[fIdx] <= arr[rIdx])
            sortArr[sIdx++] = arr[fIdx++];
        else
            sortArr[sIdx++] = arr[rIdx++];
    }

    if (fIdx > mid)
    {
        for (int i = rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else
    {
        for (int i = fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for (int i = left; i <= right; i++)
        arr[i] = sortArr[i];
    free(sortArr);
}
void MergeSort(Data *arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    MergeTwoArea(arr, left, mid, right);
}