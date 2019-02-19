/*************************************************************************
	> File Name: day6test6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 19时36分21秒
 ************************************************************************/

//./a.out < 18_in  输出结果


#include<stdio.h>
#define max 15

int map[max + 5][max + 5] = {0};
int keep[max + 5][max + 5] = {0};

int solve(int i, int j) {
    if (i == max) return 0;
    if (keep[i][j]) return keep[i][j];
    int lnum = solve(i + 1, j), rnum = solve(i + 1, j+ 1);
    keep[i][j] = (lnum > rnum ? lnum : rnum) + map[i][j];
    return keep[i][j];
}

int main() {
    for (int i = 0; i < max; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", map[i] + j);//无取地址符&，故此处是地址
        }
    }
    printf("%d\n", solve(0, 0));
    return 0;
}
