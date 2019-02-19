/*************************************************************************
	> File Name: day7test3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月26日 星期三 20时44分43秒
 ************************************************************************/

#include<stdio.h>
#define max 100000

int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int mnum[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                dnum[prime[j] * i] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
}

int main() {
    
}
