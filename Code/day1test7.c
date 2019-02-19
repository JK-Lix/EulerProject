/*************************************************************************
	> File Name: day1test7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 16时27分03秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h> //C99标准
int main(){
    int64_t num = 600851475143, x = 2, ans;
    while (x * x <= num) {
        if (num % x) {
            x++;
            continue;
        }
    //证明 x 一定是个素数      证明：所有合数的因子都是质数
        ans = x;
        while (num % x == 0) num /= x;
        x += 1;
    }
    if (num - 1) ans = num;//证明这行代码的必要性

    //当

    printf("%" PRId64 "\n", ans);
    
    //宏，在C99标准中的输出宏PR输出I为int，d64，64位
    
    return 0;
}
