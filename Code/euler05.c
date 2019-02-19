/*************************************************************************
	> File Name: euler05.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月23日 星期五 15时30分15秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#define MAX_N 20

int main() {
    int64_t ans = 1;
    int a,n=0;
    int b[MAX_N];
    for(int j = 2; j<=20;j++) {
        for ( int k = 2; k <= sqrt(j); j++ ){
            if (j%k==0) break;
            a++;
        }
        if(a >= sqrt(j)){
            b[n] = j;
            n++;
        } 
    }
    for ( int i = 0; i < n; i++ ){
        printf("%d", b[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        ans *=b[i];
    }
    printf("%" PRId64 "\n",ans);
    return 0;
}
