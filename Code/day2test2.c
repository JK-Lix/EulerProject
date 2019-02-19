/*************************************************************************
	> File Name: day2test2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时05分11秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int prime(int x) {
    for (int i = 2; i <= sqrt(x); i++){
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n = 0, num=1;
    do {
        num += 1;
        while (!prime(num)) num++;
        n += 1;
    } while (n < 10001);
    printf("%d", num);
    return 0;
}
