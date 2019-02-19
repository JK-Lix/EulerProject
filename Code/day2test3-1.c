/*************************************************************************
	> File Name: day2test3-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 11时54分16秒
 ************************************************************************/
#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define max 2000000
int num[max] = {0};//素数数组(小数组区放素数，大数组区1当做标记，合两个数组为一个)
void prime() {
    int index = 0;
    for (int i = 2; i < max; i++) {
        if(!num[i]) num[++num[0]] = i;                    
            //检查标记数组的对应位置，若标记数组为1，则肯定不为质数，则无需考虑
        for (int j = 1; j <= num[0] && num[j] * i < max; ++j){
            num[i * num[j]] = 1;
                                        //线性筛核心，将得出的素数的倍数全部标记
            if (i % num[j] == 0) break;      
                                        //如果这个数可以整除素数数组的某个素数，则该数肯定为合数，则停止标记,停止本层循环，继续外层循环。
            //上面的if语句减少了循环次数，将多出的时间复杂度loglogN 优化。
        }
    }
    return ;
}
int main() {
    prime();
    int64_t ans = 0;
    for (int i = 1; i <= num[0]; i++){
        ans += num[i];
    }
    printf("%d\n",num[0]);
    printf("%" PRId64 "\n", ans);
    return 0; 
}
