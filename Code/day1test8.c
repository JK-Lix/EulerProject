/*************************************************************************
	> File Name: day1test8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 18时18分48秒
 ************************************************************************/

#include<stdio.h>
int is_valid(int x) {
    int temp = x, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main() {
    int ans = 10000;
    for (int a = 100; a < 1000; a++) {
        for (int b = ans / a + 1; b < 1000; b++) {
            if (! is_valid(a*b)) continue;
            if (ans >= a * b) continue;
            ans = a * b;
            printf("%d * %d = %d \n", a, b, ans);
        }
    }
    printf("%d", ans);
    return 0;
}
