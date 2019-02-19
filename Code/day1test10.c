/*************************************************************************
	> File Name: day1test10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 18时49分03秒
 ************************************************************************/

#include<stdio.h>
int calc(int n) {
    return (2 * n * n * n + 3 * (n + 1) * n - 2 * n)/6
}
int main() {
    int sum1 = 0, sum2 = 5050;
    sum1 = calc(100);
    printf("%d \n", sum2 * sum2 - sum1);
    return 0;
}
