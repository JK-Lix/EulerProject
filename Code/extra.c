/*************************************************************************
	> File Name: practice.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 10时40分50秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<stdlib.h>
#include<stdarg.h>
#define P(func) {                    \
printf("%s = %d\n", #func, func);     \
}

int is_prime(int x);
int max_int(int n, ...);

int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n",i);
    }
    P(max_int(3, 2, 3, 5));
    P(max_int(4, 1, 2, 3, 6));
    return 0;
}

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = 0;
    while (n--) {
        int temp = va_arg(arg, int);
        ans = temp > ans ? temp : ans;
    }
    va_end(arg);
    return ans;
}
