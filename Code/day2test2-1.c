/*************************************************************************
	> File Name: day2test2-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时14分44秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 2000002

int num[MAX_N]={0};

void prime() {
    for(int i = 2; i <= sqrt(MAX_N); i++) {
        if (num[i]) continue;
            for (int j = i * i; j <= MAX_N; j += i){
                num[j] = 1;
            }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (num[i]) continue;
        num[++num[0]] = i; //num[0]用作计数，然后将数组数据非1的值用计数num[0]覆盖
    }
    return ;
}

int main() {
    prime();
    printf("%d\n", num[10001]);
    return 0;
}
