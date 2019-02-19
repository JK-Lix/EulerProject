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
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int d = 1, sum = 1, ans = 1;
int temp[8] = {0};

int choose(int a) {
    return a *= 10;
}

void judge(int z) {
    int sign = 1;
    int a = d;
    for (temp[0] = 0; z / 10 != 0; z /= 10) {
        temp[++temp[0]] = z % 10;
    }
    temp[++temp[0]] = z; 
    if (ans < a && ans + temp[0] > a) {
        for (int i = 1; i <= temp[0]; i++) {
            if (ans + i == a) {
                sign = 0;
                printf("1-位数%d d%d = %d\n", temp[0] + 1, ans + i, temp[i]);
                d= choose(d);
                sum *= temp[i];
                break;
            }
        }
    } else if (ans == a) {
        sign = 0;
        printf("2-位数%d d%d = %d\n", temp[0] + 1, ans, temp[temp[0]]); 
        d = choose(d);
        sum *= temp[temp[0]];
    }
    if (!sign) printf("%d", ans);
    ans += temp[0];
    if (!sign){
        printf("---%d\n",ans);
        for (int x = temp[0]; x > 0; x--) {
            printf("%d", temp[x]);
        }
        printf("\n");
    }
    return ;
}

int main() { 
    int i = 0, a = 0;
    for (i = 1; ans <= 1000000; i++) {
        judge(i);
    }
    judge(i);
    printf("\nanswer is %d", sum);
    return 0;
}
