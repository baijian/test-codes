#include <stdio.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);
void print_nums(int nums[], int len);

int main()
{
    int a[] = {7, 12, -2, 0, 3, 30, 20, 19};
    printf("Before quick sort:\n");
    print_nums(a, sizeof(a)/4);
    quick_sort(a, 0, sizeof(a)/4 - 1);
    printf("After quick sort:\n");
    print_nums(a, sizeof(a)/4);
    return 0;
}

int partition(int a[], int low, int high)
{
    int pivot, i, j, k;
    pivot = a[low];
    i = low;
    j = high + 1;
    while(1) {
        do ++i; while(a[i] < pivot && i < high);
        do --j; while(a[j] > pivot && j > low);
        if (i >= j) {
            break;
        }
        k = a[i];
        a[i] = a[j];
        a[j] = k;
    }
    if (low != j) {
        k = a[low];
        a[low] = a[j];
        a[j] = k;
    }
    return j;
}

void quick_sort(int a[], int low, int high)
{
    int j;
    if (low < high) {
        j = partition(a, low, high);
        if (j - 1 > low) {
            quick_sort(a, low, j - 1);
        }
        if (high > j + 1) {
            quick_sort(a, j + 1, high);
        }
    }
}

void print_nums(int nums[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
