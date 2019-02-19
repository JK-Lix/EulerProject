/*************************************************************************
	> File Name: practice2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 14时15分37秒
 ************************************************************************/
#include <stdio.h>
#include <algorithm>
#include <inttypes.h>
#define max 1000000

int prime[max + 5] = {0};
int s_prime[max] = {0};
int64_t sum[max] = {0};


void get_prime() {
    for (int i = 2; i< max; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        sum[i] += sum[i - 1] + prime[i];
        s_prime[prime[i]] = 1;
    }
}

int64_t get_sum(int i, int j) {
    return sum[i] - sum[j];
}

int main() {
    get_prime();
    int temp = 0;
    int ans = 0;
    for (int i = 1; i <= prime[0]; i++) {
        for (int j = 1; j < i - 2; j++) {
            if (get_sum(i, j) > prime[prime[0]])continue;
            if (!s_prime[get_sum(i, j)]) continue;
            if (i - j > temp) {
                temp = i - j;
                ans = get_sum(i, j);
            }
        }
    }
    printf("%"PRId64" --- %d",ans, temp );
    return 0;
}
