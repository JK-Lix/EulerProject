/*************************************************************************
	> File Name: day10test2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 14时59分44秒
 ************************************************************************/

#include<stdio.h>
#define max 28123

int is_prime[max + 5] = {0};
int prime[max] = {0};
int ans[max + 5] = {0};
int n[max + 6] = {0};

int main() {
    ans[1] = 0;
    for (int i = 2; i <= max; i++) {
        if (!is_prime[i]) {
            is_prime[i] = i;
            ans[i] = i + 1;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i <= max; j++) {            
            if (i % prime[j] == 0) {
                is_prime[i * prime[j]] = is_prime[i] * prime[j];
                ans[i * prime[j]] = ans[i] * 
                        (is_prime[i] * prime[j] * prime[j] - 1) / 
                        (is_prime[i] * prime[j] - 1);
                break;
            } else {
                is_prime[i * prime[j]] = prime[j];
                ans[i * prime[j]] = ans[prime[j]] * ans[i];
            }
        }
    }
    ans[0] = 0;
    for (int i = 0; i <= max; i++) {
        ans[i] -= i;
        if (ans[i] > i) ans[++ans[0]] = i;
    }
    for (int i = 1; i <= ans[0]; i++) {
        for (int j = i; j <= ans[0]; j++) {
                if (ans[i] + ans[j] > max) break;
                n[ans[i] + ans[j]] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i <= max; i++) {
        if (!n[i]) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
