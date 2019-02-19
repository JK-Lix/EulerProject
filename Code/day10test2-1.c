/*************************************************************************
	> File Name: day10test2-1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 18时32分29秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 28123

int prime[max + 5] = {0};
int fnum[max + 5] = {0};
int min_num[max + 5] = {0};
int num[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_num[i] = 1;   //最小素因子个数
            fnum[i] = 1 + i;//因子和

        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                min_num[prime[j] * i] = min_num[i] + 1;
                fnum[prime[j] * i] = fnum[i] / (pow(prime[j], min_num[i] + 1) - 1) * (pow(prime[j], min_num[i] + 2) - 1);    //推导大数因子和
                break;
            } else {
                min_num[prime[j] * i] = 1;
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i]; //当两数互素时
            }
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 0; i <= max; i++) {
        fnum[i] -= i;
        if (fnum[i] > i) min_num[++min_num[0]] = i;
    }
    for (int i = 1; i < min_num[0]; i++) {
        for (int j = 1; j < min_num[0]; j++) {
            if (min_num[i] + min_num[j] > max) break;
                num[min_num[i] + min_num[j]] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i < max; i++) {
        if (num[i]) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
