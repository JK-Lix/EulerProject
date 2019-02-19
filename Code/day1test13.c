/*************************************************************************
	> File Name: day1test13.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 20时24分23秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 2540160
int is_valid(int x){
    int sum = 0, temp = x,a;
    if(x!=1 && x!=2)
    {
    while(x) {
        a=1;
        for (int i=x%10; i>0;i--){
            a=i*a;
        }
        sum+=a;
        x /= 10;
    }}
    return temp==sum;
}

int main(){
    int sum =0;
    for(int i=2;i<=MAX_N;i++){
        if(!is_valid(i)) continue;
        sum+=i;
    }
    printf("%d \n", sum);
    return 0;
}
