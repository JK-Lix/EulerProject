/*************************************************************************
	> File Name: euler36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月21日 星期三 17时35分01秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 1000000
int is_binary(int64_t x) {
    int a[20];
    int k=0,i;
    do{
        if(x==1) {
            a[k]=1;
            break;
        }
        a[k] = x % 2;
        x /= 2;
        k++;
    }while(x);
    for (i=0;i <= k; i++){
        if (a[i] != a[k - i]) break;
    }
    return i == k + 1;
}

int is_decimal(int64_t x) {
    int64_t temp = x, num = 0;
    while(x){
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main() {
    int64_t ans=0;
    for(int i = 1; i < MAX_N; i++){
        if (! is_binary(i)) continue;
        if (! is_decimal(i)) continue;
        printf("%d\n", i);
        ans += i;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
