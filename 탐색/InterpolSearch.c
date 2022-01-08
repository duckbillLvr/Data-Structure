//º¸°£ Å½»ö
#include <stdio.h>
typedef int Data;
int ISearch(Data *arr, int first, int last, int target);

int main()
{
    Data arr[] = {1, 3, 5, 6, 7, 8, 9};

    int idx = ISearch(arr, 0, sizeof(arr) / sizeof(Data) - 1, 9);
    if (idx == -1)
        printf("Å½»ö ½ÇÆÐ\n");
    else
        printf("Å¸°Ù ÀÎµ¦½º: %d\n", idx);
    return 0;
}

int ISearch(Data *arr, int first, int last, int target)
{
    if (arr[first] > target || arr[last] < target)
        return -1;

    int interpol = ((double)(target - arr[first]) / (arr[last] - arr[first])) * (last - first) + first;
    if (arr[interpol] == target)
        return interpol;
    else if (target < arr[interpol])
        return ISearch(arr, first, interpol - 1, target);
    else
        return ISearch(arr, interpol + 1, last, target);
}