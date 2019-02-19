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
#define MAX 87654321

int64_t prime[MAX + 5] = {0};

void get_prime() { 
    for (int64_t i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int64_t j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int judge(int64_t x) {
    int times;
    int64_t temp = x;
    int arr[9] = {0};
    for (times = 0; temp / 10 != 0; temp /= 10) {
        if (!arr[(temp % 10) - 1]) {
            arr[(temp % 10) - 1] = 1;
            times++;
        } else break;
    }
    if (temp > 10 || arr[temp - 1]) return 0;
    else arr[temp - 1] = 1;
    times++;
    //printf("\n");
    for (int i = 0; i < times; i++) {
       // printf("%d",arr[i]);
        if (!arr[i]) return 0;
    }
    return 1;
}

int main() {
    get_prime();
    for (int i = 1; i <= prime[0]; i++) {
       if (judge(prime[i])) printf("%"PRId64"\n", prime[i]);
    }
    return 0;
}
