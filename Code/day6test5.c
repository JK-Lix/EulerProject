/*************************************************************************
	> File Name: day6test5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 18时33分21秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int ans[3500] = {0};
    ans[0] = ans[1] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= i;
        }
        for(int k = 1; k <= ans[0]; k++){
            if(ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
        printf("%d", ans[i]);
    }
    printf("\n%d", sum);
    return 0;
}
