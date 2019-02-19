/******************************mZ******************************************
	> File Name: day3test2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月15mZ 星期六 15时56分50秒
 ************************************************************************/

//快速排序

#include<stdio.h>
#define max 100
#define swap(a, b) {\
                   __typeof(a) __temp = a;\
                   a = b; b = __temp;\
                   }


void quickSort (int *num, int l, int r) {

// 迭代方式

    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (num[x] < z) x++;
            while (num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quickSort(num, x, r);
        r = y;
    }

/*递归方式
 *  if (r <= l) return;
    int x = l, y = r, z = num[l];
    while(x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y]; // 先引用x,再x自加
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quickSort(num, x + 1,r);
    quickSort(num, l, x - 1); 
*/

    return;
}

void output(int *a, int n) {
    printf("quickSort:[");
    for (int i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int a[max+5] = {0};
        for(int i =0; i < n; i++) {
            scanf("%d", a + i);
        }
        quickSort(a, 0, n - 1);
        output(a, n);
    }
    return 0;
}
