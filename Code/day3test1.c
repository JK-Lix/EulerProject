/*************************************************************************
	> File Name: day3test1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年12月15日 星期六 15时53分17秒
 ************************************************************************/

//归并排序


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
#define swap(a, b) {__typeof(a) __temp = a;a = b;b = __temp;}
//      宏定义和宏替换，直接将相应代码段替换成宏定义了里的内容，
//      \用来链接宏定义的不同行。


void mergeSort (int *num, int l, int r) {
    if (r <= l) {
        if (r - l == l && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    mergeSort(num, l, mid);
    mergeSort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
}

void output(int *a, int n) {
    printf("[");
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}


int main() {
    int n;
    while (scanf("%d ", &n) != EOF) { 
        //    循环输入串
        int a[100] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        mergeSort(a, 0, n - 1);
        output(a, n);
    }
    return 0;
}
