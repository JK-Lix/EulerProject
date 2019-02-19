/*************************************************************************
	> File Name: day7test2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月26日 星期三 19时49分40秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max 100000

int dnum[max + 5];

int get_len(int d) {
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));//在每一步对数组dnum清零
    printf("1 / %d = 0.", d);
    while (y && dnum[y] == 0) {
        printf("%d", y * 10 /d);
        dnum[y] = n;
        y = y * 10 % d;
        n++;
    }
    printf("(%d)\n", y ? n - dnum[y]: 0);
    return y ? n - dnum[y] : 0;
}

int main() {
    int max_len = 0, ans = 0;
    for (int d = 2; d < max; d++) {
        int temp_len = get_len(d);
        if (temp_len > max_len) {
            max_len = temp_len;
            ans = d;
        }
    }
    printf("Anwser is %d -> %d\n", ans, max_len);
    return 0;
}
