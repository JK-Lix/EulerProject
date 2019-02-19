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
#define MAX 1000000

int prime[MAX + 5] = {0};
int dnum[MAX + 5] = {0};
int cnt [MAX + 5] = {0};
int sum = 0;

int r_judge(int x, int y) {
    if (y == 0 ) {
        if (x == 1) return 0;
        if (dnum[x])
            return 1;
        else return 0;
    }
    int a = x / pow(10, y);
    a *= pow(10, y);
    a = x - a;
    if (dnum[a]) {
        printf("%d\n",x);
        return r_judge(a, --y);
    }
    else return 0;
}

int main() {
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;
          //  printf("%d\n", i);
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i < prime[0]; i++) {
        int j = 0, k = 1, temp = 0;
        temp = prime[i];
        temp /= 10;
        for (j = 1; temp / 10 != 0; temp /= 10) {
            k++;
            if (!dnum[temp]) {
                j = 0;
                break;
            }
        }
        if (temp == 1 || !dnum[temp]) j = 0; 
        if (j && r_judge(prime[i], k)) sum += prime[i];
    }
    printf("总和为：%d\n", sum);
    return 0;
}
