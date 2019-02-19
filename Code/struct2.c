/*************************************************************************
	> File Name: practice3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月10日 星期四 13时52分31秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<string.h>

union IP {
    struct {
        unsigned char arr[4];
    } ip;
    unsigned int num;
};

int main() {
    IP ip;
    int a, b, c, d;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d", ip.num);
    }
    return 0;
}
