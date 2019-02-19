/*************************************************************************
	> File Name: day8test2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月28日 星期五 19时21分35秒
 ************************************************************************/

#include<stdio.h>
#define max 1000000

int prime[max + 5] = {0};
int a[max + 5] = {0};

int main() {
    for (int i = 2; i < max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            a[i] = 1;
        }
        for (int j = 2; j <= prime[0]; j++) {
            if (i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            a[prime[j] * i] = a[i] + (i % prime[j] != 0);
            if (i % prime[j] == 0) 
                break;
        }
    }
    int k = 0;
    for (int i = 0; i <= max - 3; i++) {
        if (a[i] ^ 4) continue;
        if (a[i + 1] ^ 4) continue;
        if (a[i + 2] ^ 4) continue;
        if (a[i + 3] ^ 4) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
