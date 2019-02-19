/*************************************************************************
	> File Name: day2test3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 11时20分14秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#define MAX_N 2000000

int num[MAX_N] = {0};

void prime() {
    for (int i = 2; i <= sqrt(MAX_N); i++ ){
        if(num[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            num[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if(num[i]) continue;
        num[++num[0]] = i;
    }
    return ;
}

int main() {
    prime();
    int64_t ans=0;
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    printf("%" PRId64 "\n", ans);
}

