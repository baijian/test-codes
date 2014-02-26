#include <stdio.h>

void print_nums(int nums[], int len);
void bubble_sort(int nums[], int len);

int main(void)
{
    int a[10] = {3,4,1,23,2,8,9,6,19,10};   
    bubble_sort(a, 10);
    return 0;
}

void print_nums(int nums[], int len)
{
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void bubble_sort(int nums[], int len)
{
    printf("Before Bubble Sort:\n");
    print_nums(nums, len);
    int i,j;
    int tmp = 0;
    for (i = 0; i < len; i++) {
        for (j = len - 1; j > i; j--) {
            if (nums[j] < nums[j - 1]) {
                tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
            }
        }
    }
    printf("After Bubble Sort:\n");
    print_nums(nums, len);
}
