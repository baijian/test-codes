#include <stdio.h>

void print_nums(int nums[], int len);
void select_sort(int nums[], int len);

int main(void)
{
    int nums[10] = {3,4,1,23,2,8,9,6,19,10};
    select_sort(nums, sizeof(nums)/4);
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

void select_sort(int nums[], int len)
{
    printf("Before Select Sort:\n");
    print_nums(nums, len);
    int i,j;
    int min,tmp;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (i != min) {
            tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;
        }
    }
    printf("After Select Sort:\n");
    print_nums(nums, len);
}
