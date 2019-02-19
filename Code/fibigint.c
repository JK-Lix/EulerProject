/*************************************************************************
	> File Name: practice.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 10时40分50秒
 ************************************************************************/
    
#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))


int main() {
    int ans = 0;
    int f[3][1005] = {0};
    f[0][0] = 1;
    f[0][1] = 0;
    f[1][0] = f[1][1] = 1;
    f[2][0] = f[2][1] = 1;
    for (int i = 3; f[i % 3][0] < 1000; i++) {
        int size = 0;
        if (f[(i + 1) % 3][0] > f[(i + 2) % 3][0]) size = f[(i + 1) % 3][0];
        else size = f[(i + 2) % 3][0];
        for (int j = 1; j <= size; j++) {
            f[i % 3][j] = f[(i + 1) % 3][j] + f[(i + 2) % 3][j];
        }
        f[i % 3][0] = size;
        for (int k = 1; k <= size; k++) {
            if (f[i % 3][k] < 10) continue;
            f[i % 3][k + 1] += f[i % 3][k] / 10;
            f[i % 3][k] %= 10;
            f[i % 3][0] += (k == size);
        }
        printf("%d   F%d = ", f[i % 3][0], i);
        for (int x = f[(i % 3)][0]; x > 0; x--) {
            printf("%d", f[(i % 3)][x]);
        }
        printf("\n");
    }
    return 0;
}
