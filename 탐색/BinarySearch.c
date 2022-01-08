//ÀÌÁø Å½»ö
#include <stdio.h>
typedef int Data;
int BSearch(Data *arr, int first, int last, int target);

int main()
{
    Data arr[] = {1, 3, 5, 6, 7, 8, 9};

    int idx = BSearch(arr, 0, sizeof(arr) / sizeof(Data) - 1, 7);
    if (idx == -1)
        printf("Å½»ö ½ÇÆĞ\n");
    else
        printf("Å¸°Ù ÀÎµ¦½º: %d\n", idx);
    return 0;
}

int BSearch(Data *arr, int first, int last, int target)
{
    if (first > last)
        return -1;
    int mid = (first + last) / 2;
    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return BSearch(arr, first, mid - 1, target);
    else
        return BSearch(arr, mid + 1, last, target);
}