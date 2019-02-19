/*************************************************************************
	> File Name: day6test2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 10时58分51秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define intl int64_t

intl pentagonal(intl n) {
    return n * (3 * n - 1) / 2;
}

intl hexagonal(intl n) {
    return n * (2 * n - 1);
}

intl binary_search(intl (*num)(intl), intl n, intl x) {  // 函数传参，参数是另一个函数
    intl head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num(mid) == x) return 1;
        if (num(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    intl n = 144;
    while (binary_search(pentagonal, 2 * n, hexagonal(n)) == -1) n++;
    printf("%"PRId64"\n", hexagonal(n));
    return 0;
}
