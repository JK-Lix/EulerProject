/*************************************************************************
	> File Name: day6test4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 18时10分09秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main() {
    int a[10000] = {0};
    a[0] = 0, a[1] = 1;
    int n = 20, ans = 1,  cnt = 1, cnt0 = 1;
    ans = 1;
    for (int i = 21; i <= 40; i++) {
        for (int j = 1; j <= a[0]; j++){
            a[j] *= i;
        }
        for (int k = 1; k <= a[0]; k++) {
            if(a[k] < 10) continue;
            a[k + 1] += a[k] / 10;
            a[k] %= 10;
            a[0] += (k == a[0]);
        } 
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= a[0]; j++) {
            a[j] /= i;
        }
        for (int k = a[0]; k > 0; k--) {
            if(a[k] > i) continue;
            a[k - 1] += a[k] % i * 10;
            a[k] *= 10;
            a[0] -= (k == 0);
        }
    }
    printf("%d\n", ans);
    return 0;
}
