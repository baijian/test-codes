#include <stdio.h>

int get_score(float naomi[], float ken[], int len);
float * bubble_sort(float nums[], int len);

int main(void)
{
    FILE *f1;
    f1 = fopen("D-large.in", "r");
    int t;
    fscanf(f1, "%d", &t);
    int len = 0;
    int left_score = 0;
    int right_score = 0;
    for (int i = 0; i < t; i++) {
        fscanf(f1, "%d", &len);
        float naomi_init[len];
        float ken_init[len];
        for (int j = 0; j < len; j++) {
            fscanf(f1, "%f", &naomi_init[j]);
        }
        for (int k = 0; k < len; k++) {
            fscanf(f1, "%f", &ken_init[k]);
        }
        float * naomi = bubble_sort(naomi_init, len);
        float * ken   = bubble_sort(ken_init, len);
        left_score = get_score(naomi, ken, len);
        right_score = get_score(ken, naomi, len);
        printf("Case #%d: %d %d\n", i + 1, left_score, len - right_score);
    }
    fclose(f1);
}

int get_score(float naomi[], float ken[], int len)
{
    int score = 0;
    int begin = len - 1;
    for (int i = len - 1; i >= 0; i--) {
        for (int j = begin; j >= 0; j--) {
            if (naomi[i] > ken[j]) {
                score++;
                begin--;
                break;
            } else {
                begin--;
            }
        }
    }
    return score;
}

float * bubble_sort(float nums[], int len)
{
    int i,j;
    float tmp = 0;
    int exchange = 0;
    int second = 0;
    int flag = 0;
    for (i = 0; i < len; i++) {
        exchange = 0;
        if (flag > i) {
            second = flag;
        } else {
            second = i;
        }
        for (j = len - 1; j > second; j--) {
            if (nums[j] < nums[j - 1]) {
                exchange = 1;
                flag = j;
                tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
            }
        }
        if (exchange == 0) {
            break;
        }
    }
    return nums;
}
