#include <stdio.h>

int main(void)
{
    FILE *f1;
    f1 = fopen("A-small-attempt0.in", "r");
    int t;
    fscanf(f1, "%d", &t);
    
    int line_num;
    int line_num2;
    int row[4][4];
    int row2[4][4];
    int mutex;
    int right;
    int rightnow;
    int j,k;
    for (int i = 0; i < t; i++) {
        mutex = 0;
        right = 0;
        rightnow = 0;
        fscanf(f1, "%d", &line_num);
        fscanf(f1, "%d", &row[0][0]);
        fscanf(f1, "%d", &row[0][1]);
        fscanf(f1, "%d", &row[0][2]);
        fscanf(f1, "%d", &row[0][3]);
        fscanf(f1, "%d", &row[1][0]);
        fscanf(f1, "%d", &row[1][1]);
        fscanf(f1, "%d", &row[1][2]);
        fscanf(f1, "%d", &row[1][3]);
        fscanf(f1, "%d", &row[2][0]);
        fscanf(f1, "%d", &row[2][1]);
        fscanf(f1, "%d", &row[2][2]);
        fscanf(f1, "%d", &row[2][3]);
        fscanf(f1, "%d", &row[3][0]);
        fscanf(f1, "%d", &row[3][1]);
        fscanf(f1, "%d", &row[3][2]);
        fscanf(f1, "%d", &row[3][3]);
        fscanf(f1, "%d", &line_num2);
        fscanf(f1, "%d", &row2[0][0]);
        fscanf(f1, "%d", &row2[0][1]);
        fscanf(f1, "%d", &row2[0][2]);
        fscanf(f1, "%d", &row2[0][3]);
        fscanf(f1, "%d", &row2[1][0]);
        fscanf(f1, "%d", &row2[1][1]);
        fscanf(f1, "%d", &row2[1][2]);
        fscanf(f1, "%d", &row2[1][3]);
        fscanf(f1, "%d", &row2[2][0]);
        fscanf(f1, "%d", &row2[2][1]);
        fscanf(f1, "%d", &row2[2][2]);
        fscanf(f1, "%d", &row2[2][3]);
        fscanf(f1, "%d", &row2[3][0]);
        fscanf(f1, "%d", &row2[3][1]);
        fscanf(f1, "%d", &row2[3][2]);
        fscanf(f1, "%d", &row2[3][3]);
        for (j = 0; j < 4; j++) {
            right = row[line_num-1][j];
            for (k = 0; k < 4; k++) {
                if (right == row2[line_num2-1][k]) {
                    mutex = mutex + 1;
                    rightnow = right;
                }
            }
        }
        if (mutex == 0) {
            printf("Case #%d: Volunteer cheated!\n", i+1);//no same
        } else if (mutex == 1)  {
            printf("Case #%d: %d\n", i+1, rightnow);//one same
        } else if (mutex > 1){
            printf("Case #%d: Bad magician!\n", i+1);//more than one same!
        }
    }
    fclose(f1);
}
