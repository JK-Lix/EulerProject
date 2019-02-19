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

int judge(int x, int cn) {
    if (cn == 0) return 1;
    if (dnum[x] != 0 && dnum[x] != 1) {
        printf("%d\n",dnum[x]);    
        return judge(dnum[x], --cn);
    }
    else return 0;   
}

void is_prime(int x) {
    int s = x;
    int i, j; 
    for (i = 0; s / 10 != 0; s /= 10) {
        i++;
    }
    int d = x / 10 + (x % 10) * pow(10, i);
    if (dnum[d]) dnum[x] = d;
    cnt[x] = i;
}

int main() {
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        is_prime(prime[i]);
    }
    int sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        sum += judge(prime[i], cnt[prime[i]]);
    }
    printf("%d", sum);
    return 0;
}
