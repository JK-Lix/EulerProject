/*************************************************************************
	> File Name: day1test6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 15时51分10秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000
int main() {
    int fib[2]={1, 1}, n = 2, ans = 0;
    while(fib[(n-1) & 1] <= MAX_N) {
        if ((fib[(n - 1) & 1] & 1) ==0)  ans += fib[(n - 1) & 1];
        fib[n & 1] += fib[(n - 1) & 1];
        n += 1;
    }
    printf("%d\n", ans);
    return 0;
}
