//�� ��Ʈ
//������: �ְ�Big(nlogn) �־�Big(n^2)
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
void Swap(Data *arr, int idx1, int idx2);
int Partition(Data *arr, int left, int right);
void QuickSort(Data *arr, int left, int right);

int main()
{
    // Data arr[7] = {3, 2, 4, 1, 7, 6, 5};
    Data arr[3] = {3, 3, 3};

    int len = sizeof(arr) / sizeof(Data);
    QuickSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
void Swap(Data *arr, int idx1, int idx2)
{
    Data tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}
int Partition(Data *arr, int left, int right)
{
    int pivot = arr[left]; //�ǹ��� ���� ���ʿ� ��ġ
    int low = left + 1;
    int high = right;
    while (low <= high) //���� ���� ���� ������ �ݺ�
    {
        //�ǹ����� ū ���� ã�� ����
        while (pivot >= arr[low] && low <= right)
            low++;
        while (pivot <= arr[high] && high >= (left + 1))
            high--;

        if (low <= high)
            Swap(arr, low, high);
    }
    Swap(arr, left, high);
    return high;
}
void QuickSort(Data *arr, int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}