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

int64_t sum[5000] = {0};

void one() {
    sum[0] = 1;
    for (int times = 1; times <= 1000; times++) {
        int64_t num[3500] = {0};
        num[0] = num[1] = 1;
        for (int i = 1; i <= times; i++) {
            for (int j = 1; j <= num[0]; j++) {
                num[j] *= times;
            }
            for (int k = 1; k <= num[0]; k++) {
                if (num[k] < 10) continue;
                num[k + 1] += num[k] / 10;
                num[k] %= 10;
                num[0] += (k == num[0]);
            }
        }
        for (int j = 1; j<= 200; j++) {
            if (num[j]) sum[j] += num[j];
        }
        for (int k = 1; k <= sum[0]; k++) {
            if (sum[k] < 10) continue;
            sum[k + 1] += sum[k] / 10;
            sum[k] %= 10;
            sum[0] += (k == sum[0]);
        }
        for (int i = 10; i > 0; i--) {
            printf("%d", sum[i]);
        }
        printf("\n");
    }
    return ;
}

void two() {
    return ;
}

int main() {
    one();
    two();
    return 0;
}
