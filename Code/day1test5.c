/*************************************************************************
	> File Name: day1test5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 15时25分55秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000

int main() {
    int a = 1, b = 1, ans = 0;
    while (b <= MAX_N) {
        if ((b & 1) == 0) ans += b;
        a = a + b;
        a ^= b;
        b ^= a;
        a ^= b;   //异或运算
    }
    printf("%d\n", ans);
    return 0;
}
