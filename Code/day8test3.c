/*************************************************************************
	> File Name: day8test3.c
	> Author: Your Father X
	> Mail: ihavenoemail@fuck.com
	> Created Time: 2018年12月28日 星期五 20时16分11秒
 ************************************************************************/

//求一个数因子和

#include<stdio.h>
#include<math.h>
#define max 10000

int prime[max + 5] = {0};
int Snum[max + 5] = {0};
int mnum[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            Snum[i] = i + 1;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                Snum[prime[j] * i] = Snum[i] / (pow(prime[j], mnum[i] + 1) - 1) * (pow(prime[j], mnum[i] + 2) - 1);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                Snum[prime[j] * i] = Snum[prime[j]] * Snum[i];
            }
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while (~scanf("%d", &n)) {
        printf("%d -> %d, %d\n", n, Snum[n], mnum[n]);
    }
    return 0;
}
