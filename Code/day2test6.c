/*************************************************************************
	> File Name: day2test6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 20时07分42秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 1000000

#define keep_range 1000000  //数组越大运行时间越长。操作系统寻址，及命中率影响运行时间

int keep[keep_range + 5] = {0};

int get_length(int64_t x) {
    if (x == 1) return 1;
    if (x <= keep_range && keep[x]) return keep[x];
    int temp = 0;
    if (x & 1) temp = get_length(3 * x + 1) + 1;
    else temp = get_length(x >> 1) + 1;
    if (x <= keep_range) keep[x] = temp;
    return temp;
}

int main() {
    int64_t ans, ans_len = 1;
    for (int i = 1; i < max; i++) {
        int temp_len = get_length(i);
        if (temp_len > ans_len) {
            ans = i;
            ans_len = temp_len;
        }
    }
    printf("%d(%d)\n", ans, ans_len);
    return 0;
}

