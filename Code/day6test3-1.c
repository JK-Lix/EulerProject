/*************************************************************************
	> File Name: day6test3-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 15时19分26秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

int mnum[max_n + 5]= {0};
int prime[max_n + 5] = {0};
int dnum[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                dnum[prime[j] * i] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
        /*      int temp = i, bj = 0;
                while (temp % prime[j] == 0) temp /= prime[j], bj++;
                dnum[prime[j] * i] = dnum[i] / (bj + 1) * (bj + 2);//标记数组下标对应数字的因子个数   */
                break;
            } else {
                mnum[prime[j] * i] = 1;
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
    return;
}

int fac_num(int n) {
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) >> 1];
    } else {
        return dnum[n >> 1] * dnum[n + 1];
    }
}

int main() {
    init();
    int n = 1;
    while (fac_num(n) < 500) n++;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
