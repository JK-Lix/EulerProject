/*************************************************************************
	> File Name: practice2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 14时15分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<inttypes.h>
#include<limits.h>

int count = 1;
int num[10] = {0};
int flag = 0;

int init(int x) {
    int i;
    for (i = 1; x / 10 != 0; i++, x /= 10) {
        if (num[x % 10] == 1) return 0;
        num[x % 10] = 1;
    }
    num[x] = 1;
    return i;
}

void check(int x, int d) {
    if (count == 6) return;
    count++;
    int temp = count * x;
    for (int i = 1; temp / 10 != 0; i++, temp /= 10) {
        if (i > d) return ;
        if (!num[temp % 10]) return;
    }
    if (!num[temp % 10]) return;
    if (count == 6) {
        printf("\n%d %d %d %d %d %d\n", x, 2 * x, 3 * x, 4 * x, 5 * x, 6 * x);
        flag = 1;
        return;
    }
    check(x, d);
}

int main() {
    for (int i = 10000; 6 * i < 1000000; i++) {
        count = 0;
        memset(num, 0, sizeof(num));
        int d = init(i);
        if (!d) continue;
        check(i, d);
    }
    return 0;
}

