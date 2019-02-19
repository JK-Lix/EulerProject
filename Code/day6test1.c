/*************************************************************************
	> File Name: day6test1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 09时16分29秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

int is_pentagonal(int x) {
    int head = 1, tail = 10000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return 1;
        if (pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int temp = INT32_MAX, i, j;

    for (int i = 1; i <= 10000 && pentagonal(i + 1) - pentagonal(i)< temp; i++) {
        for (int j = i; j > 0 && pentagonal(i) - pentagonal(j) < temp; j--) {
            int num_1 = pentagonal(i) - pentagonal(j);
            int num_2 = pentagonal(i) + pentagonal(j);
            if(num_1 < temp && is_pentagonal(num_1) && is_pentagonal(num_2)) temp = num_1; 
        }
    }    

    //这段代码是自己写的
/*
//需要改成64位的int类型，并取值tail = 10000000
    j = 1;
    while (pentagonal(j + 1) - pentagonal(j) < temp) {
        j++;
        i = j - 1;
        do {
            if (is_pentagonal(pentagonal(i) + pentagonal(j))) {
                if (is_pentagonal(pentagonal(j) - pentagonal(i))) {
                    if (pentagonal(j) - pentagonal(i) < temp) {
                    temp = pentagonal(j) - pentagonal(i);
                    }
                }
            }
            i--;
        } while (i && pentagonal(j) - pentagonal(i) < temp);
    }

*/
    printf("%d\n", temp);
    return 0;
}
