/*************************************************************************
	> File Name: day1test4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 15时15分21秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000
int main() {
    int c;
    int a = 1, b = 1;
    while (b < MAX_N) {
        if ((b & 1) == 0) sum += b;
        c = b;
        b = a + b;
        a = c;
    }
    printf("%d", b);
    return 0;
}
